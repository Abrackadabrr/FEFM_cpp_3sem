// Можно создавать шаблоны классов

// Было
class vector_int {
    int top;
    int capacity;

    // вот тут как раз фиксация типа данных
    int * data;
};

// Стало
template<typename T>
class vector {
    int top;
    int capacity;
    T * data;
};

// vector -- это обобщенный тип данных