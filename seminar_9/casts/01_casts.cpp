int main() {
    int a = 0;
    int *a_ptr = nullptr;
    long b = 0;

    // приведение int к double
    double d = static_cast<double>(a);

    // приведение int к const int
    const int* const_a_prt = const_cast<const int *>(a_ptr);

    // реинтерпретация данных
    a_ptr = reinterpret_cast<int *>(b); 
}

// cosnt_cast и reinterpret_cast ничего не делают с данными в памяти
// значение после static_cast никак не связано со значением до static_cast

// static_cast работает по принципу "сохранение семантического значения"
// static_cast -- это явное преобразование