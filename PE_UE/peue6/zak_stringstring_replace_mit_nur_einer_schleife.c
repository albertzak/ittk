#include <stdio.h>
#include <string.h>

char *stringString(char *haystack, char *needle, char backwards) {
    unsigned long haystackPos, needlePos = 0;

    if (! haystack || ! needle) {
        return NULL;
    }

    if (backwards) {

        for (haystackPos = strlen(haystack) - strlen(needle); haystackPos + 1; haystackPos--) {

            for (needlePos = 0;
                 needle[needlePos] == haystack[haystackPos + needlePos];
                 needlePos++);

            if (needlePos >= strlen(needle)) {
                return &haystack[haystackPos];
            }
        }

    } else {

        for (haystackPos = 0; haystack[haystackPos]; haystackPos++) {

            if (needle[needlePos] && (haystack[haystackPos] == needle[needlePos])) {
                needlePos++;
            } else {
                needlePos = 0;
            }


            if ( ! needle[needlePos]) {
                return &haystack[haystackPos - (needlePos - 1)];
            }
        }

    }

    return NULL;
}


void replace(char *haystack, char *needle, char *new_text) {
    char *result;

    if (!needle || !new_text || (strlen(needle) != strlen(new_text))) {
        return;
    }

    result = stringString(haystack, needle, 0);
    if (result) {
        strncpy(result, new_text, strlen(new_text));
    }
}

int main() {
    char *haystack = "Hellou, Wourld!";
    char *needle = "ou";
    char *result;


    // Forwards search
    result = stringString(haystack, needle, 0);

    if (result) {
        printf("Forward: Found needle at position %ld\n",  result - haystack);
    } else {
        printf("Could not find needle\n");
    }


    // Backwards search
    result = stringString(haystack, needle, 1);
    
    if (result) {
        printf("Backwards: Found needle at position %ld\n",  result - haystack);
    } else {
        printf("Could not find needle\n");
    }

    // Replace
    char string[] = "C ist einfach\n";

    printf("Original: %s", string);
    replace(string, "einfach", "komplex");
    printf("Replaced: %s", string);

    return 0;
}
