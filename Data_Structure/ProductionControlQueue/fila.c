#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int ini, fim, tamanho;
} Fila;

// Cria fila vazia
void criaFila(Fila *f) {
    f->ini = 0;
    f->fim = -1;
    f->tamanho = 0;
}

// Verifica se a fila está vazia
bool emptyFila(Fila *f) {
    return (f->tamanho == 0);
}

// Retorna o tamanho da fila
int sizeFila(Fila *f) {
    return f->tamanho;
}

// Insere elemento no final (enqueue)
void enqueue(Fila *f, int valor) {
    if (f->tamanho == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX; // incremento circular
    f->dados[f->fim] = valor;
    f->tamanho++;
}

// Remove elemento do início (dequeue)
int dequeue(Fila *f) {
    if (emptyFila(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->ini];
    f->ini = (f->ini + 1) % MAX;
    f->tamanho--;
    return valor;
}

// Retorna o primeiro da fila sem remover
int front(Fila *f) {
    if (emptyFila(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->dados[f->ini];
}

// Exibe fila
void imprimeFila(Fila *f) {
    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->ini + i) % MAX;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}


int main() {
    // Testando Fila
    Fila f;
    criaFila(&f);
    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);
    imprimeFila(&f);
    printf("Front: %d\n", front(&f));
    printf("Removeu: %d\n", dequeue(&f));
    imprimeFila(&f);

    return 0;
}
