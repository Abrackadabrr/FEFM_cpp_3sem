#include <iostream>
int main() {
    int a[3] = {0, 1, 2};
    // посмотрим на указатель 
    std::cout << a << std::endl;
    std::cout << std::dec << (long)(a) << '\n' << std::endl;
    
    std::cout << "Вывод индексов элемента массива в памяти (10 сс)" << std::endl; 
    std::cout << std::dec << (long)(&(a[0])) << std::endl;
    std::cout << std::dec << (long)(&(a[1])) << std::endl;
    std::cout << std::dec << (long)(&(a[2])) << std::endl;
    
    // будет ли вывод на экран одинаковый? нам бы хотелось в это верить...
    // std::cout << *a << ' ' << a[0] << std::endl;

    return 0;   
}