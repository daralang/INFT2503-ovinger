## Oppgave 2
`line` er en peker av typen `char*`. En peker lagrer en minneadresse, altså adressen til et område i minnet der en verdi kan ligge. Når vi skriver `char *line = nullptr;` setter vi pekeren til en nullpeker. Det betyr at `line` ikke peker på noe gyldig minneområde.

Funksjonen `strcpy` kopierer en C-streng tegn for tegn til minneområdet som første argument peker på. I dette tilfellet prøver `strcpy` å skrive teksten `"Dette er en tekst"` til adressen som ligger i `line`.

Problemet er at `line` er `nullptr` og det er derfor ikke satt av noe gyldig minneområde som teksten kan lagres i. Programmet forsøker å skrive til en ugyldig adresse. Dette gir undefined behavior og programmet kan for eksempel krasje med en segmentation fault.

"Process finished with exit code 139 (interrupted by signal 11:SIGSEGV)
"

```cpp
char *line = nullptr;   // eller char *line = 0;
strcpy(line, "Dette er en tekst");
```
