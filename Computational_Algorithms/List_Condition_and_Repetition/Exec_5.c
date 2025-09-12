#include <stdio.h>


int main() {
    int produto = 0;
    int quantidade = 0;
    float total = 0;


    printf("Insira o tipo de produto: \n");
    scanf("%d", &produto);

    printf("Insira a quantidade de produtos: \n");
    scanf("%d", &quantidade);


    if (produto == 1) {
        total = quantidade*1.10;
    }

    else if (produto == 2) {
        total = quantidade*2.30;
    }

    else if (produto == 3) {
        total = quantidade*4.70;
    }


    printf("%f\n", total);
    return 0;
}
