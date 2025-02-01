#include <iostream>

//#include "third_party/math/math.hpp"
//#include "third_party/phys/energy.hpp"

#include <math/math.hpp>
#include <phys/energy.hpp>

#ifndef USE_MY_MATH
#include <cmath>
#endif

int main() {

#ifdef USE_MY_MATH
    std::cout << "mysin(pi) = " << calcSin(3.1415926535) << std::endl;
#else
    std::cout << "sin(pi) = " << std::sin(3.1415926535) << std::endl;
#endif
    std::cout << "E = " << energy(1, 2) << std::endl;
}
