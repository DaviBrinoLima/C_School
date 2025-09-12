#include <stdio.h>

int main() {
    int matrice[10][10];

    int *pointer;
    pointer = &matrice[0][0];
    
    for (int i = 0; i < 100; i++) {
        *pointer = 0;
        pointer++;
    }

    pointer = &matrice[0][0]; 
    
    for (int i = 1; i <= 100; i++) {
        *pointer = i;
        pointer++;
    }
    
    printf("\nMatriz 10x10 Preenchida de 1 a 100:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%4d", matrice[i][j]);
        }
        printf("\n");
    }
}