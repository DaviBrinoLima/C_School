#include <stdio.h>

void main() {
    int num;

    printf("Insira o fatorial a ser calculado: ");
    scanf("%d", &num);

    int fat = num;

    for (int i = fat-1; i>=1; i--) {
        fat = fat * i;
    }

    printf("O Fatorial de %d é = %d\n", num,fat);
}