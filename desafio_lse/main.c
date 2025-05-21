#include <stdio.h>
#include "lse.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 40);
    insereFim(L, 50);
    insereFim(L, 60);
    insereFim(L, 70);
    insereFim(L, 80);
    insereFim(L, 90);

    imprimeLista(L);
    imprimeRev(L);
    printf("Elementos REV REC:\n");
    imprimeRevRec(L);
    printf("\n");

    destroiLista(L);
    return 0;
}