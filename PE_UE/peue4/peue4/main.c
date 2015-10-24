#include <stdio.h>

float f(float x) {
    return x*x*x + 3 * x - 4;
}

int main() {
    float x0, x1, epsilon, xneu;
    int i = 0;
    
    printf("Calculate a root of a function by bisection.\n");
    printf("(Root will be within +/- epsilon value)\n\n");
    
    printf("   Enter start x-value of search interval: ");
    scanf("%f", &x0);
    printf("   Enter end x-value of search interval: ");
    scanf("%f", &x1);
    printf("   Enter epsilon value [Ex.: 0.01]: ");
    scanf("%f", &epsilon);
    printf("\n");
    
    if (x0 > x1) {
        float z;
        z = x1;
        x1 = x0;
        x0 = z;
    }
    
    if (f(x0)*f(x1) > 0) {
        printf("There is no root bewteen x=[%.4f; %.4f].", x0, x1);
        return 0;
    }
    
    xneu = x1;
    while (f(xneu-x0) > epsilon || f(x0-xneu) < -epsilon) {
        xneu = (x0 + xneu) / 2;
        if (f(x0) * f(xneu) < 0) {
            printf("[%d] Root is left to [%.4f, %.4f]\n", i, x0, xneu);
        } else if (f(xneu) * f(x1) < 0) {
            printf("[%d] Root is right to [%.4f, %.4f]\n", i, xneu, x1);
        }
        i++;
    }
    
    printf("Found a root: (in %d steps)\n", i);
    printf("    f(%.4f) = %.4f\n", xneu, f(xneu));
    

    
    return 0;
}
