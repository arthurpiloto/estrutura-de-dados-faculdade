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

int inserePrio(FilaP *fp, int elem, int prio) {
    NO *novo = alocarNO();
    if (fp == NULL || novo == NULL) return 0;
    novo->info = elem;
    novo->prio = prio;
    if (estaVazia(fp)) {
        novo->prox = *fp;
        *fp = novo; 
    } else {
        NO *aux = *fp, *ant = NULL;
        while (aux != NULL && aux->prio >= novo->prio) {
            ant = aux;
            aux = aux->prox;
        }
        if (ant == NULL) {
            novo->prox = *fp;
            *fp = novo;
        } else {
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
    return 1;
}

int removePrio(FilaP *fp, int *info, int *prio) {
    if (fp == NULL || estaVazia(fp)) return 0;
    *info = (*fp)->info;
    *prio = (*fp)->prio;
    NO *aux = *fp;
    *fp = aux->prox;
    liberarNO(aux);
    return 1;
}

void imprime(FilaP *fp) {
    if (fp == NULL || estaVazia(fp)) return;
    NO *aux = *fp;
    while (aux != NULL) {
        printf("Elemento: %d, Prioridade: %d\n", aux->info, aux->prio);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiFila(FilaP *fp) {
    if (fp != NULL) {
        NO *aux;
        while ((*fp) != NULL) {
            aux = *fp;
            *fp = (*fp)->prox;
            liberarNO(aux);
        }
        free(fp);
    }
}

int uneFilas(FilaP *f1, FilaP *f2) {
    if (f1 == NULL || f2 == NULL) return 0;
    int elem, prio;
    while (!estaVazia(f2)) {
        removePrio(f2, &elem, &prio);
        inserePrio(f1, elem, prio);
    }
    return 1;
}

#endif