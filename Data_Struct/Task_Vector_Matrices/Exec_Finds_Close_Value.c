#include <stdio.h>
#include <stdlib.h>

void main() {
    int index, close_value, diff_values= 100000;

    printf("Insira o tamanho desejado para o vetor: ");
    scanf("%d", &index);

    printf("Insira o número a ser analisado: ");
    scanf("%d", &close_value);

    int vector[index];

    for (int i=0; i<index;i++) {
        printf("Insira o %d° elemento do vetor: ", (i+1));
        scanf("%d", &vector[i]);

        int modulo = abs(vector[i]-close_value);

        if (modulo < diff_values){
            diff_values = modulo;
        }   
    }

    int comparator, cont=0;

    printf("O(s) número(es) do vetor mais próximo(s) do número analisado é: ");

    for (int i= 0; i<index;i++) {
        int modulo = abs(vector[i]-close_value);

        if (modulo == diff_values){
            if (cont==0){
            comparator= vector[i];
            printf("%d",vector[i]);
            cont++;
            }
            
            else if(comparator!=vector[i] && cont==1){
                printf(" e %d\n",vector[i]);
                cont++;
            }

            
        } 
    }
}