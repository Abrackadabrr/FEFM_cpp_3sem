int main() {
    for (/*инициализация и присавивание*/ ;
         /*условие продолжения цикла*/ ;
         /*орепации над переменными в первой секции: итерация*/)
    {
        /*тело цикла*/
    }
    int a = 0;
    int b = 1;
    for (i = 0; i < N; i++)
    { //среднестатистический цикл for
        a += b + c;
        b *= i + c;
    }
    // если операции в одну строку, то можно скобочки не ставить
    for (int i = 0; i != 0; ++i) 
        a += i;
    return 0;
}
