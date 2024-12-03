int main() {
    int a = 0;
    const int *a_ptr = nullptr;
    long b = 0;

    // приведение int к double
    double d = (double)a;

    // приведение int к const int
    int* const_a_prt = (int *)a_ptr;

    // реинтерпретация данных
    a_ptr = (int *)b; 
}

// логически эти касты все разные, однако в С пишутся одинаково
// в С++ эти касты разделились: static_cast, const_cast, reinterpret_cast