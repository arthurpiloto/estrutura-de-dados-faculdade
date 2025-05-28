#include <stdio.h>
#include "deque.h"

int main() {
    Deque *dq = criaDeque();
    insereFim(dq, 'X');
    insereFim(dq, 'Y');
    insereFim(dq, 'Z');
    insereFim(dq, 'Y');
    insereFim(dq, 'X');
    imprime(dq);
    if (verificaSimetria(dq)) printf("É simétrico\n");
    else printf("Não é simétrico\n");
    destroiDeque(dq);
    return 0;
}