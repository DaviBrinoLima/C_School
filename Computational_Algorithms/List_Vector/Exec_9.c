#include <stdio.h>


int main() {
    int codigo[3] = {12,34,56};
    float preco[3] = {1.39, 2.49, 3.89};
    int len = 3;


    int consulta = 0;
    
    printf("Insira o código do produto desejado: \n");
    scanf("%d", &consulta);


    for (int i=0; i<len; i++) {
        if (codigo[i] == consulta) {
            printf("%f\n", preco[i]);
        }
    }


    return 0;
}