#include <stdio.h>
#include <math.h>


int main(void) {
    int cateto_1, cateto_2;

    printf("Insira o valor do 1° Cateto: ");
    scanf("%d", &cateto_1);

    printf("Insira o valor do 2° Cateto: ");
    scanf("%d", &cateto_2);
    
    int  hipotenusa_quadrado = pow(cateto_1, 2) + pow(cateto_2, 2);
    double hipotenusa = sqrt(hipotenusa_quadrado);

    printf("A hipotenusa do triângulo retângulo é: %lf\n", hipotenusa);
}