#ifndef LSE_ALUNO_H
#define LSE_ALUNO_H
#define MAX_NOME 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    float nota;
} Aluno;

typedef struct NO {
    Aluno* info;
    struct NO* prox;
} NO;

typedef struct NO* Lista;

Lista* criaLista() {
    Lista *li;
    li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL) *li = NULL;
    return li;
}

Aluno* criaAluno(char nome[], int matricula, float nota) {
    Aluno *a = (Aluno*)malloc(sizeof(Aluno));
    if (a != NULL) {
        strcpy(a->nome, nome);
        a->matricula = matricula;
        a->nota = nota;
    }
    return a;
}

int listaVazia(Lista *li) {
    if (li == NULL) return -1;
    return (*li == NULL);
}

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

int insereAluno(Lista *li, Aluno *a) {
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = a;
    novo->prox = NULL;
    NO **aux = li;
    while (*aux != NULL && strcmp((*aux)->info->nome, a->nome) < 0) aux = &(*aux)->prox;
    novo->prox = *aux;
    *aux = novo;
    return 1;
}

int removeAluno(Lista *li, int matricula) {
    if (li == NULL) return 0;
    if (listaVazia(li)) return 0;
    NO **aux = li;
    while (*aux != NULL && (*aux)->info->matricula != matricula) {
        aux = &(*aux)->prox;
    }
    if (*aux == NULL) return 0;
    NO *removerNO = *aux;
    *aux = removerNO->prox;
    free(removerNO->info);
    free(removerNO);
    return 1;
}

void imprimeLista(Lista *li) {
    if (li == NULL) return;
    if (listaVazia(li)) {
        printf("Lista Vazia!\n");
        return;
    }
    NO *aux = *li;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->info->nome);
        printf("Matrícula: %d\n", aux->info->matricula);
        printf("Nota: %.2f\n", aux->info->nota);
        aux = aux->prox;
        printf("\n");
    }
}

void destroiLista(Lista *li) {
    if (li != NULL) {
        NO *aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            free(aux->info);
            free(aux);
        }
        free(li);
    }
}


#endif
