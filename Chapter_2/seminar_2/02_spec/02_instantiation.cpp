

// Инстанцирование -- это процесс порождения специализации

template <typename value_type>
value_type max(value_type lhs, value_type rhs) {
    return lhs < rhs ? rhs : lhs;
}

int main() {
    max<int>(4, 5);
    // здесь произойдет НЕЯВНОЕ инстанцирование функции с телом,
    // указанным в шаблоне
    // Будто бы вы руками написали
    // template<> int max(int, int) {...};
    
    // Шаблон -- это четреж, специализация -- это деталь
    // Постановка шаблонного параметра назвается ... постановкой
    // "substitution"
}
