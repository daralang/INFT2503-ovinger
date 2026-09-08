#include <iostream>
int main() {
    int a = 5;
    //int &b; Den må initialiseres. Skriver det slik at den peker på a.
    int &b = a;
    int *c;
    c = &b;
    //*a = *b + *c; a er int og kan ikke derefereres med *. b er ikke en referanse eller en peker og kan ikke defereres.
    a = b + *c;
    //&b = 2; &b er adressen til b og kan ikke få verdien 2.
    b = 2;

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "*c = " << *c << '\n';
    //Grunnen til at alle kommer ut som 2 er fordi b er referanse til a og c peker på a og disse viser til samme verdien i minnet.
    //Det er fordi b = 2 endrer a til 2 ettersom b er referanse til a og fordi c peker deretter på a.

    return 0;
}