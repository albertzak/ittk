#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x-4;
}

int fsgn(float x) {
    if (x > 0.0) {
        return 1;
    } else if (x < 0.0) {
        return -1;
    } else {
        return 0;
    }
}

void bisect(float x0, float x1, float epsilon, int counter) {
    counter++;

    if (fabsf(x1-x0) < epsilon) {
        printf("Found a root at %.4f (took %d iterations)\n", x0, counter);
    } else {
        float xneu = (x0 + x1) / 2.0;

        if (fsgn(f(x0)) != fsgn(f(xneu))) {
            bisect(x0, xneu, epsilon, counter);
        } else if (fsgn(f(xneu)) != fsgn(f(x1))) {
            bisect(xneu, x1, epsilon, counter);
        } else if (f(xneu) == 0.0) {
            printf("Found a root at %.4f", xneu);
        } else {
            printf("Couldn't find a root.\n");
        }
    }

}

int main() {
    float x0, x1, epsilon;
    
    printf("Approximate a root of a function by bisection.\n");
    printf("(Root will be within +/- epsilon value)\n\n");
    
    printf("   Enter start x-value of search interval: ");
    scanf("%f", &x0);
    printf("   Enter end x-value of search interval: ");
    scanf("%f", &x1);
    printf("   Enter epsilon value [Ex.: 0.001]: ");
    scanf("%f", &epsilon);
    printf("\n");
    
    // Swap upper and lower bounds if entered incorrectly
    if (x0 > x1) {
        float z;
        z = x1;
        x1 = x0;
        x0 = z;
    }
    
    bisect(x0, x1, epsilon, 0);
    
    return 0;
}
