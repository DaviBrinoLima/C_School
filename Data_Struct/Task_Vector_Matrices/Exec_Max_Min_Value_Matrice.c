#include <stdio.h>

void main() {
    int matriz[3][3];
    int maior = matriz[0][0], menor = matriz[0][0];


    for (int i = 0; i<3;i++) {
        for (int j = 0; j<3; j++) {
            printf("Insira o elemento %d:%d da matriz: ", i,j);
            scanf("%d", &matriz[i][j]);
            
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }

            else if (matriz[i][j] < menor) {
                menor= matriz[i][j];
            }
        }

    }

    printf("\nO maior desta matriz é: %d\nO menor valor desta matriz é: %d\n",maior,menor);
}