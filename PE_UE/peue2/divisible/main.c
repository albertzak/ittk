#include <stdio.h>

int main() {
    int divisible_by = 7;
    int from = 1;
    int to = 1000;
    
    printf("All integers from %d to %d that are divisible by %d:\n\n", from, to, divisible_by);
    
    while (from <= to) {
        if ((from % divisible_by) == 0) {
            printf("%d  ", from);
        }
        from++;
    }
    
    printf("\n");

    return 0;
}
