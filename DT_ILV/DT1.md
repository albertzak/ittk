## Gatter - Gates

OR - Disjunction - [>= 1] - S=AvB - 'Wenn die Anzahl der Einer an den Eingängen >= 1 ist, dann 1'
"1 WENN MIND >=1"

AND - Konjunktion - [&] - S=A&B
"1 WENN ALLE 1"

XOR - Antivalenz - [=1] - S=A(+)B 'Wenn die Anzahl der Einer an den Eingängen genau = 1 ist, dann 1'

NOT - Negation - [o] - S=Ā


NAND - And > Not - [& o]

NOR - Or > Not - [>=1 o]


Schaltnetz Kombination mit System (zB.)
C 00001111
B 00110011
A 01010101
----------

## Augustus De Morgan

NAND <3 OR
  B&A   BvB
A 0011  0011
B 0101  0101
Q 1110  0111

Eingänge (und Ausgänge sowieso) invertiert -> NAND wird zu OR

  NOR <3 AND
A 0011  0011
B 0101  0101
Q 1000  0001

A&B = !(!A v !B)

"Man kann statt jedem AND ein OR verwenden, wenn man Ein/Ausgänge negiert"
zB alles mit NORs bauen, oder nur mit NANDs (wird auch so in der Produktion von Chips gemacht)


NAND
A 0011
B 0101
Q 1110

(A+B verbunden -> E) wird ein NOT

NAND -> NAND = AND




Schaltungsanalyse -> Wahrheitstabelle
Wahrheitstabelle -> Schaltunssynthese

"Vollkonjunktion" = Wenn alle Eingänge des Gesamtsystems in ein AND gehen

"disjunktiv" = "wenn man 'von hinten' in die schaltung schaut, sieht man eine disjunktion"
Man kann jede Schaltung mit einer disjunktiven Normalform synthetisieren
  Disjunktive Normalform = DNF
    - AND \
    - AND - OR - 
    - AND /

Vereinfacht: Minimierte DNF
