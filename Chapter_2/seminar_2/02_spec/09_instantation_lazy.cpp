template<typename T>
T foo() {return T{};}

template<typename T>
T bar() {return T{};}

int main() {
    return foo<int>();
}

// Функция bar не будет инстанцирована компилятором,
// потому что на "ну просто не нужна совсем"

// Давайте посмотрим на ... ассемблер
