#include <iostream>

static int find_sum(const int *table, int length);

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }
    return sum;
}

int main () {
    const int length = 20;
    int table[length];

    for (int i = 0; i < length; i++) {
        table[i] = i+1;
    }
    std::cout << "Summen av de 10 første: " << find_sum(table, 10) << "\n";
    std::cout << "Summen av de 5 neste: " << find_sum(table + 10, 5) << "\n";
    std::cout << "Summen av de 5 siste tallene: " << find_sum(table + 15, 5) << "\n";

    return 0;
}

