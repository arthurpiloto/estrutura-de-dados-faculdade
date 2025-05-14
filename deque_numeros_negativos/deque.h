/*
+----------------- File: deque.h -----------------------+
| Deque Duplamente Encadeado                            |
|					      		                        |
|					      		                        |
| Implementado por Arthur Piloto Silva em 14/05/2025    |
+-------------------------------------------------------+
*/

#ifndef DDE_H
#define DDE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info;
    NO *prox, *ant;
} NO;

NO* alocarNO() {
    return ((NO*)malloc(sizeof(NO)));
}

void liberarNO(NO *q) {
    free(q);
}

typedef struct {
    int qtd;
    NO *ini, *fim;
} Deque;

Deque* criaDeque() {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    if (dq != NULL) {
        dq->qtd = 0;
        dq->ini = dq->fim = NULL;
    }
    return dq;
}

int estaVazio(Deque *dq) {
    return (dq->ini == NULL);
}

int insereFim(Deque *dq, int elem) {
    if (dq == NULL) return 0;
    NO *novo = alocarNO();
    if (novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (estaVazio(dq)) {
        novo->ant = NULL;
        dq->ini = novo;
    } else {
        dq->fim->prox = novo;
        novo->ant = dq->fim;
    }
    dq->fim = novo;
    dq->qtd++;
    return 1;
}

int insereIni(Deque *dq, int elem) {
    if (dq == NULL) return 0;
    NO *novo = alocarNO();
    if (novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (estaVazio(dq)) {
        novo->ant = NULL;
        dq->ini = novo;
    } else {
        dq->fim->prox = novo;
        novo->ant = dq->fim;
    }
    dq->fim = novo;
    dq->qtd++;
    return 1;
}

#endif