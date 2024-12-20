#include <stdio.h>


int main () {
    char s[] = "abcd";
    // Em C, strings são vetores de caracter, ou seja, na mémoria a string é assim: {'a','b','c','d','\0'}, ou seja, esta string é um vetor com 5 índices.
    // O '\0' é o terminador da string, ele indica que a sequência de caracter chegou ao fim.


    printf("%s \n", s);
    return 0;
}