#include <stdio.h>
#include <string.h>

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int str_chr(char *string, char caracter, int index) {
    int len = strlen(string);

    for (int i = index; i<len; i++){
        if (caracter == string[i]) {
            return i;
        }

        else if ((caracter != string[i]) && (i== len-1)){
            return -1;
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

    if (indice_resultado == -1){
        printf("\nNão foi encontrado nenhuma aparição do caractere '%c' a partir do índice %d na string analisada\n", caractere, indice_desejado);
    }

    else{
    printf("\nA primeira aparição do caractere '%c' a partir do índice %d ocorre no índice: %d\n", caractere, indice_desejado, indice_resultado);
    }
}