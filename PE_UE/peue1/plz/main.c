//
//  main.c
//  plz
//
//  Created by Albert Zak on 01/10/15.
//
//

#include <stdio.h>
#include <string.h>

int main() {
    int plz;
    
    printf("Enter a PLZ code\n");
    scanf("%d", &plz);

    if (plz > 9999) {
        printf("Error: PLZ %i is invalid (too long, should be 4 digits)", plz);
        return 1;
    } else if (plz < 1000) {
        printf("Error: PLZ %i is invalid (too short, should be 4 digits)", plz);
        return 1;
    } else {
        printf("OK: PLZ %i is valid", plz);
    }
    
}