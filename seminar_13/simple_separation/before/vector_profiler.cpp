#include <iostream>
#include <random>
#include <chrono>

#include <iostream>

using std::cout;
using std::endl;

template<typename T>
struct subvector {
    T *mas;
    unsigned int top;
    unsigned int capacity;

public:
    subvector() : mas(nullptr), top(0), capacity(0) {
        cout << "Ctor"<< endl;
    }

    subvector(const subvector &rhs) {
        top = rhs.top;
        capacity = rhs.capacity;
        mas = new T[capacity];
        for (unsigned int i = 0; i < top; ++i) {
            mas[i] = rhs.mas[i];
        }
    }

    subvector& operator=(const subvector &rhs) {
        if (this != &rhs) {
            delete[] mas;
            top = rhs.top;
            capacity = rhs.capacity;
            mas = new T[capacity];
            for (unsigned int i = 0; i < top; ++i) {
                mas[i] = rhs.mas[i];
            }
        }
        return *this;
    }

    ~subvector() {
        delete[] mas;
        cout << "Dtor"<< endl;
    }

    bool push_back(const T& d) {
        if (top == capacity) {
            unsigned int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            T *temp = new T[new_capacity];
            for (unsigned int i = 0; i < top; ++i) {
                temp[i] = mas[i];
            }
            delete[] mas;
            mas = temp;
            capacity = new_capacity;
        }
        mas[top++] = d;
        return true;
    }

    T pop_back() {
        if (top == 0) {
            return T{};
        }
        return mas[--top];
    }

    bool resize(unsigned int new_capacity) {
        if (new_capacity < top) {
            top = new_capacity;
        }
        T *temp = new T[new_capacity];
        for (unsigned int i = 0; i < top; ++i) {
            temp[i] = mas[i];
        }
        delete[] mas;
        mas = temp;
        capacity = new_capacity;
        return true;
    }

    void shrink_to_fit() {
        if (top == 0) {
            delete[] mas;
            mas = nullptr;
            capacity = 0;
        } else {
            T *temp = new T[top];
            for (unsigned int i = 0; i < top; ++i) {
                temp[i] = mas[i];
            }
            delete[] mas;
            mas = temp;
            capacity = top;
        }
    }

    void print (){
        for (int i = 0; i < top; i++ ) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }

    void clear() {
        top = 0;
    }
};


using vector = subvector<int>;
using std::cout;
using std::endl;
double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}
int rand_uns(int min, int max)
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        static std::default_random_engine e(seed);
        std::uniform_int_distribution<int> d(min, max);
        return d(e);
}
int main()
{
    int n = 100000;
    int *test_sequence = new int[n], sum_for_O3 = 0, sum_check = 0,
        *pop_push_sequence_eq = new int[n],
        *pop_push_sequence_push = new int[n],
        *pop_push_sequence_pushpush = new int[n];
    double start = 0, finish = 0, total = 0;
    cout << std::fixed;
    cout.precision(4);
//----------- Initialization
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        test_sequence[i] = rand_uns(0, n - 1);
        pop_push_sequence_eq[i] = rand_uns(0, 1);
        pop_push_sequence_push[i] = rand_uns(0, 5);
        pop_push_sequence_pushpush[i] = rand_uns(0, 10);
    }
    finish = get_time();
    cout << "Test sequence initialization: \t\t" << finish - start << endl;
    vector sv{};
//----------- Test 000 Straight push_back
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        sv.push_back(test_sequence[i]);
        // sv.push_back(test_sequence[i])
    }
    finish = get_time();
    for (int i = 0; i < n; i++)   //!!! This is a hack to bamboozle the O3 optimization.
        sum_for_O3 += sv.mas[i];  // I might as well use it to test push/pop.
    cout << "000 Straight push_back: \t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 001 Straight pop_back
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        sum_check += sv.pop_back();
    }
    finish = get_time();
    if (sum_check != sum_for_O3)
    {
        cout <<endl <<"--- !!! Failed push/pop consistency !!! ---" << endl;
        return 0;
    }
    cout << "001 Straight pop_back: \t\t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 002 Straight resize up
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        sv.resize(i);
    }
    finish = get_time();
    sv.shrink_to_fit();
    if (sv.capacity)
    {
        cout <<endl <<"--- !!! Failed resize/shrink consistency !!! ---" << endl;
        return 0;
    }
    cout << "002 Straight resize up: \t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 003 Random pop/push equal amount
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        if (pop_push_sequence_eq[i])
            sv.push_back(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_back();
    }
    finish = get_time();
    sv = vector{};
    sv.shrink_to_fit();
    if (sv.top)
    {
        cout <<endl <<"--- !!! Falied clear !!! ---" << endl;
        return 0;
    }
    if (sv.capacity)
    {
        cout <<endl <<"--- !!! Falied shrink_to_fit !!! ---" << endl;
        return 0;
    }
    cout << "003 Random pop/push equal amount: \t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 004 Random pop/push more push
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        if (pop_push_sequence_push[i])
            sv.push_back(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_back();
    }
    finish = get_time();
    sv.clear();
    sv.shrink_to_fit();
    cout << "004 Random pop/push more push: \t\t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 005 Random pop/push much more push
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (int i = 0; i < n; i++)
    {
        if (pop_push_sequence_pushpush[i])
            sv.push_back(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_back();
    }
    finish = get_time();
    cout << "005 Random pop/push much more push: \t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- End of tests
    cout << "-----------" << endl <<"Alltests finished, total time: \t" << total << endl;
    delete[] test_sequence;
    delete[] pop_push_sequence_eq;
    delete[] pop_push_sequence_push;
    delete[] pop_push_sequence_pushpush;
    return 0;
}
