/*
+----------------- File: deque.h -----------------------+
| Deque Sequencial Estático                             |
|					      		                        |
|					      		                        |
| Implementado por Arthur Piloto Silva em 14/05/2025    |
+-------------------------------------------------------+
*/

#ifndef DEQUE_H
#define DEQUE_H
#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int qtd, ini, fim;
    int dados[MAX];
} Deque;

Deque* criaDeque() {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    if (dq != NULL) dq -> qtd = dq -> ini = dq -> fim = 0;
    return dq;
}

void destroiDeque(Deque *dq) {
    if (dq != NULL) free(dq);
}

int estaCheio(Deque *dq) {
    return (dq->qtd == MAX);
}

int estaVazio(Deque *dq) {
    return (dq->qtd == 0);
}

int insereFim(Deque *dq, int elem) {
    if (dq == NULL || estaCheio(dq)) return 0;
    dq->dados[dq->fim] = elem;
    dq->fim = (dq->fim+1) % MAX;
    dq->qtd++;
    return 1; 
}

int removeFim(Deque *dq, int *c) {
    if (dq == NULL || estaVazio(dq)) return 0;
    dq->fim = (dq->fim-1 < 0 ? MAX-1 : dq->fim-1);
    dq->qtd--;
    return 1; 
}

int insereIni(Deque *dq, int elem) {
    if (dq == NULL || estaCheio(dq)) return 0;
    dq->ini = (dq->ini-1 < 0 ? MAX-1 : dq->ini-1);
    dq->dados[dq->ini] = elem;
    dq->qtd++;
    return 1; 
}

int removeIni(Deque *dq, int *c) {
    if (dq == NULL || estaVazio(dq)) return 0;
    dq->ini = (dq->ini+1) % MAX;
    dq->qtd--;
    return 1; 
}

void imprime(Deque *dq) {
    if (dq == NULL || estaVazio(dq)) return;
    int i = dq->ini;
    printf("Itens: ");
    do {
        printf("%d ", dq->dados[i]);
        i = (i+1) % MAX;
    } while(i != dq->fim);
    printf("\n");
}

void imprimeInverso(Deque *dq) {
    if (dq == NULL || estaVazio(dq)) return;
    int i = (dq->fim - 1 + MAX) % MAX;
    printf("Itens: ");
    for (int count = 0; count < dq->qtd; count++) {
        printf("%d ", dq->dados[i]);
        i = (i - 1 + MAX) % MAX;
    }
    printf("\n");
}


#endif