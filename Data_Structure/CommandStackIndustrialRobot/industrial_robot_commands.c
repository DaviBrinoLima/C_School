#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char **commands;
    int top;
    int stack_len;

}Stack;

void stackbegin(Stack *st) {
    st->top = -1;
    st->commands = malloc((1) * sizeof(char *));
}

void stack_up(Stack *st,char *command){
    if ((st->top +1) == (st->stack_len)){
        st->stack_len++;
        st->commands= realloc(st->commands, (st->stack_len) * sizeof(char *));
    }

    st->top++;
    st->commands[st->top]= command;
}

char *undo_stack(Stack *action, Stack *undo){
    if (action->top == -1) {
        printf("\nIMPOSSÍVEL DESFAZER COMANDO, A PILHA DE AÇÕES ESTÁ VAZIA!\n");
        return NULL;
    }
    
    char *command_executed = action->commands[action->top];

    action->top--;

    if ((undo->top + 1) == (undo->stack_len)){
        undo->stack_len++;
        undo->commands= realloc(undo->commands, (undo->stack_len) * sizeof(char *));
    }

    undo->top++;
    undo->commands[undo->top] = command_executed;

    return command_executed;
}

char *redo_stack(Stack *undo, Stack *action){
    if (undo->top == -1) {
        printf("\nIMPOSSÍVEL REFAZER COMANDO, A PILHA DE DESFAZER ESTÁ VAZIA!\n");
        return NULL;
    }
    
    char *command_executed = undo->commands[undo->top];

    undo->top--;


    action->top++;
    action->commands[action->top] = command_executed;

    return command_executed;
}

void print_stacks(Stack *action, Stack *undo) {
    printf("EXIBINDO PILHA DE AÇÕES:\n");

    if ((action->top) == -1){
        printf("\nPILHA DE AÇÕES VAZIA! NENHUM COMANDO EXECUTADO\n");
    }

    else{
        for (int i = 0; i<=action->top; i++) {
            printf("\nComando: %s\n", action->commands[action->top - i]);
            printf("\nPosição do comando na pilha: %d\n", action->top - i);
        }
    }

    printf("\nEXIBINDO PILHA DE DESFAZER:\n");

    if ((undo->top) == -1){
        printf("\nPILHA DE DESFAZER VAZIA! NENHUM COMANDO PARA SER DESFEITO\n");
    }

    else{
        for (int i = 0; i<=undo->top; i++) {
            printf("\nComando: %s\n", undo->commands[undo->top - i]);
            printf("\nPosição do comando na pilha: %d\n", undo->top - i);
        }
    }

}

int main() {
    char robot_command[50];

    Stack stack_action, stack_undo;



    stackbegin(&stack_action);
    stackbegin(&stack_undo);

    printf("INICIANDO CLI DA PILHA DE COMANDOS DE UM ROBÔ INDUSTRIAL\n");
    printf("--------------------------------------------------------------------------------------------------------------\n\n");

    while (1) {
        int next_command;

        printf("1 - EXECUTAR NOVO COMANDO \n2 - DESFAZER COMANDO\n3 - REFAZER COMANDO \n4 - LISTAR PILHAS \n0 - ENCERRAR O PROGRAMA\n\n");
        scanf("%d", &next_command);

        printf("--------------------------------------------------------------------------------------------------------------\n\n");

        if (next_command == 0) {
            break;
        }

        else if (next_command == 1){
            printf("INICIANDO EXECUÇÃO DE NOVO COMANDO\n\n");

            printf("Digite o novo comando a ser executado: \n");
            scanf(" %s", robot_command);

            stack_up(&stack_action, robot_command);
        }   

        else if (next_command == 2){
            printf("DESFAZENDO COMANDO!\n\n");
            char *undo_commando = undo_stack(&stack_action, &stack_undo);


            if (undo_commando != NULL){
            printf("O comando desfeito foi: %s\n\n", undo_commando);
            }
        }   
        
        else if (next_command == 3) {
            printf("REFAZENDO COMANDO!\n\n");
            char *redo_commando = redo_stack(&stack_undo, &stack_action);


            if (redo_commando != NULL){
            printf("O comando desfeito foi: %s\n\n", redo_commando);
            }
        }

        else if (next_command == 4) {
            printf("LISTANDO PILHAS\n\n");
            print_stacks(&stack_action,&stack_undo);
        }

        printf("\n--------------------------------------------------------------------------------------------------------------\n\n");   
    }

    free(stack_action.commands), free(stack_undo.commands);
}

