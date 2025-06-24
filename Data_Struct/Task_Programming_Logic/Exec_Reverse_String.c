#include <stdio.h>
#include <string.h>

int main(void) {
    char frase[81];


    printf("Insira a frase a ser invertida: ");
    fgets(frase,80,stdin);

    int len_frase = strlen(frase);


    printf("\nInvertendo a frase inserida");

    for (int i = len_frase - 1; i>= 0; i--){
        printf("%c\n", frase[i]);
    }
}