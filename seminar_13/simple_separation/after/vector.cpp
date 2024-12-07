struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    subvector() : mas(nullptr), top(0), capacity(0) {
    }

    subvector(const subvector &rhs) {
        top = rhs.top;
        capacity = rhs.capacity;
        mas = new int[capacity];
        for (unsigned int i = 0; i < top; ++i) {
            mas[i] = rhs.mas[i];
        }
    }

    subvector& operator=(const subvector &rhs) {
        if (this != &rhs) {
            delete[] mas;
            top = rhs.top;
            capacity = rhs.capacity;
            mas = new int[capacity];
            for (unsigned int i = 0; i < top; ++i) {
                mas[i] = rhs.mas[i];
            }
        }
        return *this;
    }

    ~subvector() {
        delete[] mas;
    }

    bool push_back(const int& d) {
        if (top == capacity) {
            unsigned int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int *temp = new int[new_capacity];
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

    int pop_back() {
        if (top == 0) {
            return int{};
        }
        return mas[--top];
    }

    bool resize(unsigned int new_capacity) {
        if (new_capacity < top) {
            top = new_capacity;
        }
        int *temp = new int[new_capacity];
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
            int *temp = new int[top];
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
        }
    }

    void clear() {
        top = 0;
    }
};

