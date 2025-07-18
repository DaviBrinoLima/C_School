#include <stdio.h>

typedef struct{
int codigo, idade;
float salario;
char sexo;
}EmployeeRegistration;

int main(void) {
    EmployeeRegistration employee;
    char teste_sexo;

    while (1){
        printf("\n***Iniciando Cadastrado de novo funcionário (Para encerrar o programa insira '0' no código do funcionário)***\n");
        
        printf("Insira o código do funcionário: ");
        scanf(" %d", &employee.codigo);

        if (employee.codigo == 0) {
            break;
        }


        printf("Insira a idade do funcionário: ");
        scanf(" %d", &employee.idade);

        printf("Insira o salário do funcionário: ");
        scanf(" %f", &employee.salario);

        printf("Insira o sexo do funcionário (M para homem e F para mulher): ");
        scanf(" %c", &teste_sexo);

        while (1){
            if ((teste_sexo!= 'M') && (teste_sexo!= 'F')){
                printf("Sexo digitado inválido, por favor insera novamente o sexo (M para homem e F para mulher): ");
                scanf(" %c", &teste_sexo);
            }

            else {
                employee.sexo = teste_sexo;
                break;
            }
        }
    }
}
