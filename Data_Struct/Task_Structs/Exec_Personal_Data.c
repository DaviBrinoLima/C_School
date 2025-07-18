#include <stdio.h>

typedef struct{
int idade;
char CEP[10];
char nome[100];
}PersonalData;

void main() {
    PersonalData peoples[3];
    int maior_idade = 0, pessoa_mais_velha;

    for (int i=0; i<=2; i++){
        printf("\n***Iniciando Cadastrado, Insira os dados de 10 pessoas***\n");
        
        printf("Insira o 1° nome da pessoa: ");
        scanf(" %s", &peoples[i].nome);

        printf("Insira a idade da pessoa: ");
        scanf(" %d", &peoples[i].idade);
        
        printf("Insira o CEP da pessoa: ");
         scanf(" %9s", &peoples[i].CEP); 

        while (1){
            if (peoples[i].CEP[0] == '0' || peoples[i].CEP[5] != '-'){
                printf("CEP INVÁLIDO, insira novamente o CEP: ");
                scanf(" %9s", &peoples[i].CEP);  
            }

            else {
                break;
            }
        }

        if (maior_idade < peoples[i].idade) {
            maior_idade = peoples[i].idade;
            pessoa_mais_velha = i;
        }
    }

    printf("\n***Exibindo os dados da pessoa mais velha cadastrada***\n");
    printf("Nome: %s\n", peoples[pessoa_mais_velha].nome);
    printf("Idade: %d\n", peoples[pessoa_mais_velha].idade);
    printf("Endereço (CEP): %s\n", peoples[pessoa_mais_velha].CEP);
}