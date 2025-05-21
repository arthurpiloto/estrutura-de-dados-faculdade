#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"
// #include "pilha_dinamica.h" // funcionando da mesma maneira que a estatica, descomentar para teste

int main() {
    Pilha *p = criaPilha();
    empilhar(p, 1);
    empilhar(p, 2);
    empilhar(p, 3);
    empilhar(p, 4);
    empilhar(p, 5);
    empilhar(p, 6);
    imprimePilha(p);
    int valor = 0;
    if (desempilhar(p, &valor)) printf("Elemento %d desempilhado com sucesso\n", valor);
    imprimePilha(p);
    printf("Invertendo pilha...\n");
    invertePilha(p);
    imprimePilha(p);
    destroiPilha(p);
    return 0;
}