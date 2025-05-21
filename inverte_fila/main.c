#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"
// #include "fila_dinamica.h" // funcionando da mesma maneira que a estatica, descomentar para teste

int main() {
    Fila *f = criaFila();
    enfileirar(f, 1);
    enfileirar(f, 2);
    enfileirar(f, 3);
    enfileirar(f, 4);
    enfileirar(f, 5);
    enfileirar(f, 6);
    imprimeFila(f);
    int p = 0;
    if (desenfileirar(f, &p)) printf("Elemento %d desenfileirado com sucesso\n", p);
    imprimeFila(f);
    printf("Invertendo fila...\n");
    inverteFila(f);
    imprimeFila(f);
    destroiFila(f);
    return 0;
}