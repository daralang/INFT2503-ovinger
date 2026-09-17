#include <iostream>
#include <string>

int main() {
    // Oppgave a
    std::string word1;
    std::string word2;
    std::string word3;

    std::cout << "Skriv inn tre ord: ";
    std::cin >> word1 >> word2 >> word3;

    // Oppgave b
    std::string sentence = word1 + " " + word2 + " " + word3;
    std::cout << "Setning: " << sentence << '\n';

    // Oppgave c
    std::cout << '\n';
    std::cout << "Lengden på første ord: " << word1.length() << '\n';
    std::cout << "Lengden på andre ord: " << word2.length() << '\n';
    std::cout << "Lengden på tredje ord: " << word3.length() << '\n';
    std::cout << "Setningen har lengde: " << sentence.length() << " (Obs: inkluderer mellomrom)\n";

    // Oppgave d
    std::string sentence2 = sentence;

    // Oppgave e
    if (sentence2.length() > 12) {
        sentence2[10] = 'x';
        sentence2[11] = 'x';
        sentence2[12] = 'x';
    }
    std::cout << '\n';
    std::cout << "Kopi av setning:  " << sentence << '\n';
    std::cout << "X-er i setningen: " << sentence2 << '\n';

    // Oppgave f
    std::string sentence_start;

    if (sentence.length() >= 5) {
        sentence_start = sentence.substr(0, 5);
        std::cout << '\n';
        std::cout << "Setningen: " << sentence << '\n';
        std::cout << "Første ord i setningen: " << sentence_start << '\n';
    }

    std::cout << '\n';

    // Oppgave g
    if (sentence.find("hallo") != std::string::npos) {
        std::cout << "Setningen inneholder \"hallo\".\n";
    } else {
        std::cout << "Setningen inneholder ikke \"hallo\".\n";
    }

    // Oppgave h
    std::cout << '\n';
    std::size_t position = sentence.find("er");

    while (position != std::string::npos) {
        std::cout << "\"er\" finnes på posisjon " << position << '\n';

        position = sentence.find("er", position + 1);
    }

    return 0;
}