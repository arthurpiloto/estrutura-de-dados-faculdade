#include <stdio.h>
#include "lse_aluno.h"

int main(){
    Lista *L = criaLista();
    insereAluno(L, criaAluno("Carlos", 1001, 8.2));
    insereAluno(L, criaAluno("Ana", 1002, 9.5));
    insereAluno(L, criaAluno("Daniel", 1004, 6.7));
    printf("Alunos:\n");
    imprimeLista(L);
    printf("Inserindo novo aluno...\n");
    insereAluno(L, criaAluno("Beatriz", 1003, 7.8));
    imprimeLista(L);
    printf("Removendo matrícula 1003...\n\n");
    removeAluno(L, 1003);
    printf("Alunos:\n");
    imprimeLista(L);
    destroiLista(L);
    return 0;
}