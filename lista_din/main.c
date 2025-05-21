#include <stdio.h>
#include "lista_din.h"

int main(){
    ListaDin *L = criaLista(10);

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    imprimeLista(L);
    removeIni(L);
    imprimeLista(L);
    destroiLista(L);

    return 0;
}