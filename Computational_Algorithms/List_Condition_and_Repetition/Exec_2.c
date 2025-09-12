#include <stdio.h>


int main() {
    int produtos = 333;
    int caixas = 12;


    int caixas_preenchidas =  produtos/caixas;
    int resto = produtos % caixas;


    printf("%d\n%d\n", caixas_preenchidas, resto);

    
    return 0;
}