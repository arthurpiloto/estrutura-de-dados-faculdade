/*
+----------------- File: fila_prioridade_heap.h ----------+
| Fila de Prioridade com Heap Binária                   |
|					      		                        |
|					      		                        |
| Implementado por Arthur Piloto Silva em 30/05/2025    |
+-------------------------------------------------------+
*/

#ifndef FPHEAP_H
#define FPHEAP_H
#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int info, prio;
} NO;

NO* alocarNO() {
    return ((NO*)malloc(sizeof(NO)));
}

void liberarNO(NO *q) {
    free(q);
}

void trocaNO(NO* a, NO* b) {
    NO temp;
    temp.info = a->info;
    temp.prio = a->prio;
    a->info = b->info;
    a->prio = b->prio;
    b->info = temp.info;
    b->prio = temp.prio;
}

typedef struct {
    int qtd;
    NO dados[MAX];
} FilaP;

FilaP* criaFila() {
    FilaP *fp = (FilaP*)malloc(sizeof(FilaP));
    if (fp != NULL) fp->qtd = 0;
    return fp;
}

int estaVazia(FilaP *fp) {
    return (fp->qtd == 0);
}

int estaCheia(FilaP *fp) {
    return (fp->qtd == MAX);
}

int tamanhoFila(FilaP *fp) {
    return (fp->qtd);
}

void ajustaHeapInsere(FilaP* fp, int filho) {
    NO temp;
    int pai = (filho-1)/2;
    int prioPai = fp->dados[pai].prio;
    int prioFilho = fp->dados[filho].prio;
    while (filho > 0 && prioPai < prioFilho) {
        trocaNO(&fp->dados[filho], &fp->dados[pai]);
        filho = pai;
        pai = (pai-1)/2;
        prioPai = fp->dados[pai].prio;
        prioFilho = fp->dados[filho].prio;
    }
}

int inserePrio(FilaP *fp, int elem, int prio) {
    if (fp == NULL || estaCheia(fp)) return 0;
    fp->dados[fp->qtd].info = elem;
    fp->dados[fp->qtd].prio = prio;
    ajustaHeapInsere(fp, fp->qtd);
    fp->qtd++;
    return 1;
}

void ajustaHeapRemove(FilaP* fp, int pai) {
    NO temp;
    int filho = 2*pai + 1;
    while(filho < fp->qtd) { 
        if (filho < fp->qtd-1) {
            if(fp->dados[filho].prio < fp->dados[filho+1].prio) filho++;
        }
        if (fp->dados[pai].prio > fp->dados[filho].prio) break;
        trocaNO(&fp->dados[pai], &fp->dados[filho]);
        pai = filho;
        filho = 2*pai + 1;
    }
}

int removePrio(FilaP *fp, int *info, int *prio) {
    if (fp == NULL || estaVazia(fp)) return 0;
    fp->qtd--;
    *info = fp->dados[0].info;
    *prio = fp->dados[0].prio;
    fp->dados[0].info = fp->dados[fp->qtd].info;
    fp->dados[0].prio = fp->dados[fp->qtd].prio;
    ajustaHeapRemove(fp, 0);
    return 1;
}

void imprime(FilaP *fp) {
    if (fp == NULL || estaVazia(fp)) return;
    printf("Elementos:\n");
    for (int i = 0; i < fp->qtd; i++) printf("Elemento: %d, Prioridade: %d\n", fp->dados[i].info, fp->dados[i].prio);
    printf("\n");
}

void destroiFila(FilaP *fp) {
    if (fp != NULL) free(fp);
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