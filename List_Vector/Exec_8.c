#include <stdio.h>


int main() {
    int n = 0;

    printf("Insira o número intero: \n");
    scanf("%d", &n);


    int vetor[n] = {};


    for (int i=0; i <= (n-1); i++) {
        vetor[i] = ((i+1)*(i+1));
        printf("%d ", vetor[i]);
    }


    return 0;
}