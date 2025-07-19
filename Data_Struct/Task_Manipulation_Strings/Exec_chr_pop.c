#include <stdio.h>
#include <string.h>

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void main() {
    char frase[99999];
    char character;

    printf("Informe a frase a ser modificada: ");
    fgets(frase, 99999, stdin);
    
    int len_frase = strlen(frase);
    char nova_frase[len_frase];

    printf("Informe o caractere que será removido da string: ");
    scanf(" %c", &character);
    flush_in();

    int flag = 1;

    while (flag) {
        for(int i= 0; i<len_frase; i++) {
            if (frase[i] == character) {
                flag--;
            } 
        }

        if (flag == 1) {
            printf("O caractere informado não está presente na string. INSIRA UM CARACTERE VÁLIDO: ");
            scanf(" %c", &character);
            flush_in();
        }

        else{
            flag = 0;
        }
    }

    int index_counter = 0;

    for (int j= 0; j<len_frase; j++) {
        if (frase[j] != character) {
            nova_frase[index_counter] = frase[j];
            index_counter++;
        }

    }

    printf("A frase gerada após a modificação é: %.*s\n", (index_counter-1), nova_frase);
}