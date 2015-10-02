Wiederholung Datentypen
`char short int long`
`float double`

Komplexe Datentypen
`array`
`struct` ['hash']
(`union`) <- Mehrere Möglichkeiten, einen Speicherbereich anzusprechen
(`bitfield`) <- Max. Bits, hardwarenahe

pointer
`void`

## Array

`int numbers[4];`
  (i) indices: `0 1 2 3`
  (i) letztes Element: `numbers[3];`
  (i) letztes Element: `char i = 2; numbers[i+1];`
`int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}` (! Array `{}`)
`int 2d[3] = { {1, 2, 3}, {3, 2, 1} }`
`int numbers[4] = {}` => `0 0 0 0`
`int numbers[4]` => `random random random random`
`char chessboard[8][8];`

`int wuerfel[1000][1000][1000]` => 4GB


### Strings

    char letter
    letter = 'A';
    printf("%c %i\n", letter, letter); // => A 65

    Nullzeichen: '\0'
    zB `char hello[10] = {'H', 'e', 'l', 'l', 'o', '\0'}`
    int i;
    for (i = 0, hello[i] != 0, i++) {
      printf("%c", letter);
    }
    // => Hello

    (i) Array muss immer um 1 größer sein, als die Anzahl der sinnvollen Zeichen, die abgespeichert werden sollen (wegen null \0)


## Struct

    struct person {
      int age;
      int height;
      char last_name[20];
    }; // (!) Einziger Fall in C, wo nach `}` ein `;` folgen muss

    struct person fred;

    x = fred.age;

    (i) `typedef`
      struct xdate { int yyy, mm, dd; }
      typedef struct xdate date;
      date birthday;
