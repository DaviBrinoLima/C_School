#include <stdio.h>
#include <stdlib.h>

int mm( int *vector_int, int *value_min, int *value_max) {
    *value_min = vector_int[0], *value_max = vector_int[0];

    int len_vector = 1, flag =1;

    while(flag) {
        if (vector_int[len_vector-1] == -1) {
            flag = 0;
        }

        else {
            len_vector++;
        }
    }
    
    for (int i = 1; i<len_vector-1; i++) {
        if (vector_int[i]< *value_min) {
            *value_min = vector_int[i];
        }

        if (vector_int[i]> *value_max) {
            *value_max = vector_int[i];
        }        
    }

    return 0;
}

int main() {
    int tamanho_vetor = 1, valor_minimo, valor_maximo;
    int *vetor = malloc(tamanho_vetor * sizeof(int));
    

    int flag = 1;

    while(flag) {
        printf("Insira o %d° elemento do vetor (Para finalizar a inserção de elementos DIGITE -1): ", tamanho_vetor);
        scanf(" %d", &vetor[tamanho_vetor-1]);

        if (vetor[tamanho_vetor-1] == -1) {
            flag = 0;
        }

        else{
            tamanho_vetor++;
        }
    }

    mm(vetor, &valor_minimo, &valor_maximo);
    printf("O menor valor do vetor é %d e o maior valor é %d\n", valor_minimo, valor_maximo);

    free(vetor);
    vetor = NULL;
    return 0;
}
