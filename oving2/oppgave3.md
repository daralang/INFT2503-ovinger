## Oppgave 3

Feil i koden
1. `text` er en tabell med plass til fem
`char`-verdier. Når en slik tabell brukes som en C-streng, må teksten avsluttes med nulltegnet `'\0'`. Det betyr at det 
normalt bare er plass til fire vanlige tegn i `text`. 
Ved bruk av `cin >> text` kan brukeren skrive inn mer tekst enn tabellen har plass til. Da kan programmet skrive utenfor 
tabellen.

2. `pointer` peker først på det første elementet i `text`. Løkken undersøker verdien som pekeren peker på med `*pointer`.
Hvis tegnet ikke er `e` blir tegnet erstattet med `e` og pekeren flyttes videre til neste
element. Det finnes ingen kontroll på om pekeren har kommet til slutten av tabellen. Hvis teksten ikke inneholder `e` 
vil pekeren da etter hvert passere nulltegnet og bevege seg utenfor `text`. Programmet vil da lese og skrive i minne som 
ikke tilhører tabellen. Dette gir undefined behavior.

3. Vi ser også at programmet endrer selve teksten mens det søker fordi
`*pointer = search_for` overskriver tegnene med `e`. C++ stopper ikke automatisk en peker når den kommer til slutten av en tabell.

```cpp
char text[5];
char *pointer = text;
char search_for = 'e';
cin >> text;
while (*pointer != search_for) {
  *pointer = search_for;
  pointer++;
}