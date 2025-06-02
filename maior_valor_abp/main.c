#include <stdio.h>
#include "abp.h"

int main(){

    ABP* A;
    A = criaABP();
    
    insereElem(A, 2);
    insereElem(A, 5);
    insereElem(A, 14);
    insereElem(A, 10);
    insereElem(A, 6);
    insereElem(A, 4);
    insereElem(A, 1);
    insereElem(A, 12);
    insereElem(A, 20);

    imprime(A);

    removeElem(A, 10);
    imprime(A);

    printf("Maior valor na ABP: %d\n", maiorValorABP(A));

    destroiABP(A);
    return 0;
}