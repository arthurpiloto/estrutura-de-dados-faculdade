#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H
#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int qtd, ini, fim;
    int dados[MAX];
} Fila;

Fila* criaFila() {
    Fila *fi;
    fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL) fi->qtd = fi->ini = fi->fim = 0;
    return fi;
}

void destroiFila(Fila *fi) {
    if (fi != NULL) free(fi);
}

int estaCheia(Fila *fi) {
    if (fi == NULL) return -1;
    return (fi->qtd == MAX);
}

int estaVazia(Fila *fi) {
    if (fi == NULL) return -1;
    return (fi->qtd == 0);
}

int tamanhoFila(Fila *fi) {
    if (fi == NULL) return -1;
    return fi->qtd;
}

int enfileirar(Fila *fi, int elem) {
    if (fi == NULL) return 0;
    if (estaCheia(fi)) return 0;
    fi->dados[fi->fim] = elem;
    fi->fim = (fi->fim+1) % MAX;
    fi->qtd++;
    return 1;
}

int desenfileirar(Fila *fi, int *p) {
    if (fi == NULL) return 0;
    if (estaVazia(fi)) return 0;
    *p = fi->dados[fi->ini];
    fi->ini = (fi->ini+1) % MAX;
    fi->qtd--;
    return 1;
}

void imprimeFila(Fila *fi) {
    if (fi == NULL) return;
    if (estaVazia(fi)) {
        printf("Fila vazia\n");
        return;
    }
    int i = fi->ini;
    printf("Elementos:\n");
    do {
        printf("%d ", fi->dados[i]);
        i = (i+1) % MAX;
    } while (i != fi->fim);
    printf("\n");
}

void inverteFila(Fila *fi) {
    if (fi == NULL) return;
    if (estaVazia(fi)) return;
    int i = fi->ini;
    int j = fi->fim-1;
    do {
        int aux = fi->dados[j];
        fi->dados[j] = fi->dados[i];
        fi->dados[i] = aux;
        i = (i+1) % MAX;
        j = (j-1) % MAX;
    } while (i != j);
}


#endif