#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Cria pilha vazia
void criaPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
bool emptyPilha(Pilha *p) {
    return (p->topo == -1);
}

// Retorna o tamanho da pilha
int sizePilha(Pilha *p) {
    return p->topo + 1;
}

// Push – insere elemento no topo
void push(Pilha *p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

// Pop – remove elemento do topo
int pop(Pilha *p) {
    if (emptyPilha(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--];
}

// Retorna o topo sem remover (stackpop)
int stackpop(Pilha *p) {
    if (emptyPilha(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}

// Exibe pilha
void imprimePilha(Pilha *p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}


int main() {
    // Testando Pilha
    Pilha p;
    criaPilha(&p);
    push(&p, 5);
    push(&p, 15);
    push(&p, 25);
    imprimePilha(&p);
    printf("Topo: %d\n", stackpop(&p));
    printf("Removeu: %d\n", pop(&p));
    imprimePilha(&p);

    return 0;
}
