#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    float processing_time;
    int priority;

}Part;

typedef struct 
{
    int *production_orders;
    int begin, end, len;

}Queue;

void QueueBegin(Queue *qq, int len_po) {
    qq->production_orders = calloc(len_po, sizeof(int));

    if (qq->production_orders == NULL){
        
    }

}


int main() {
    int len_production_orders = 15;
}

