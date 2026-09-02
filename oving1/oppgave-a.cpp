#include <iostream>

int main() {
    const int length = 5;
    double temperature;

    int under10 = 0;
    int between10And20 = 0;
    int over20 = 0;

    std::cout << "Enter " << length << " temperatures. \n";
    printf("-------------------- \n");

    for (int i = 0; i < length; i++) {
        std::cout << "Temperature nr " << i + 1 << ": ";
        std::cin >> temperature;

        if (temperature < 10) {
            under10++;
        }
        else if (temperature <=20) {
            between10And20++;
        }
        else {
            over20++;
        }
    }
    std::cout << "You entered " << under10 << " temperatures under 10.\n";
    std::cout << "You entered " << between10And20 << " temperatures between 10 and 20.\n";
    std::cout << "You entered " << over20 << " temperatures over 20.\n";
}