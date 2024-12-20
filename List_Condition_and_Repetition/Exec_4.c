#include <stdio.h>


int main() {
    int a = 0;
    int b = 0;


    printf("Digite o 1° ângulo: \n");
    scanf("%f", &a);

    printf("Digite o outro ângulo: \n");
    scanf("%f", &b);

    
    if (a+b >= 360) {
        float soma = (a+b) % 360;
        printf("%f\n", soma);
    }

    else {
        float soma = (a+b);
        printf("%f\n", soma);
    }
}