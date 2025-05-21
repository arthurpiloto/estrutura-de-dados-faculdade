#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H
#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

Pilha* criaPilha() {
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(Pilha));
    if (pi != NULL) pi->topo = 0;
    return pi;
}

void destroiPilha(Pilha *pi) {
    if (pi != NULL) free(pi);
}

int estaCheia(Pilha *pi) {
    if (pi == NULL) return -1;
    return (pi->topo == MAX);
}

int estaVazia(Pilha *pi) {
    if (pi == NULL) return -1;
    return (pi->topo == 0);
}

int tamanhoPilha(Pilha *pi) {
    if (pi == NULL) return -1;
    return pi->topo;
}

int empilhar(Pilha *pi, int elem) {
    if (pi == NULL || estaCheia(pi)) return 0;
    pi->dados[pi->topo] = elem;
    pi->topo++;
    return 1;
}

int desempilhar(Pilha *pi, int *p) {
    if (pi == NULL || estaVazia(pi)) return 0;
    pi->topo--;
    *p = pi->dados[pi->topo];
    return 1;
}

void imprimePilha(Pilha *pi) {
    if (pi == NULL) return;
    if (estaVazia(pi)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Elementos:\n");
    for (int i = pi->topo-1; i >= 0; i--) printf("%d ", pi->dados[i]);
    printf("\n");
}

void invertePilha(Pilha *pi) {
    if (pi == NULL || estaVazia(pi)) return;
    int tam = tamanhoPilha(pi);
    int aux[tam];
    int valor;
    int i = 0;
    while (!estaVazia(pi)) {
        desempilhar(pi, &valor);
        aux[i] = valor;
        i++; 
    }
    i = 0;
    while(i <= tam-1) {
        empilhar(pi, aux[i]);
        i++;
    }
}


#endif