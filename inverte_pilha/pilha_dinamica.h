#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct {
    int qtd;
    NO *topo;
} Pilha;

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO *q) {
    free(q);
}

Pilha* criaPilha() {
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(Pilha));
    if (pi != NULL) pi->topo = NULL;
    return pi;
}

void destroiPilha(Pilha *pi) {
    if (pi != NULL) {
        NO *aux = pi->topo;
        while (aux != NULL) {
            pi->topo = pi->topo->prox;
            liberarNO(aux);
            aux = pi->topo;
        }
    }
}

int estaVazia(Pilha *pi) {
    return (pi == NULL || pi->topo == NULL);
}

int empilhar(Pilha *pi, int elem) {
    if (pi == NULL) return 0;
    NO *novo = alocarNO();
    if (novo == NULL) return 0;
    novo->info = elem;
    novo->prox = pi->topo;
    pi->topo = novo;
    pi->qtd++;
    return 1;
}

int desempilhar(Pilha *pi, int *p) {
    if (pi == NULL || pi->topo == NULL) return 0;
    NO* aux = pi->topo;
    *p = aux->info;
    pi->topo = aux->prox;
    free(aux);
    pi->qtd--;
    return 1;
}

void imprimePilha(Pilha *pi) {
    if (pi == NULL) return;
    if (estaVazia(pi)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Elementos:\n");
    NO *aux = pi->topo;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void invertePilha(Pilha *pi) {
    if (pi == NULL || estaVazia(pi)) return;
    Pilha *aux1 = criaPilha();
    Pilha *aux2 = criaPilha();
    int valor;
    while (!estaVazia(pi)) {
        desempilhar(pi, &valor);
        empilhar(aux1, valor);
    }
    while (!estaVazia(aux1)) {
        desempilhar(aux1, &valor);
        empilhar(aux2, valor);
    }
    while (!estaVazia(aux2)) {
        desempilhar(aux2, &valor);
        empilhar(pi, valor);
    }
    destroiPilha(aux1);
    destroiPilha(aux2);
}


#endif