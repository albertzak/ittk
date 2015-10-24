//
//  main.c
//  sum
//
//  Created by Albert Zak on 01/10/15.
//
//

#include <stdio.h>

int main() {
    int input;
    int sum;
    
    sum = 0;
    
    do {
        printf("Current sum: %i, enter a number to add: \n", sum);
        
        scanf("%i", &input);
        
        sum += input;
    } while (input > 0);
    
    printf("The total sum is: %i", sum);
    
    return 0;
}