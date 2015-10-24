//
//  add.c
//  peue1
//
//  Created by Albert Zak on 01/10/15.
//
//

#include <stdio.h>

void add_short() {
    short a, b, result;
    
    printf("Enter two numbers (short: -32,768 to 32,767) to add: \n");
    scanf("%hd", &a); // h: short format modifier
    scanf("%hd", &b);
    
    result = a + b;
    
    printf("The result is: %hd \n", result);
}

void add_long() {
    long a, b, result;
    
    printf("Enter two numbers (long: -2,147,483,648 to 2,147,483,647) to add: \n");
    scanf("%ld", &a); // l: long format modifier
    scanf("%ld", &b);
    
    result = a + b;
    
    printf("The result is: %ld \n", result);
}

void add_float() {
    float a, b, result;
    
    printf("Enter two numbers (float: 6 decimal places) to add: \n");
    scanf("%f", &a); // f: float format modifier
    scanf("%f", &b);
    
    result = a + b;
    
    printf("The result is: %f \n", result);
}

void add_double() {
    double a, b, result;
    
    printf("Enter two numbers (double: 15 decimal places) to add: \n");
    scanf("%lf", &a); // lf: double float
    scanf("%lf", &b);
    
    result = a + b;
    
    printf("The result is: %lf \n", result);
}

void add_char() {
    char a, b, result;
    
    printf("Enter two numbers (char: -128 to 127) to add: \n");
    scanf(" %c", &a); // c: char format
    scanf(" %c", &b);
    
    result = a + b;
    
    printf("The result is: %d \n", result);
}


int main() {
    add_short();
    add_long();
    add_float();
    add_double();
    add_char();

    return 0;
}