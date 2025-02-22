int main() {
    int ten = 10;
    auto constant_multiplier = [ten](int a) -> int { return ten * a; };
    // использование
    return constant_multiplier(10);
}

// Здесь нет никакого мусора, давайте
// посмотрим после семантического анализа
