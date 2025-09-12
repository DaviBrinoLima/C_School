#include <stdio.h>


int main() {
    float soma = 0;
    float media = 0;
    

    int n = 0;

    printf("Insira o número desejado: \n");
    scanf("%d", &n);


    float v[n] = {};


    for (int i=0; i<n; i++) {
        printf("Escreva um número real: \n");
        scanf("%f", &v[i]);

        soma = soma + v[i];
    }


    media = soma/n;
    printf("%f\n%f", soma,media);


    return 0;
}