#include <stdio.h>
#include <string.h>

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int str_chr(char *string, char character, int index) {
    int len = strlen(string), result_index = 0;

    for (int i = index; i<len; i++){
        if (character == string[i]) {
            result_index = i;
            return result_index;
        }
    }   
}

int correct_errors(char *string, char index_desire){
    int len = strlen(string)-2;
    int index;

    while (1){
        if (index_desire != 'y' && index_desire != 'n') {
            printf("Opção inserida inválida! (DIGITE 'y' PARA SIM E 'n' PARA NÃO): ");
            scanf(" %c", &index_desire);
            flush_in();
        }

        else{
            if (index_desire == 'y') {
            printf("Insira o índice em que a busca deve ser iniciada: ");
            scanf(" %d", &index);
            }
            

            else if (index_desire == 'n') {
            index = 0;
            }

            break;
        }
    }

    while (1){
        if (index>len){
            printf("O índice inserido é maior que o tamanho da string, LIMITE DO INDÍCE = %d! (INSIRA NOVAMENTE O ÍNDICE): ", (len));
            scanf(" %d", &index); 
        }

        else {
            break;
        }
    }

    return index;
}

void main(){
    char frase[99999];
    char caractere;

    printf("Informe a frase a ser analisada: ");
    fgets(frase, 99999, stdin);

    printf("Informe o caractere a ser procurado: ");
    scanf(" %c", &caractere);
    flush_in();

    char deseja_indice;
    printf("Você deseja iniciar a busca a partir de um índice específico? (Digite 'y' para Sim ou 'n' para Não): ");
    scanf(" %c", &deseja_indice);
    flush_in();
    
    int indice_desejado = correct_errors(frase, deseja_indice);
    int indice_resultado = str_chr(frase, caractere, indice_desejado);

    if (indice_resultado == 0){
        printf("\nNão foi encontrado nenhuma aparição do caractere '%c' a partir do índice %d na string analisada\n", caractere, indice_desejado);
    }

    else{
    printf("\nA primeira aparição do caractere '%c' a partir do índice %d ocorre no índice: %d\n", caractere, indice_desejado, indice_resultado);
    }
}