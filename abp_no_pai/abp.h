/*
+----------------- File: abp.h -------------------------+
| Árvore Binária de Pesquisa                            |
|					      		                        |
|					      		                        |
| Implementado por Arthur Piloto Silva em 02/06/2025    |
+-------------------------------------------------------+
*/
#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
    struct NO* pai;
}NO;

typedef struct NO* ABP;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

int insereRec(NO** raiz, int elem){
    int res;
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = elem;
        novo->esq = NULL; novo->dir = NULL; novo->pai = NULL;
        *raiz = novo;
    }else{
        if((*raiz)->info == elem){
            printf("Elemento Existente!\n"); 
            return 0;
        }
        if(elem < (*raiz)->info) {
            res = insereRec(&(*raiz)->esq, elem);
            if (res) (*raiz)->esq->pai = *raiz;
            return res;
        }
        else if(elem > (*raiz)->info) {
            res = insereRec(&(*raiz)->dir, elem);
            if (res) (*raiz)->dir->pai = *raiz;
            return res;
        }
    }
    return 1;
}

int insereElem(ABP* raiz, int elem){
    if(raiz == NULL) return 0;
    return insereRec(raiz, elem);
}

int pesquisaRec(NO** raiz, int elem){
    if(*raiz == NULL) return 0;
    if((*raiz)->info == elem) return 1;
    if(elem < (*raiz)->info)
        return pesquisaRec(&(*raiz)->esq, elem);
    else 
        return pesquisaRec(&(*raiz)->dir, elem);
}

int pesquisa(ABP* raiz, int elem){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, elem);
}

int removeRec(NO** raiz, int elem){
    if(*raiz == NULL) return 0;

    if(elem < (*raiz)->info){
        return removeRec(&(*raiz)->esq, elem);
    } else if (elem > (*raiz)->info){
        return removeRec(&(*raiz)->dir, elem);
    } else {
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            printf("Caso 1: Liberando %d..\n", (*raiz)->info);
            liberarNO(*raiz);
            *raiz = NULL;
        } else if((*raiz)->esq == NULL){
            printf("Caso 2.1: Liberando %d..\n", (*raiz)->info);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            if (*raiz != NULL) (*raiz)->pai = aux->pai;
            liberarNO(aux);
        } else if((*raiz)->dir == NULL){
            printf("Caso 2.2: Liberando %d..\n", (*raiz)->info);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            if (*raiz != NULL) (*raiz)->pai = aux->pai;
            liberarNO(aux);
        } else {
            printf("Caso 3: Liberando %d..\n", (*raiz)->info);
            NO* minRight = (*raiz)->dir;
            while(minRight->esq != NULL){
                minRight = minRight->esq;
            }
            (*raiz)->info = minRight->info;
            removeRec(&(*raiz)->dir, minRight->info);
        }
        return 1;
    }
}

NO* removeAtual(NO* atual){
    NO* no1, *no2;

    if(atual->esq == NULL){
        no2 = atual->dir;
        if (no2 != NULL) {
            no2->pai = atual->pai;
        }
        liberarNO(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual){
        no1->dir = no2->esq;
        if (no2->esq != NULL) {
            no2->esq->pai = no1;
        }
        no2->esq = atual->esq;
        if (atual->esq != NULL) {
            atual->esq->pai = no2;
        }
    }

    no2->pai = atual->pai;
    no2->dir = atual->dir;
    if (atual->dir != NULL) {
        atual->dir->pai = no2;
    }

    liberarNO(atual);
    return no2;
}

int removeElem(ABP* raiz, int elem){
    if(pesquisa(raiz, elem) == 0){
        printf("Elemento inexistente!\n");
        return 0;
    }
    return removeRec(raiz, elem);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%d, %d] ", raiz->info,nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        printf("[%d, %d] ", raiz->info,nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("[%d, %d] ", raiz->info,nivel);
    }
}

void imprime(ABP* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    printf("\nEm Ordem: "); em_ordem(*raiz, 0);
    printf("\nPre Ordem: "); pre_ordem(*raiz, 0);
    printf("\nPos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}

void imprimeCaminhoFolhaRaiz(NO* folha){
    if(folha == NULL) return;
    printf("Caminho: ");
    NO* atual = folha;
    while(atual != NULL){
        printf("%d", atual->info);
        if(atual->pai != NULL){
            printf(" <- ");
        }
        atual = atual->pai;
    }
    printf("\n");
}

void encontraFolhasEImprimeCaminhos(NO* raiz){
    if(raiz == NULL) return;

    if(raiz->esq == NULL && raiz->dir == NULL){
        imprimeCaminhoFolhaRaiz(raiz);
    } else {
        encontraFolhasEImprimeCaminhos(raiz->esq);
        encontraFolhasEImprimeCaminhos(raiz->dir);
    }
}

void mostraTodosCaminhosFolhaRaiz(ABP* raiz){
    if(raiz == NULL || *raiz == NULL){
        printf("Arvore Vazia!\n");
        return;
    }
    printf("\nCaminhos de nos folha ate a raiz:\n");
    encontraFolhasEImprimeCaminhos(*raiz);
}

int contaNos(NO* no) {
    if (no == NULL) {
        return 0;
    }
    return 1 + contaNos(no->esq) + contaNos(no->dir);
}

#endif