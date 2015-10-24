#include <stdio.h>

int main() {
    int year;
    int is_leap, input_count;
    
    do {
        printf("Enter a year to check if it is a leap year (or enter 0 to exit):\n");
        input_count = scanf("%i", &year);
        
        if ((year % 4) != 0) {
            is_leap = 0;
        } else if ((year % 100) != 0) {
            is_leap = 1;
        } else if ((year % 400) == 0) {
            is_leap = 1;
        } else {
            is_leap = 0;
        }
        
        if (is_leap) {
            printf("%d IS a leap year.\n\n", year);
        } else {
            printf("%d is NOT a leap year.\n\n", year);
        }
        
        if (year == 0) {
            return 0;
        }
        
    } while (input_count != 0);
    
    return 0;
}
