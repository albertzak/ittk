#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int max_guesses = 10;
    char random, guess;
    int i;
    
    // Initialize the PRNG
    srand((unsigned int) time(NULL));
    rand();
    
    random = 97 + (char)(26.0*rand()/(RAND_MAX+1.0));
    
    printf("Guess a letter between 'a' and 'z': ");
    
    for (i = 0; i <= max_guesses; i++) {
        scanf(" %c", &guess);
        
        if (guess == random) {
            printf("Yay! You got it (Score: %d)!\n", 10-i);
            break;
        } else if (guess > random) {
            printf("Nope, i'm thinking of a letter before '%c'.\n", guess);
        } else if (guess < random) {
            printf("Nope, i'm thinking of a letter after '%c'.\n", guess);
        }
        
        if (10-i > 0) {
            printf("Try again (%d tries left): ", 10-i);
        } else {
            printf("Sorry, you lost and I won. The secret letter was '%c'", random);
        }
    }
//    
//    float a, b;
//    
//    a = 1.99999999;
//    b = 1.999999991;
//    
//    if (a == b) {
//        printf("Gleich %.10f - %.10f", a, b);
//    } else {
//        printf("Ungleich %.10f - %.10f", a, b);
//    }
//    
//    
    
    
    
    return 0;
}
