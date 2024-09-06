#include <iostream>
using namespace std;
int main () {
    char c;
    cin >> c; // оператор ввода
    switch (c) { // можно рассмотреть различные варианты значения переменной
    case 48:
        cout <<"zero\n";
        break; // если не ставить break, исполнение продолжится
    case '1':
        cout << "one" <<endl;
    case 50:
        cout << "a lot" <<endl;
        break;
    default:
        cout << "whatever" <<endl;
    }
    return 0;
}
