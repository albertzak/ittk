#include <stdio.h>

int main() {
    int a, b;
    
    printf("Enter two numbers, the smaller value will be displayed:\n");
    if (scanf("%i %i", &a, &b) == 2) {
        if (a < b) {
            printf("The smaller value is: %d\n", a);
            return 0;
        } else if (b < a) {
            printf("The smaller value is: %d\n", b);
            return 0;
        } else if (a == b) {
            printf("The two values are equal: %d\n", a);
            return 0;
        }
    } else {
        printf("Please check your input: Expected two integers.\n");
        return 1;
    }
}
