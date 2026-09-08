#include <iostream>

int main() {
    double n = 0;
    double *p = &n;
    double &r = n;
    n = 1;
    std::cout << "number = " << n << '\n';
    *p = 2;
    std::cout << "number = " << n << '\n';
    r = 3;
    std::cout << "number = " << n << '\n';
    return 0;
}