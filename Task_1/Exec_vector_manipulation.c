#include <stdio.h>
#include <stdlib.h>

 int *vetor_global, tam;

int reading_vector(int *vector) {
    int len_vector = 1;
    vector = malloc(len_vector * sizeof(int));
    
    if (vector == NULL){
        printf("Erro na alocação de memória para o Vetor. Encerrando o Programa, POR FAVOR EXECUTE O MESMO NOVAMENTE");
        free(vector); vector = NULL; return 0;
    }

    int flag = 1;

    while(flag) {
        printf("Insira o %d° elemento do vetor (Para finalizar a inserção de elementos DIGITE -1): ", len_vector);
        scanf(" %d", &vector[len_vector-1]);

        if (vector[len_vector-1] == -1) {
            vector = realloc(vector, (len_vector-1) * sizeof(int));

            if (vector == NULL){
                printf("Erro na alocação de memória para o Vetor. Encerrando o Programa, POR FAVOR EXECUTE O MESMO NOVAMENTE");
                free(vector); vector = NULL; return 0;
            }

            flag = 0;
        }

        else{
            len_vector++;
            vector = realloc(vector, len_vector * sizeof(int));

            if (vector == NULL){
                printf("Erro na alocação de memória para o Vetor. Encerrando o Programa, POR FAVOR EXECUTE O MESMO NOVAMENTE");
                free(vector); vector = NULL; return 0;
            }
        }
    }

    return len_vector;
    // Esta função realiza a leitura do vetor e retorna seu tamanho. Ela recebe como argumento um ponteiro, transforma este ponteiro em um vetor
    // com os elementos digitado pelo usuário e ao final, se esta função for chamada dentro de um int, este int terá o valor do tamanho do vetor.
}

int highest_value(int *vector, int len_vector) {
    int highest = vector[0];

    for (int i = 1; i<len_vector; i++) {
        if (vector[i] > highest) {
            highest = vector[i];
        }
    }

    return highest;
}

int arithmetic_mean(int *vector, int len_vector) {
    float sum = 0, mean;

    for (int i = 0; i<len_vector; i++) {
        sum += vector[i];
    }

    mean = sum/len_vector;

    return mean;
}

int exchange(int *vector, int len_vector, int x, int y) {
    int flag = 0;
    
    for (int i = 0; i<len_vector; i++){
        if (vector[i] == x) {
            vector[i] == y;
            flag++;
        }
    }

    if (flag>0) {
        return 1; // A função retorna 1 se foi realiza pelo menos uma troca de valores foi realizada.
    }

    else {
        return 0; //A função retorna 0 se nenhuma troca de valores for realizada.
    }
}

void print_vector(int *vector, int len_vector) {
    printf("VETOR = ");

    for (int i = 0; i<len_vector; i++) {
        printf("%d, ", vector[i]);
    }

    printf("\n");
}

int main() {
    tam = reading_vector(vetor_global);
    int maior_valor = highest_value(vetor_global, tam);
    
}


