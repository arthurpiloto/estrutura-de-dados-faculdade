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
    struct NO *prox, *ant;
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

void destroiDeque(Deque *dq) {
    if (dq != NULL) {
        NO *aux;
        while (dq->ini != NULL) {
            aux = dq->ini;
            dq->ini = dq->ini->prox;
            liberarNO(aux);
        }
        free(dq);
    }
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

int removeFim(Deque *dq) {
    if (dq == NULL || estaVazio(dq)) return 0;
    NO *aux = dq->fim;
    if (dq->ini == dq->fim) dq->ini = dq->fim = NULL;
    else {
        dq->fim = dq->fim->ant;
        dq->fim->prox = NULL;
    }
    liberarNO(aux);
    dq->qtd--;
    return 1;
}

int insereIni(Deque *dq, int elem) {
    if (dq == NULL) return 0;
    NO *novo = alocarNO();
    if (novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (estaVazio(dq)) {
        novo->prox = NULL;
        dq->fim = novo;
    } else {
        dq->ini->ant = novo;
        novo->prox = dq->ini;
    }
    dq->ini = novo;
    dq->qtd++;
    return 1;
}

int removeIni(Deque *dq) {
    if (dq == NULL || estaVazio(dq)) return 0;
    NO *aux = dq->ini;
    if (dq->ini == dq->fim) dq->ini = dq->fim = NULL;
    else {
        dq->ini = dq->ini->prox;
        dq->ini->ant = NULL;
    }
    liberarNO(aux);
    dq->qtd--;
    return 1;
}

void imprime(Deque *dq) {
    if (dq == NULL || estaVazio(dq)) return;
    NO *aux = dq->ini;
    printf("Elementos: ");
    while(aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int removeNegativos(Deque *dq) {
    if (dq == NULL || estaVazio(dq)) return 0;
    NO *aux = dq->ini;
    while (aux != NULL) {
        NO *prox = aux->prox;

        if (aux->info < 0) {
            if (aux->ant != NULL) aux->ant->prox = aux->prox;
            else dq->ini = aux->prox;

            if (aux->prox != NULL) aux->prox->ant = aux->ant;
            else dq->fim = aux->ant;

            liberarNO(aux);
            dq->qtd--;
        }

        aux = prox;
    }
}

#endif