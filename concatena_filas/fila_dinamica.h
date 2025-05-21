#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct {
    int qtd;
    NO *ini, *fim;
} Fila;

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO *q) {
    free(q);
}

Fila* criaFila() {
    Fila *fi;
    fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->qtd = 0;
        fi->ini = fi->fim = NULL;
    }
    return fi;
}

void destroiFila(Fila *fi) {
    if (fi != NULL) {
        NO *aux;
        while (fi->ini != NULL) {
            aux = fi->ini;
            fi->ini = fi->ini->prox;
            liberarNO(aux);
        }
        free(fi);
    }
}

int estaVazia(Fila *fi) {
    return (fi == NULL || fi->qtd == 0);
}

int tamanhoFila(Fila *fi) {
    if (fi == NULL) return -1;
    return fi->qtd;
}

int enfileirar(Fila *fi, int elem) {
    if (fi == NULL) return 0;
    NO *novo = alocarNO();
    if (novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (estaVazia(fi)) fi->ini = novo;
    else fi->fim->prox = novo;
    fi->fim = novo;
    fi->qtd++;
    return 1;
}

int desenfileirar(Fila *fi, int *p) {
    if (fi == NULL || estaVazia(fi)) return 0;
    NO *aux = fi->ini;
    *p = aux->info;
    fi->ini = aux->prox;
    if (fi->ini == NULL) fi->fim == NULL;
    free(aux);
    fi->qtd--;
    return 1;
}

void imprimeFila(Fila *fi) {
    if (fi == NULL) return;
    if (estaVazia(fi)) {
        printf("Fila vazia\n");
        return;
    }
    NO *aux = fi->ini;
    printf("Elementos:\n");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void concatenaFilas(Fila *f1, Fila *f2) {
    if (f1 == NULL || f2 == NULL || estaVazia(f2)) return;
    int valor;
    while (!estaVazia(f2)) {
        desenfileirar(f2, &valor);
        enfileirar(f1, valor);
    }
}

#endif