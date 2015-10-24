#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int max_guesses = 10;
    int random, guess;
    int i;
    
    // Initialize the PRNG
    srand((unsigned int) time(NULL));
    rand();
    
    random = 1+(int)(100.0*rand()/(RAND_MAX+1.0));
    
    printf("Guess a number between 1 and 100: ");
    
    for (i = 0; i <= max_guesses; i++) {
        scanf("%d", &guess);
        
        if (guess == random) {
            printf("Yay! You got it (Score: %d)!\n", 10-i);
            break;
        } else if (guess > random) {
            printf("Nope, i'm thinking of a smaller number.\n");
        } else if (guess < random) {
            printf("Nope, i'm thinking of a bigger number.\n");
        }
        
        if (10-i > 0) {
            printf("Try again (%d tries left): ", 10-i);
        } else {
            printf("Sorry, you lost and I won. The secret number was %d", random);
        }
    }
    
    return 0;
}
