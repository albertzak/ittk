//
//  main.c
//  degrees
//
//  Created by Albert Zak on 01/10/15.
//
//

#include <stdio.h>

float to_fahrenheit(float celsius) {
    return celsius * 9.0 / 5.0 + 32.;
}

int main() {
    float celsius;
    
    printf("Enter a degree value in Celsius to be converted into Fahreheit: \n");
    scanf("%f", &celsius);
    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, to_fahrenheit(celsius));
    
    return 0;
}