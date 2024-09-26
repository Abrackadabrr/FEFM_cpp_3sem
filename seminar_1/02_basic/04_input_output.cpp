#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int int_variable;
    char char_variable_first, char_variable_second;
    float float_variable;
    cin >> int_variable;
    cout << int_variable << endl;
    cin >> float_variable;
    cout << float_variable << endl;
    cin >> char_variable_first >> char_variable_second;
    cout << char_variable_first << " "
         << char_variable_second << endl;
    return 0;
}
