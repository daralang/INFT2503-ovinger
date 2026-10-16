#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &fraction) {
    cout << text
         << fraction.numerator
         << " / "
         << fraction.denominator
         << endl;
}

int main() {
    Fraction fraction1(1, 2);
    Fraction fraction2(1, 4);

    Fraction result1 = fraction1 - 5;
    Fraction result2 = 5 - fraction1;

    print("fraction1 = ", fraction1);
    print("fraction1 - 5 = ", result1);
    print("5 - fraction1 = ", result2);

    Fraction result3 = 5 - 3 - fraction1 - 7 - fraction2;
    print("5 - 3 - fraction1 - 7 - fraction2 = ", result3);

    return 0;
}