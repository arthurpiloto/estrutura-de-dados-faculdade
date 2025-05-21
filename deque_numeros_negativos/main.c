#include <stdio.h>
#include "deque.h"

int main() {
    Deque *dq = criaDeque();
    insereFim(dq, 1);
    insereIni(dq, -1);
    insereFim(dq, 2);
    insereFim(dq, -9);
    insereFim(dq, 3);
    insereIni(dq, -15);
    insereFim(dq, 4);
    imprime(dq);
    printf("Removendo negativos...\n");removeNegativos(dq);
    imprime(dq);
    destroiDeque(dq);
    return 0;
}