## Oppgave 2
### Forutsetninger

`Pair<First, Second>` lagrer to elementer som kan ha forskjellig type.
Operatorene sammenligner eller legger sammen par med de samme to
template-typene, for eksempel to `Pair<double, int>`.

- Konstruktøren forutsetter at elementene kan kopieres.
- `operator+` forutsetter at `First + First` og `Second + Second` er
  definert. Resultatene må kunne brukes som henholdsvis `First` og
  `Second`, siden summen returneres som et nytt par med de samme typene.
- `operator>` forutsetter at `First + Second` er definert, slik at
  elementene i hvert par kan summeres. De to summene må kunne sammenlignes
  med `>`, og sammenligningen må gi et resultat som kan returneres som `bool`.
- De nødvendige operatorene må kunne brukes på konstante elementer,
  siden medlemsoperatorene er `const` og tar det andre paret som en
  `const`-referanse.

For `Pair<double, int>` finnes de nødvendige innebygde operatorene.
Når `double` og `int` summeres, konverteres heltallet til `double`.
Dermed sammenlignes `3.5 + 14 = 17.5` med `2.1 + 7 = 9.1`, og `p1` er
størst. Elementvis summering gir et nytt par med `first = 5.6` og
`second = 21`. De opprinnelige parene endres ikke.

Template-klassen er definert i `pair.hpp`, slik at hele definisjonen er
tilgjengelig når kompilatoren lager en utgave for de valgte typene.
