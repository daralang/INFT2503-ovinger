#include <fstream>
#include <iostream>

void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    double temperature[length];

    int under10 = 0;
    int between10And20 = 0;
    int over20 = 0;

    read_temperatures(temperature, length);

    for (int i = 0; i < length; i++) {
        if (temperature[i] <10) {
            under10++;
        }
        else if (temperature[i] <=20) {
            between10And20++;
        }
        else {
            over20++;
        }
    }
    std::cout << "Count of temperatures under 10: " << under10 << "\n";
    std::cout << "Count of temperatures between 10 and 20: " << between10And20 << "\n";
    std::cout << "Count of temperatures over 20: " << over20 << "\n";
}
void read_temperatures(double temperatures[], int length) {
    std::ifstream file("temp.txt");

    if (!file) {
        std::cout << "Error opening file\n";
        return;
    }

    for (int i = 0; i < length; i++) {
        file >> temperatures[i];
    }
    file.close();
}


