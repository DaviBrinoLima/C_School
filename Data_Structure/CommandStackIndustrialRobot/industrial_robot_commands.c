#include <stdio.h>
#include <stdlib.h>

char command[50];


typedef struct 
{
    Part *production_orders;
    int begin, end, len_queue, len_production_orders;

}Stack;

void queuebegin(Queue *qq) {
    qq->begin= 0;
    qq->end=-1;
    qq->len_queue = 0;
    qq->len_production_orders = 0;

    qq->production_orders = malloc((1) * sizeof(Part));
}

void enqueue(Queue *qq,Part pt){
    if ((qq->end +1) == (qq->len_queue)){
        qq->len_production_orders++;
        qq->production_orders= realloc(qq->production_orders, (qq->len_production_orders) * sizeof(Part));
    }

    qq->end = ((qq->end + 1) % qq->len_production_orders);
    qq->production_orders[qq->end] = pt;
    qq->len_queue++;
}

Part dequeue(Queue *qq){
    if (qq->len_queue == 0) {
        Part null_part;
        null_part.id = -1, null_part.priority= -1, null_part.processing_time = 0;

        return null_part;
    }

    Part pt = qq->production_orders[qq->begin];
    qq->begin = ((qq->begin + 1) % qq->len_production_orders);
    qq->len_queue--;

    return pt;
}

void print_queues(Queue *normal_queue, Queue *priority_queue) {
    printf("EXIBINDO A FILA DE PEÇAS AGUARDANDO PROCESSAMENTO POR ORDEM DE CHEGADA E PRIORIDADE\n");

    if ((priority_queue->len_queue) == 0 && (normal_queue->len_queue==0)){
        printf("\nFILA VAZIA! NENHUMA PEÇA AGUARDNANDO PROCESSAMENTO\n");
    }

    else{
        for (int i = 0; i<priority_queue->len_queue; i++) {
            int index = ((priority_queue->begin + i) % priority_queue->len_production_orders);

            printf("\nID da Peça: %d", priority_queue->production_orders[index].id);
            printf("\nTempo necessário para processamento da Peça: %fs", priority_queue->production_orders[index].processing_time);
            printf("\nPrioridade da peça = URGENTE");
            printf("\nPosição da peça na fila: %d\n", i+1);
        }

        for (int i = 0; i<normal_queue->len_queue; i++) {
            int index = ((normal_queue->begin + i) % normal_queue->len_production_orders);

            printf("\nID da Peça: %d", normal_queue->production_orders[index].id);
            printf("\nTempo para processamento da Peça: %fs", normal_queue->production_orders[index].processing_time);
            printf("\nPrioridade da peça = NORMAL");
            printf("\nPosição da peça na fila: %d\n", (priority_queue->len_queue+1+i));
        }
    }

}

int main() {
    Queue normal_queue, priority_queue;
    Part master_part;

    int num_processed_parts = 0;
    float total_processing_time = 0;



    queuebegin(&normal_queue);
    queuebegin(&priority_queue);

    printf("INICIANDO CLI DO CONTROLE DE PRODUÇÃO DE PEÇAS\n");
    printf("--------------------------------------------------------------------------------------------------------------\n\n");

    while (1) {
        int next_command;

        printf("1 - INSERIR NOVA PEÇA \n2 - PROCESSAR PRÓXIMA PEÇA DA FILA \n3 - EXIBIR FILA DE PEÇAS \n4 - EXIBIR ESTATÍSTICAS \n0 - ENCERRAR O PROGRAMA\n\n");
        scanf("%d", &next_command);

        printf("--------------------------------------------------------------------------------------------------------------\n\n");

        if (next_command == 0) {
            break;
        }

        else if (next_command == 1){
            printf("INICIANDO INSERÇÃO DE NOVA PEÇA\n\n");

            printf("Digite o ID da nova peça: ");
            scanf(" %d", &master_part.id);
            
            printf("Digite o tempo necessário para o processamento da nova peça (TEMPO EM SEGUNDOS): ");
            scanf(" %f", &master_part.processing_time);

            printf("Digite a prioridade da nova peça (URGENTE = 1 | NORMAL = 0): ");
            scanf(" %d", &master_part.priority);

            if (master_part.priority == 1) {
                enqueue(&priority_queue, master_part);
            }

            else{
                enqueue(&normal_queue, master_part);
            }
        }

        else if (next_command == 2){
            printf("PROCESSANDO PRÓXIMA PEÇA DA FILA, AGUARDE!\n\n");

            if (priority_queue.len_queue > 0) {
                master_part = dequeue(&priority_queue);
                sleep(master_part.processing_time);
            }

            else {
                master_part = dequeue(&normal_queue);
                sleep(master_part.processing_time);
            }

            if (master_part.id != -1) { 
                printf("PROCESSANDO CONCLÚIDO, A PEÇA PROCESSADA CONTÉM OS SEGUINTES DADOS: \n\n");

                printf("\nID da Peça: %d", master_part.id);
                printf("\nDuração do processamento da Peça: %fs", master_part.processing_time);
                
                if (master_part.priority == 1){
                    printf("\nPrioridade da peça processada: URGENTE");
                }

                else {
                    printf("\nPrioridade da peça processada: NORMAL\n");
                }

                num_processed_parts++;
                total_processing_time = total_processing_time + master_part.processing_time;
            }

            else {
                printf("IMPOSSÍVEL CONCLUIR PROCESSAMENTO, A FILA ESTÁ VAZIA!\n\n");
            }

        }   
        
        else if (next_command == 3) {
            print_queues(&normal_queue, &priority_queue);
        }

        else if (next_command == 4) {
            printf("EXIBINDO ESTATÍSTICAS DO CONTROLE DE PRODUÇÃO\n\n");
            
            printf("Total de peças processadas = %d\n", num_processed_parts);
            printf("Tempo total gasto processando peças = %f\n", total_processing_time);
        }

        printf("\n--------------------------------------------------------------------------------------------------------------\n\n");   
    }

    free(priority_queue.production_orders), free(normal_queue.production_orders);
}

