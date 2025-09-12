#include <stdio.h>
#include <stdlib.h>

 int *vetor_global, tam;

void buffer_clear(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int *reading_vector(int len_vector) {
    int *vector = malloc(len_vector * sizeof(int));
    
    if (vector == NULL){
        printf("Erro na alocação de memória para o Vetor. Encerrando o Programa, POR FAVOR EXECUTE O MESMO NOVAMENTE");
        return NULL;
    }

    for (int i=0; i<len_vector; i++) {
        printf("Insira o %d° elemento do Vetor: ", (i+1));
        scanf(" %d", &vector[i]);
    }

    printf( "\n");
    return vector;
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

int exchange_values(int *vector, int len_vector, int x, int y) {
    int flag = 0;
    
    for (int i = 0; i<len_vector; i++){
        if (vector[i] == x) {
            vector[i] = y;
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
    printf("Insira o tamanho desejado para o Vetor Global: ");
    scanf(" %d", &tam);

    vetor_global = reading_vector(tam);
    if (vetor_global == NULL) {
        free(vetor_global); return 0; 
    }

    int maior_valor = highest_value(vetor_global, tam);
    float media_aritmetica = arithmetic_mean(vetor_global, tam);
    
    print_vector(vetor_global, tam);
    printf("O maior valor dentre os elementos do Vetor Global é: %d\n", maior_valor);
    printf("A média aritmética dos elementos do Vetor Global é: %f\n", media_aritmetica);

    char deseja_troca;
    printf("\nDigite 'y' para realizar troca de valores no vetor ou QUALQUER TECLA para encerrrar o programa: ");
    scanf(" %c", &deseja_troca);
    
    buffer_clear();

    if (deseja_troca == 'y'){
        int x,y;

        printf("Insira o valor do Vetor Global que será substituido: ");
        scanf("%d", &x);

        printf("Insira o valor que será inserido no lugar: ");
        scanf("%d", &y);

        printf("\n --- TROCANDO TODAS AS APARIÇÕES DO NÚMERO %d NO VETOR GLOBAL POR %d ---\n",x,y);
        int flag_exchange = exchange_values(vetor_global, tam, x, y);

        if (flag_exchange == 1) {
        printf("A troca de valores foi realizada com sucesso, mostrando o novo vetor formado --> ");
        print_vector(vetor_global,tam);
        }
    }

    free(vetor_global); vetor_global = NULL;
    return 0;
}


