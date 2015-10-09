#include <stdio.h>


//2. Schreiben Sie ein weiteres Programm, welches Breite, Länge und Tiefe eines Schwimmbeckens einliest und die nötige Menge an Litern Wasser ausgibt. (1 Kubikmeter enthält 1000 Liter Wasser).

int main() {
    int width, height, depth, volume;
    
    printf("Enter pool dimensions (Width x Height x Depth) in meters to calculate how many liters of water you need: \n");
    if (scanf("%i x %i x %i", &width, &height, &depth) == 3) {
        volume = (width * height * depth) * 1000;
        printf("You need %d liters of water to fill the pool.\n", volume);
        return 0;
    } else {
        printf("Please check your input, should be \"Width x Height x Depth\"");
        return 1;
    }
}
