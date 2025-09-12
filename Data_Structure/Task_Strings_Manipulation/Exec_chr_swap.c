#include <stdio.h>
#include <string.h>

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void main() {
    char frase[99999];
    char character_old, character_new;

    printf("Informe a frase a ser modificada: ");
    fgets(frase, 99999, stdin);
    
    int len_frase = strlen(frase);
    
    printf("Informe o caractere que será removido da string: ");
    scanf(" %c", &character_old);
    flush_in();

    int flag = 1;

    while (flag) {
        for(int i= 0; i<len_frase; i++) {
            if (frase[i] == character_old) {
                flag--;
            } 
        }

        if (flag == 1) {
            printf("O caractere informado não está presente na string. INSIRA UM CARACTERE VÁLIDO: ");
            scanf(" %c", &character_old);
            flush_in();
        }

        else{
            flag = 0;
        }
    }

    printf("Informe o caractere que será inserido na string: ");
    scanf(" %c", &character_new);
    flush_in();

    char nova_frase[len_frase];

    for (int j=0; j<len_frase; j++) {
        nova_frase[j] = frase[j];

        if (frase[j] == character_old) {
            nova_frase[j] = character_new;
        }
    }

    printf("A frase gerada após a modificação é: %.*s\n", (len_frase-1), nova_frase);
}