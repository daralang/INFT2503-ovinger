## Oppgave 1b

Operatoren `-` er venstreassosiativ. Det betyr at uttrykket

```cpp
5 - 3 - fraction1 - 7 - fraction2
```

blir regnet ut fra venstre mot høyre og tolkes slik:

```cpp
((((5 - 3) - fraction1) - 7) - fraction2)
```

Først blir `5 - 3` regnet ut. Her brukes den vanlige, innebygde operatoren `-` for to heltall, og resultatet blir `2`. Deretter utføres `2 - fraction1`. Siden den første operanden er et heltall og den andre er et `Fraction`-objekt, brukes ikke-medlemsfunksjonen:

```cpp
Fraction operator-(int integer, const Fraction &fraction);
```

Denne operatoren kan ikke være en medlemsfunksjon i `Fraction`, fordi den første operanden er et heltall og ikke et `Fraction`-objekt. Resultatet av `2 - fraction1` er et nytt `Fraction`-objekt. Når `7` deretter trekkes fra dette resultatet, brukes medlemsfunksjonen:

```cpp
Fraction Fraction::operator-(int integer) const;
```

Til slutt trekkes `fraction2` fra resultatet. Begge operandene er nå av typen `Fraction`, og derfor brukes medlemsfunksjonen:

```cpp
Fraction Fraction::operator-(const Fraction &other) const;
```

Dersom `fraction1` er `1/2` og `fraction2` er `1/4`, blir utregningen:

```text
5 - 3 - 1/2 - 7 - 1/4
= 2 - 1/2 - 7 - 1/4
= 3/2 - 7 - 1/4
= -11/2 - 1/4
= -23/4
```

Resultatet av hele uttrykket blir derfor `-23/4`.