Warum Pointer?

Vermeidet kopieren von grossen Strukturen
Mehrere Rückgabewerte: Man gibt einer Funktion Pointer "wohin die Rückgabewerte hin kommen sollen"
Dynamische Speicherreservierung


__*__ hat 3 Bedeutungen:
  - Deklaration: `int *a`
  - Dereferenzierung: `*a = 7` (Speicheradresse bekommt 7 zugewiesen)
  - (Multiplikation: `*a * *a;`)


(i) Pointer subtrahieren macht dann Sinn: 2 Pointer zeigen auf das selbe Array und per Subtraktion kann man die Anzahl der Elemente dazwischen herausfinden (wenn die Pointer vom gleichen Typ sind!)

int *p;
int a[4];
p = a;
a[n] === p[n] === *(p+n) === *(a+n)

geeksquiz.com
