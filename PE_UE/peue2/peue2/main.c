#include <stdio.h>

int main() {
    float a, b, c, mean;
    
    printf("Enter three numbers (integers or decimals) to calculate the mean:\n");
    scanf("%f %f %f", &a, &b, &c);
    
    mean = (a + b + c) / 3.0;
    
    printf("The mean is: %.2f\n", mean);
    
    return 0;
}
