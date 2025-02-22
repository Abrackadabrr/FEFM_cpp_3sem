// Давайте теперь использовать мощь 
// всего того, что мы сейчас узнали

template<typename T>
struct stupid_class {
    T get_value() { return T{}; }
};

template<typename class_with_method_get_value>
/*???*/ get(const class_with_method_get_value& obj) {
    return obj.get_value();
} 

// Что ставим вместо ??? ?

int main() {
    stupid_class<int> int_c;
    stupid_class<double> double_c;

    get(int_c);
    get(double_c);
}


// Так можно писать функцию main, но стоит ли....
