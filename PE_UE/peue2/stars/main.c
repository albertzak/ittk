#include <stdio.h>

int main() {
    int lines = 7;
    
    int current_line, current_star;
    
    for (current_line = lines; current_line > 0; current_line--) {
        
        for (current_star = 0; current_star < current_line; current_star++) {
            printf("*");
        }
        
        printf("\n");
    }
}
