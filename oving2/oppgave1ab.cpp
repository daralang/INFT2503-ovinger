#include <iostream>

int main() {
    //Oppgave 1a
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    std::cout << "Oppgave 1a:";
    std::cout << "i innholder " << i << " og har adresse " << &i <<  ".\n";
    std::cout << "j innholder " << j << " og har adresse " << &j <<  ".\n";

    std::cout << "p innholder adressen " << p <<
            " og har selv adresse " << &p <<
            ". Og peker på verdien " << *p << "\n";
    std::cout << "q innholder adressen " << q <<
            " og har selv adresse " << &q <<
            ". Og peker på verdien " << *q << "\n\n";

    //Oppgave 1b
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;

    std::cout << "Oppgave 1b: \n";
    std::cout << "Når i = " << i << " og når j = " << j << '\n';
    std::cout << "Får vi *p = " << *p << " og *q = " << *q << '\n';
    std::cout << *p << " " << *q << '\n';

    //char *line = nullptr;   // eller char *line = 0;
    //strcpy(line, "Dette er en tekst");

    return 0;
}