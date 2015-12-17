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
    int i;
    for(i = 0; i < size; i++) {
        char z = mem1[i];
        mem1[i] = mem2[i];
        mem2[i] = z;
    }
}


int firstPosOfChar(char *text, char c) {
    int i = 0;
    while (text[i]) {
        if (text[i] == c)
            return i;
        else
            i++;
    }
    return -1;
}


void capitalize(char *text) {
    int i = 0;
    while (text[i]) {
        if (text[i] >= 97 && text[i] <= 122)
            if (i == 0 || text[i-1] <= 32)
                text[i] = text[i] - 32;
        i++;
    }
}

int length(char *text) {
    char * current = text;

    while (*current)
        current++;

    return (int)(current - text);
}

char *stringString(char *haystack, char *needle) {
    char *current;
    int foundChars = 0;

    current = haystack;

    while (*current) {

        if (*current == needle[foundChars]) {
            foundChars++;
        } else {
            foundChars = 0;
        }

        if (foundChars == strlen(needle))
            return current - strlen(needle) + 1;

        current++;
    }
    return haystack;
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
    strcpy(text, "dies      ist ein Be ispieltext, \nwo jedes Wort mit einem Großbuchstaben beginnen soll.");
    printf("before capitalize: %s\n", text);
    capitalize(text);
    printf("after capitalize: %s\n", text);


    printf("\n======================================\n");
    strcpy(text, "Dies ist ein 44 zeichen langer Beispieltext.");
    printf("text to examine: %s\n", text);
    printf("length of string (should be 44): %d\n", length(text));

      
    printf("\n======================================\n");
    strcpy(text, "Dies ist ein Test");
    printf("substring 'is' located at: %p, with a value of: %c\n", stringString(text, "Test"), *stringString(text, "Test"));

    return 0;
}
