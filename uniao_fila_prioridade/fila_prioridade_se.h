/*
+----------------- File: fila_prioridade_se.h ----------+
| Fila de Prioridade Simplismente Encadeada             |
|					      		                        |
|					      		                        |
| Implementado por Arthur Piloto Silva em 28/05/2025    |
+-------------------------------------------------------+
*/

#ifndef FPSE_H
#define FPSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info, prio;
    struct NO *prox;
} NO;

NO* alocarNO() {
    return ((NO*)malloc(sizeof(NO)));
}

void liberarNO(NO *q) {
    free(q);
}

typedef struct NO* FilaP;

FilaP* criaFila() {
    FilaP *fp = (FilaP*)malloc(sizeof(FilaP));
    if (fp != NULL) *fp = NULL;
    return fp;
}

int estaVazia(FilaP *fp) {
    if (fp == NULL) return 0;
    return ((*fp) == NULL);
}

int tamanhoFila(FilaP *fp) {
    if (fp == NULL || estaVazia(fp)) return 0;
    int tam = 0;
    NO *aux = *fp;
    while (aux != NULL) {
        aux = aux->prox;
        tam++;
    }
    return tam;
}



#endif