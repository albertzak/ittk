#include <stdio.h>

int main() {
    int lines = 20;
    
    int current_line, current_star, current_padding;
    
    for (current_line = 1; current_line <= lines; current_line++) {
        
        for (current_padding = (lines - current_line); current_padding >= 0; current_padding--) {
            printf(" ");
        }
        
        for (current_star = 1; current_star <= current_line * 2 - 1; current_star++) {
            printf("*");
        }
        
        printf("\n");
    }
}