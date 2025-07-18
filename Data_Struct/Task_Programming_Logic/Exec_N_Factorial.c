#include <stdio.h>

void main() {
    int num;

    printf("Insira o número a ter o fatorial calculado (Limite Máximo = 65 | Limite mínimo: 1): ");
    scanf(" %d", &num);

    while(1){
        if (num > 65 || num < 1) {
        printf("O número inserido está fora dos limites estabelecidos, insira outro número: ");
        scanf(" %d", &num);
        }

        else {
            break;
        }
    }

    unsigned long long int fat = num;

    for (int i = fat-1; i>=1; i--) {
        fat = fat * i;
    }

    printf("O Fatorial de %d é = %llu\n", num,fat);
}