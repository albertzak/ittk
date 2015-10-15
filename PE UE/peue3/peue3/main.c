#include <stdio.h>

int main() {
    int total = 10;
    int sum = 0;
    int fail = 0;
    int i;
    int current;
    int valid_input = 0;
    float average;
    
    printf("Enter %d grades to calculate the average:\n", total);
    
    for (i = 1; i <= total; i++) {
        do {
            printf("Grade #%d: ", i);
            valid_input = scanf("%i", &current);
            if (valid_input != 1 || current < 1 || 5 < current) {
                printf("Grade should be between 1 and 5!\n");
                valid_input = 0;
            }
        } while (valid_input != 1);
        
        
        sum += current;
        
        if (current == 5) {
            fail++;
        }
    }
    
    average = sum * 1.0 / total;
    
    printf("Grade point average of %d Grades: %.2f (Failed: %d)", total, average, fail);
    
    return 0;
}
