#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Opprett en vektor av double. Legg inn 5 tall.
 * Skal ikke leses inn.
 * Bruk front() og back() - returnerer hver et element og har ingen arg.
 * Bruk emplace() - setter inn et tall etter det første elementet.
 * Skriv ut resultatet av front() etterpå.
 *
 * STL - alogritme find() - 3 arg (start, slutt og søkeverdi)
 * Lag et if-uttrykk som sjekker om resultatet av find() er vellykket eller ikke
 * . skriv ut den funne erdien.
 */
int main() {
    vector<double> numbers= {1,20,32,43,5};
    double number;
    double search;

    // Første tall, siste tall
    cout << "First number: " << numbers.front() << "\n";
    cout << "Last number: " << numbers.back() << "\n";

    cout << "Enter a number to be added: " << "\n";
    cin >> number;

    // Skriver inn tall etter det første elementet
    numbers.emplace(numbers.begin() + 1, number);

    cout << "First number after number added: " << numbers.front() << "\n";

    // Legger inn ^ emplace i vektorlista
    for (auto i : numbers)
        cout << i << " ";

    cout << "\nSearch for a number: " << "\n";
    cin >> search;

    auto result = find(numbers.begin(), numbers.end(), search);

    if (result != numbers.end()) {
        cout << "Number found: " << *result << "\n";
    } else {
        cout << "Number not found \n";
    }

    return 0;

}