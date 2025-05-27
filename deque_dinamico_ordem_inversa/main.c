#include <stdio.h>
#include "deque.h"

int main() {
    Deque *dq = criaDeque();
    insereFim(dq, 1);
    insereFim(dq, 2);
    insereFim(dq, 3);
    insereFim(dq, 4);
    insereFim(dq, 5);
    imprimeInverso(dq);
    destroiDeque(dq);
    return 0;
}