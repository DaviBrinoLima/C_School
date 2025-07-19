#include <stdio.h>
#include <string.h>

void main(){
    char string[100000];
    char letra;
    int soma_letra = 0;

    printf("Informe a frase a ser analisada: ");
    fgets(string, 99999, stdin);
    int len_string = strlen(string);


    printf("Informe o caractere a ser procurado: ");
    scanf(" %c", &letra);

    for (int i = 0; i<len_string; i++){
        if (letra == string[i]) {
            soma_letra += 1;
        }
    }

    printf("Na frase '%.*s' foi encontrado o caractere '%c' %d vezes\n", (len_string-1), string, letra, soma_letra);
}   