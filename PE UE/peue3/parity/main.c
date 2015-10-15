#include <stdio.h>
#include <stdlib.h>

unsigned int paritaet(unsigned int zahl);
unsigned int paritaet_highest(unsigned int zahl);
void print_binary(unsigned int zahl);

int main() {
    unsigned int zahl = 100;

    printf("Input: %d, Parity %d, Highest: %d\n", zahl, paritaet(zahl), paritaet_highest(zahl));
    print_binary(11);
    printf("\n");
    print_binary(paritaet_highest(zahl));
}


unsigned int paritaet(unsigned int zahl) {
    unsigned int parity = 0, bit, i;
    
    for (i = 0; i < 32; i++) {
        bit = ((zahl >> i) & 1);
        parity += bit;
        printf("Bit %2d: %d\n", i, bit);
    }
    
    return parity % 2;
}

unsigned int paritaet_highest(unsigned int zahl) {
    unsigned int pari = 0;
    pari = paritaet(zahl);
    
    return zahl | (pari << 31);
}

void print_binary(unsigned int zahl) {
    unsigned int i;
    for (i = 0; i < 32; i++) {
        printf("%d ", ((zahl >> i) & 1));
    }
};