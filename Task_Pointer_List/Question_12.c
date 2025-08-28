#include <stdio.h>
#include <stdlib.h>

int *allocate_vector(int len_vector) {
    int *vector = malloc(len_vector * sizeof(int));

    if (vector == NULL){
        printf("Erro na alocação de memória para o Vetor. Encerrando o Programa, POR FAVOR EXECUTE O MESMO NOVAMENTE");
        free(vector); return NULL;
    }

    else{
        return vector;
    }
}

void print_vector(int **pointer_to_vector, int len_vector) {
   printf("---> VETOR = ");

    for (int i = 0; i<len_vector; i++) {
        printf("%d, ", *(*pointer_to_vector));

        (*pointer_to_vector)++;
    }

    printf("\n");
}

int main() {
    int tamanho_vetor, *vetor, **ponteiro_vetor;

    printf("Insira o tamanho desejado para o Vetor: ");
    scanf(" %d", &tamanho_vetor);

    vetor = allocate_vector(tamanho_vetor);
    if (vetor == NULL) {
        free(vetor); return 0;
    }

    for (int i=0; i<tamanho_vetor; i++) {
        printf("Insira o %d° elemento do Vetor: ", (i+1));
        scanf(" %d", &vetor[i]);
    }

    printf( "\n");

    ponteiro_vetor = &vetor;
    print_vector(ponteiro_vetor, tamanho_vetor);
    
    vetor--;free(vetor); vetor = NULL;
    free(ponteiro_vetor); ponteiro_vetor = NULL;
    
    return 0;
}