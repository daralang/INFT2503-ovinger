#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    cout << "Bruker Template-utgaven." << endl;
    return a == b;
}

template <>
bool equal(double a, double b) {
    cout << "Bruker spesialutgaven for double." << endl;
    return abs(a - b) < 0.00001;
}

int main() {
    cout << boolalpha << setprecision(17);

    bool result = equal(5, 5);
    cout << "equal(5, 5): " << result << endl;

    result = equal(5, 7);
    cout << "equal(5, 7): " << result << endl;

    result = equal(string("hei"), string("hei"));
    cout << "equal(\"hei\", \"hei\"): " << result << endl;

    double a = 0.1 + 0.2;
    double b = 0.3;
    cout << "\na = 0.1 + 0.2: " << a << endl;
    cout << "b = 0.3: " << b << endl;
    cout << "Vanlig sammenligning (a == b): " << (a == b) << endl;

    result = equal(a, b);
    cout << "equal(a, b): " << result << endl;

    result = equal(b, b + 0.000005);
    cout << "Forskjell mindre enn 0.00001: " << result << endl;

    result = equal(b, b + 0.00002);
    cout << "Forskjell større enn 0.00001: " << result << endl;

    return 0;
}
