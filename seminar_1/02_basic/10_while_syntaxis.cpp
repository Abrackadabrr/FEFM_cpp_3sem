#include <iostream>

int main ()
{
    int up = 301, low = 0, step = 20, fahr = low;
    while (fahr < up) {
        fahr = fahr + step;
        int cels = 5 * (fahr - 32) / 9;
        std::cout << fahr <<" to " << cels << std::endl;
       
    }
    std::cout << "// ----------- First type of while ------------- //" << std::endl;
    
    fahr = low;
    do {
        fahr = fahr + step;
        int cels = 5 * (fahr - 32) / 9;
        std::cout << fahr <<" to " << cels << std::endl;
    } while (fahr < up);
    std::cout << "// ----------- Second type of while ------------ //" << std::endl; 

    return 0;
}

