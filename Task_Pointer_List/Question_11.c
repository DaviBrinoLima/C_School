#include <stdio.h>
#include <stdlib.h>

int *reading_vector(int len_vector) {
    int *vector = malloc(len_vector * sizeof(int));
    
    if (vector == NULL){
        printf("Erro na alocação de memória para o Vetor. Encerrando o Programa, POR FAVOR EXECUTE O MESMO NOVAMENTE");
        free(vector); return NULL;
    }

    for (int i=0; i<len_vector; i++) {
        printf("Insira o %d° elemento do Vetor: ", (i+1));
        scanf(" %d", &vector[i]);
    }

    printf( "\n");
    return vector;
}

int main() {
    int tamanho_vetor, *vetor;

    printf("Insira o tamanho desejado para o Vetor: ");
    scanf(" %d", &tamanho_vetor);

    vetor = reading_vector(tamanho_vetor);
    if (vetor == NULL) {
        free(vetor); return 0;
    }

    printf("\n ---> VETOR = ");

    for (int i = 0; i<tamanho_vetor; i++) {
        printf("%d, ", vetor[i]);
    }

    printf("\n");

    free(vetor); vetor = NULL; return 0;
}