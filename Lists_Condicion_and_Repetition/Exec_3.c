#include <stdio.h>


int main() {
    float comprimento = 5;
    float largura = 8;


    printf("Digite o comprimento: \n");
    scanf("%f", &comprimento);

    printf("Digite a altura: \n");
    scanf("%f", &largura);


    if (comprimento == largura) {
        float area = comprimento*largura;
        printf("quadrado\n");
    }

    else {
        float area = comprimento*largura;
        printf("retângulo\n");
    }
    

    return 0;
}   

