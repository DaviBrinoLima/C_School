#include <stdio.h>

int main(void) {
    int num = 0;

    printf("Digite o número de 4 dígitos a ser decomposto: ");
    scanf("%d", &num);

    int unidade = num%10;
    int dezena = (num/10)%10;
    int centena = (num/100)%10;
    int milhar = num/1000;

    printf("\nUnidade = %d\nDezena = %d\nCentena = %d\nMilhar = %d\n", unidade,dezena,centena,milhar);
}