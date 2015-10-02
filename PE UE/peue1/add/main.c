//
//  add.c
//  peue1
//
//  Created by Albert Zak on 01/10/15.
//
//

#include <stdio.h>

int main() {
    int a;
    int b;
    int result;
    
    printf("Enter two numbers to add: \n");
    scanf("%d %d", &a, &b);
    
    result = a + b;
    
    printf("The result is: %d", result);
    
    return 0;
}