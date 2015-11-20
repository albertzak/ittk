#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(float *a, float *b);
void memswap(char *mem1, char *mem2, int size);
int firstPosOfChar(char *text, char c);
void capitalize(char *text);



void swap(float *a, float *b) {
    float z;
    z = *a;  // Dereference a and store its value in intermediate var
    *a = *b; // Store the value of b at the location where a is pointing to
    *b = z;  // Store the intermediate value (which was the value of a) at the location of b
}


void memswap(char *mem1, char *mem2, int size) {
    // Intermediate variable z holds each byte
    int i;
    char z;

    // Loop through all bytes of the memory area
    // and swap each byte via the intermediary variable
    for(i = 0; i < size; i++) {
        z = mem1[i];
        mem1[i] = mem2[i];
        mem2[i] = z;
    }
}


int firstPosOfChar(char *text, char c) {
    int i;
    char currentChar;

    i = 0;

    do {
        currentChar = text[i];
        if (currentChar == c)
            return i;
        i++;
    } while(currentChar);
    // Look at each char as long as it's not the null byte
    // else return -1 ('not found')

    return -1;
}


void capitalize(char *text) {
    int i;

    // The current char we're looking at
    char c;

    // A flag that is set to true when we're at a space
    // or any other word boundary. If the following char is a lowercase
    // letter, the char should be capitalized.
    // We should unset this flag after each iteration,
    // except if the next char is another space.
    // Inititialize with 1 because we definitely
    // want to  capitalize the first character.
    char capitalizeNext = 1;

    do {
        c = text[i];

        // set the capitalizeNext flag if we're at a word boundary now
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            capitalizeNext = 1;

        // capitalize only lower case letters that are at the beginning
        // of a word (eg. after a space / capitalizeNext is set)
        } else if (capitalizeNext && c >= 97 && c <= 122) {

            // To capitalize a lower case ascii letter,
            // subtract 32 from the char code
            c = c - 32;
            text[i] = c;

            capitalizeNext = 0;
        } else {
            capitalizeNext = 0;
        }

        i++;
    } while(c);
}


int main () {
    float zahl1, zahl2;
    int i;
    int daten1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int daten2[10] = { 101, 234, 398, 434, 523, 616, 748, 856, 901, 133 };
    char text[100];


    zahl1 = 10.56f;
    zahl2 = 1.12E3f;

    printf("\n======================================\n");
    printf("before swap: zahl1 = %.2f, zahl2 = %.2f\n", zahl1, zahl2);
    swap(&zahl1, &zahl2);
    printf("after swap: zahl1 = %.2f, zahl2 = %.2f\n\n", zahl1, zahl2);


    printf("\n======================================\n");
    printf("before memswap:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t\t%d\n", daten1[i], daten2[i]);
    }
    memswap((char *)daten1, (char *)daten2, sizeof(daten1));
    printf("after memswap:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t\t%d\n", daten1[i], daten2[i]);
    }


    printf("\n======================================\n");
    strcpy(text, "Dies ist ein Beispieltext, wo jedes Wort mit einem Großbuchstaben beginnen soll.");
    printf("text to examine: %s\n", text);

    i = firstPosOfChar(text, 'j');
    printf("first position of charachter '%c': %d (should be 30)\n", 'j', i);
    i = firstPosOfChar(text, 'G');
    printf("first position of charachter '%c': %d (should be 51)\n", 'G', i);


    printf("\n======================================\n");
    strcpy(text, "Dies ist ein Beispieltext, wo jedes Wort mit einem Großbuchstaben beginnen soll.");
    printf("before capitalize: %s\n", text);
    capitalize(text);
    printf("after capitalize: %s\n", text);
    
    return 0;
}
