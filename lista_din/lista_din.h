#ifndef LSDIN_H
#define LSDIN_H
#define INCREMENTO 100;

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados, max, qtd;
} ListaDin;

ListaDin* criaLista(int max) {
    ListaDin *li = (ListaDin*)malloc(sizeof(ListaDin));

    if (li != NULL) {
        li->dados = (int*)malloc(max * sizeof(int));

        if (li->dados != NULL) {
            li->max = max;
            li->qtd = 0;
        }
    }

    return li;
}

void destroiLista(ListaDin *li) {
    if (li != NULL) {
        free(li->dados);
        free(li);
    }
}

int tamanhoLista(ListaDin *li) {
    if (li == NULL) return -1;
    return li->qtd;
}

int listaCheia(ListaDin *li){
    if(li == NULL) return -1;
    return (li->qtd == li->max);
}

int listaVazia(ListaDin *li){
    if(li == NULL) return -1;
    return (li->qtd == 0);
}

int realocaLista(ListaDin *li) {
    if (li == NULL) return -1;
    
    int novoMax = li->max + INCREMENTO;
    int *novoDados = (int*)malloc(novoMax * sizeof(int));
    
    if (novoDados == NULL) return -1;
    for (int i = 0; i < li->max; i++) novoDados[i] = li->dados[i];

    free(li->dados);
    li->max = novoMax;
    li->dados = novoDados;

    return 1;
}

int insereFim(ListaDin *li, int elem) {
    if (li == NULL) return 0;

    if (listaCheia(li)) realocaLista(li);
    else {
        li->dados[li->qtd] = elem;
        li->qtd++;
        return 1;
    }

    return 0;
}

int insereIni(ListaDin *li, int elem) {
    if (li == NULL) return 0;

    if (listaCheia(li)) realocaLista(li);
    else {
        for(int i = li->qtd; i > 0; i--) li->dados[i] = li->dados[i-1];
        li->dados[0] = elem;
        li->qtd++;
        return 1;
    }

    return 0;    
}

int imprimeLista(ListaDin *li){
    if (li == NULL) return 0;

    printf("Elementos:\n");
    for(int i = 0; i < li->qtd; i++) printf("%d ", li->dados[i]);
    printf("\n");

    return 1;
}

int removeFim(ListaDin *li){
    if(li == NULL) return 0;

    if (!listaVazia(li)) {
        li->qtd--;
        return 1;
    }

    return 0;
}

int removeIni(ListaDin *li){
    if (li == NULL ) return 0;

    if (!listaVazia(li)) {
        for(int i = 0; i < li->qtd - 1; i++) li->dados[i] = li->dados[i+1];
        li->qtd--;
        return 1;
    }

    return 0;
}

#endif