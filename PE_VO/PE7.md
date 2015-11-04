
Speicher:
  1. Codebereich
  2. statische Daten
  3. Stack <----- grösse begrenzt (stack overflow)
    1. Activation Record main()
    2. Activation Record 2...
    3. Activation Record 3...
  4. Heap

Stack: Activation Record: <-- verwaltet vom System
  1. eingehende Parameter
  2. Rückgabewert
  3. temporärer Speicherbereich
  4. gesicherte Statusinfo
  5. ausgehende Parameter

Heap: <-- verwaltet vom Programmierer
  - `char *p = (char *)malloc(sizeof(char) * 1000);`
  - `free(p)`
 
