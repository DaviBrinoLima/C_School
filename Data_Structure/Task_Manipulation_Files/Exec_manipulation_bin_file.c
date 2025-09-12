#include <stdio.h>

typedef struct {
    int matricula;
    char nome[20];
    char sobrenome[20];
    int idade;
}Student;

void buffer_clear(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main() {
    FILE *archive = fopen("Banco_de_Dados_Alunos.dat", "a+b"); //Abre em modo de escrita append binária 

    if (archive == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO, ENCERRANDO O PROGRAMA\n");
        return 0;
    }

    Student aluno;

    printf("INICIANDO CADASTRO DE ALUNOS: \n\n");
    while (1) {
        printf("Insira a matricula do aluno (PARA ENCERRAR O CADASTRO DIGITE 0): ");
        scanf(" %d", &aluno.matricula);

        if (aluno.matricula == 0) {
            break;
        }

        buffer_clear();

        printf("Insira o primeiro nome do Aluno: ");
        scanf(" %s", aluno.nome);

        buffer_clear();
        
        printf("Insira o último nome do Aluno: ");
        scanf(" %s", aluno.sobrenome);

        printf("Insira a idade do Aluno: ");
        scanf(" %d", &aluno.idade);

        fwrite(&aluno,sizeof(Student),1,archive);

        if (ferror(archive) == 1) {
            printf("ERRO NO CADASTRO, ENCERRANDO O PROCESSO DE CADASTRO");
            break;
        }

        else{
            printf("\nCADASTRO REALIZADO COM SUCESSO, INICIANDO NOVO CADASTRO\n\n");
        }
    }

    fclose(archive);
    archive = fopen("Banco_de_Dados_Alunos.dat", "rb"); //Abre em modo de leitura binária
    
    if (archive == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO, ENCERRANDO O PROGRAMA\n");
        return 0;
    }

    while (fread(&aluno,sizeof(Student),1,archive)) {
        printf("\nNome do Aluno: %s\n", aluno.nome);
        printf("Sobrenome do Aluno: %s\n", aluno.sobrenome);
        printf("Idade do Aluno: %d\n", aluno.idade);
        printf("Matrícula do Aluno: %d\n", aluno.matricula);
    }
    
    fclose(archive);
}

