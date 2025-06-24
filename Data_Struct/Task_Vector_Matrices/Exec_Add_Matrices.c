#include <stdio.h>

int main(void) {
    int matriz_1[3][3], matriz_2[3][3], matriz_soma[3][3];
    int diagonal_principal = 0, diagonal_segundaria = 0,soma_diagonais;


    for (int i = 0; i<3;i++) {
        for (int j = 0; j<3; j++) {
            printf("Insira o elemento %d:%d da matriz 1: ", i,j);
            scanf("%d", &matriz_1[i][j]);

            printf("Insira o elemento %d:%d da matriz 2: ", i,j);
            scanf("%d", &matriz_2[i][j]);

            printf("\n");

            matriz_soma[i][j] = matriz_1[i][j] + matriz_2[i][j];
            
            if (i == j) {
                diagonal_principal += matriz_1[i][j];
            }

            if (i+j == 2) {
                diagonal_segundaria += matriz_2[i][j];
            }
        }

    }


    soma_diagonais = diagonal_principal + diagonal_segundaria;
    printf("Soma da Matrizes 1 e 2: \n");

    for (int i = 0; i<3;i++) {
        for (int j = 0; j<3; j++) {
            printf("%d, ", matriz_soma[i][j]);
        }
        printf("\n");
    }

    printf("\nA soma da Diagonal Principal da matriz 1 + Diagonal Secundária da matriz 2 é: %d\n",soma_diagonais);
}