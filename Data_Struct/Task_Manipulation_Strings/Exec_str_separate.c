#include <stdio.h>
#include <string.h>

int main(void) {
    char string[1500000];


    printf("Insira a String a ser operada: ");
    fgets(string,1500000,stdin);

    int len_frase = strlen(string);


    printf("\nSeparando a string ao encontrar o 1° '$' e invertendo a parte anterior a ele:\n");

    for (int i = 0; i < len_frase; i++){
        if (string[i] == '$') {
            for (int u = i-1; u>= 0; u--) {
                printf("%c\n", string[u]);
            }
            break;
        }
        
    }
}