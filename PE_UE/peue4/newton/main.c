#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x-4;
}

float deriv(float x) {
    float delta = 0.001;
    return (f(x+delta) - f(x)) / ((x+delta) - x);
}

void newton(float x, float epsilon, int counter) {
    counter++;

    if (fabs(f(x)) < epsilon) {
        printf("Found a root at %.4f (took %d iterations)\n", x, counter);
    } else if (counter > 500) {
        printf("Couldn't find a root (iteration count exceeded)");
    } else {
        float xneu = x - ( f(x) / deriv(x) );
        newton(xneu, epsilon, counter);
    }

}

int main() {
    float x, epsilon;

    printf("Approximate a root of a function by Newton's method.\n");
    printf("(Root will be within +/- epsilon value)\n\n");

    printf("   Enter start x-value: ");
    scanf("%f", &x);
    printf("   Enter epsilon value [Ex.: 0.001]: ");
    scanf("%f", &epsilon);
    printf("\n");

    newton(x, epsilon, 0);

    return 0;
}
