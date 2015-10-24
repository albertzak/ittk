PE 1

# Coding Style

  Deklaration und Wertzuweisung trennen

    int x;
    x = 3;

# C types
  `char` = 1 byte = 8 bits
    -128 bis 127

      warum?
        01111111 = 127
        10000000 = -128 (Zweierkomplement)

  `short` = 2 bytes = 16 bits
    -32,768 bis +32,768

  `int` = (Prozessorabhängig - passt in ein Register) 23bits = 4 bytes oder 64bits = 8 bytes
    -2 Millliarden bis +2 Milliarden

  `long` = doppeltes int
    -9x10^18 bis +9x10^18

  *Type qualifier* ist zB `unsigned`
    How to use: `unsigned int day;`


  Beispiel; 8-bit Zahl
    00001101
    2^7 ...... 2^0
    (13)10

  (!) Man kann zB char einer int zuordnen (char ist eine Teilmenge von int),
      aber nicht [immer] umgekehrt!
        (es werden nur die niederwertigsten bytes genommen)

      *char < short < int < long*

# Zweierkomplement
    00001101 <- (13)10
    11110010 <- Einerkomplement
  +        1 <- 1 addieren
  = 11110011 <- Zweierkomplement (-13)10

    Zweierkomplement erkennen: Vorderstes bit immer 1
    Vorteil Zweierkomplement: man kann zB 1 addieren und kommt auf -12
      -> rechnen funktioniert

# Hexadezimal

  01100101   <- (101)10, split into groups of 4
  0110 0101
  ==== ====
     6    5  <- 0x65

     zB. lauter 1er in eine variable füllen: `int x; x = 0xFF;`

 (i) Oktalzahl: führende 0
      (octal: deprecated)


# Floats

  `float` (single) = 32bits -> 7 significant digit
    - kleines `f` dranhängen: 1432.32f

  `double` = 64bits -> 15 significant digits
    - kein Suffix

# Gleitkomma
  0.123E12 = 0.123 * 10 ^ 12
    - E == `*10^`

^-- Das waren alle Datentypen, die es gibt
    Strings sind auch nur als Zahlen abgespeichert


# Operatoren
    Unäre: zB Vorzeichen bei -4, oder (sinnlos) +5
    Inkrement/Dekremet: ++a oder a++ (eh klar, effekt soll man nicht verwenden)
    Binäre: + - * / % (modulo)

    (i) Division: Wenn bei (x/y) x und y ganze Zahlen sind, ist das Ergebins auch eine Ganze Zahl
                  Nachkommastellen werden abgeschnitten (statt gerundet)
                  Mind. einer der beiden Operanden müsste eine Gleitkommazahl sein

    Bitoperatoren
      ~ Not       ~110 = 001
      & And       110 & 010 = 010
      | Or        110 | 010 = 110
      ^ Xor       110 ^ 010 = 100
      << >> Shift   00101110 << 2
                      10111000
                      Entspricht Multiplikation

    Logische Operatoren: ! && || != == <= >= < >
      (i) Wahr ist alles, was nicht 0 ist. `a != 0`


# Conditionals
    Umkehrung von < ist >= (!)


    switch (a) {  // a muss eine ganze Zahl sein
      int x;
      case 1:
        statement;
        statement;
        break;
      case 2:
        statement;  // fall-through
      default:
        statemnt;
    }
