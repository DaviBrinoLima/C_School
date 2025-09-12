#include <stdio.h>
#include <string.h>

int str_str(char *string_1, char *string_2) {
    int len_string_1 = strlen(string_1), len_string_2 = strlen(string_2);
    int index_1, index_2 = 0, result_index = 0;

    for (index_1 = 0; index_1<len_string_1; index_1++) {
        if ((string_1[index_1] == string_2[index_2]) && (index_2 <len_string_2)) {
            if(index_2 == 0){
                result_index = index_1;
            }

            index_2++;
         
        }
    }

    return result_index;
}

void main(){
    char frase_1[99999], frase_2[99999];

    printf("Informe a string principal: ");
    fgets(frase_1, 99999, stdin);
    int len_frase_1 = strlen(frase_1);

    printf("Informe a string a ser verificada: ");
    fgets(frase_2, 99999, stdin);
    int len_frase_2 = strlen(frase_2);

    int indice_resultado = str_str(frase_1, frase_2);
    
    if (indice_resultado == 0){
        printf("A string '%.*s' NÃO é uma SubString da string '%.*s'\n", (len_frase_2-1),frase_2, (len_frase_1-1),frase_1);
    }
    else{
        printf("A string '%.*s' é uma SubString da string '%.*s'. Ela se inicia no índice %d da String Principal\n", (len_frase_2-1),frase_2, (len_frase_1-1),frase_1, indice_resultado);
    }
    
    
}