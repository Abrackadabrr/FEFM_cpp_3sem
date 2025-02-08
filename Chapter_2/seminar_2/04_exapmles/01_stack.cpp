#include <iostream>

using namespace std;

// Шаблонный класс стека, для которого можно задавать тип хранимых элементов
template<typename T>
class Stack
{
    private:
        // Максимальный размер стека
        size_t capacity = 0;
        // Текущий размер стека
        size_t size = 0;
        // Содержимое стека
        T* ptr = nullptr;
    public:
        // Конструктор
        Stack(size_t capacity)
        {
            this->capacity = capacity;
            this->ptr = new T[capacity];
        }

        // Деструктор
        ~Stack()
        {
            delete[] ptr;
        }

        // Возвращает true, если стек пуст
        bool isEmpty() const
        {
            return size == 0;
        }

        // Возвращает true, если стек полностью заполнен
        bool isFull() const
        {
            return size == capacity;
        }

        // Добавляет элемент в стек
        void push(const T& elem)
        {
            ptr[size++] = elem;
        }

        // Извлекает элемент из стека
        T pop()
        {
            return ptr[--size];
        }

        // Функция, которая возвращает сумму элементов
        // Для Т теперь должен быть определен оператор +
        T sum()
        {
            T res = ptr[0];
            for (size_t i = 0; i < size; i++)
                res += ptr[i];
            return res;
        }

        // Функция для вывода содержимого стека.
        void dump(ostream& os) {
            os << "Stack (" << s.size << "/" << s.capacity << "): [";
            for (size_t i = 0; i < s.size; i++)
            {
                os << s.ptr[i];
                if (i != s.size-1)
                    os << ", ";
            }
            os << "]";
            return os;
        }
};

// Выводит содержимое стека
template<typename T>
ostream& operator<<(ostream& os, const Stack<T>& s)
{
    s.dump(os);   
}

// Структура
struct Struct {
    int i;
    char c;
};

// Выводит содержимое структуры
ostream& operator<<(ostream& os, const Struct& s)
{
    os << "{" << s.i << ", " << s.c << "}";

    return os;
}

// Оператор + для Struct
Struct operator+(const Struct& l, const Struct& r)
{
    Struct res = {l.i + r.i, (char)(l.c + r.c)};
    return res;
}


int main()
{
    // Стек, содержащий int-ы
    Stack<int> intStack(10);
    // Стек, содержащий char-ы
    Stack<char> charStack(11);
    // Стек, содержащий структуры
    Stack<Struct> structStack(12);

    // Заполняем стеки
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
        charStack.push('A'+i);
        structStack.push({i, (char)('A' + i)});
    }

    // Печатаем содержимое стеков и суммы элементов
    cout << intStack << " totals " << intStack.sum() << endl;
    cout << charStack << " totals " << charStack.sum() << endl;
    // Этот вызов сработает только когда реализован оператор + для Struct
    cout << structStack << " totals " << structStack.sum() << endl;

    // Извлекаем данные из стеков
    for (int i = 0; i < 10; i++)
    {
        cout << intStack.pop() << " " << charStack.pop() << endl;
        Struct st = structStack.pop();
        cout << st.i << " " << st.c << endl;
    }
    
    return 0;
}

// Здесь возникает сразу две идеи: 

// 1) Каким-то образом я должен понимать, реализованы ли в типе Т
//    необходимые для работы шаблона операторы. То есть у типа должна быть
//    некоторая "характеристика" (trait)

// 2) Оператор << как-то самостоятельно понял, с каким именно шаблонным
//    параметром нужно сделать инстанцирование специализации. Получается,
//    что компилятор самостоятельно умеет 
//    "выводить типы для шаблонных параметров"  

// Это два далеко идущих замечания, которые позволят в дальнейшем придумать
// auto decltype и метапрограммирование