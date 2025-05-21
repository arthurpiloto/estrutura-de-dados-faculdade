#ifndef LSE_H
#define LSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct NO* Lista;

Lista* criaLista() {
    Lista *li;
    li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL) *li = NULL;
    return li;
}

int listaVazia(Lista *li) {
    if (li == NULL) return -1;
    if (*li == NULL) return 1;
    return 0;
}

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO *q) {
    free(q);
}

int insereFim(Lista *li, int elem) {
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (listaVazia(li)) {
        *li = novo;
    } else {
        NO *aux = *li;
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}

void imprimeLista(Lista *li) {
    if (li == NULL) return;
    if (listaVazia(li)) {
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO *aux = *li;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimeRec(NO *n) {
    if(n == NULL) return;
    imprimeRec(n->prox);
    printf("%d ", n->info);
}

void imprimeRevRec(Lista *li) {
    if (li == NULL) return;
    if (listaVazia(li)) return;
    imprimeRevRec(&(*li)->prox);
    printf("%d ", (*li)->info);
}

void imprimeRev(Lista *li) {
    if (li == NULL) return;
    if (listaVazia(li)) {
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos REV:\n");
    NO *ant, *aux;
    NO *fim = NULL;
    do {
        aux = *li;
        while (aux != fim) {
            ant = aux;
            aux = aux->prox;
        }
        printf("%d ", ant->info);
        fim = ant;
    } while(fim != *li);
    printf("\n");
}

void destroiLista(Lista *li) {
    if (li != NULL) {
        NO *aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}


#endif
