#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *str_segment(char *string, char *new_string, int lower_limit, int upper_limit){
    int aux_index = 0;
    
    for (lower_limit; lower_limit<=upper_limit; lower_limit++){
        new_string[aux_index] = string[lower_limit];
        aux_index++;
    }

    return new_string;
}

int correct_lower(int lower_limit, char *string){
    int max_value = strlen(string)-2;

    while (1){
        if (lower_limit < 0 || lower_limit >= max_value ){
            printf("ÍNDICE INFERIOR INVÁLIDO, VALOR MÍNIMO = 0 E VALOR MÁXIMO = %d! (INSIRA NOVAMENTE O ÍNDICE): ", max_value-1);
            scanf(" %d", &lower_limit); 
        }

        else {
            break;
        }
    }

    return lower_limit;
}

int correct_upper(int upper_limit, char *string){
    int max_value = strlen(string)-2;

    while (1){
        if (upper_limit < 0 || upper_limit> max_value){
            printf("ÍNDICE SUPERIOR INVÁLIDO, VALOR MÍNIMO = 0 E VALOR MÁXIMO = %d! (INSIRA NOVAMENTE O ÍNDICE): ", max_value);
            scanf(" %d", &upper_limit); 
        }

        else {
            break;
        }
    }

    return upper_limit;
}

void main(){
    char frase[99999];
    int lim_inf, lim_sup;

    printf("Informe a frase a ser segmentada: ");
    fgets(frase, 99999, stdin);

    printf("Informe o índice inferior da string segmentada: ");
    scanf(" %d", &lim_inf);

    int lim_inf_corret = correct_lower(lim_inf, frase);
    
    printf("Informe o índice superior da string segmentada: ");
    scanf(" %d", &lim_sup);

    int lim_sup_corret = correct_upper(lim_sup, frase);

    char *nova_frase = (char*) malloc((lim_sup_corret-lim_inf_corret+1) * sizeof(char));

    char *frase_segmentada = str_segment(frase, nova_frase, lim_inf_corret, lim_sup_corret);

    printf("A frase segmentada é: %s\n", frase_segmentada);
}