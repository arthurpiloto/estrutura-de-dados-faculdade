#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"
// #include "fila_dinamica.h" // funcionando da mesma maneira que a estatica, descomentar para teste

int main() {
    Fila *f1 = criaFila();
    Fila *f2 = criaFila();
    enfileirar(f1, 1);
    enfileirar(f1, 2);
    enfileirar(f1, 3);
    enfileirar(f1, 4);
    enfileirar(f1, 5);
    enfileirar(f1, 6);
    printf("Fila 1\n");
    imprimeFila(f1);
    enfileirar(f2, 6);
    enfileirar(f2, 5);
    enfileirar(f2, 4);
    enfileirar(f2, 3);
    enfileirar(f2, 2);
    enfileirar(f2, 1);
    printf("Fila 2\n");
    imprimeFila(f2);
    printf("Concatenando Filas...\n");
    concatenaFilas(f1, f2);
    printf("Fila 1\n");
    imprimeFila(f1);
    printf("Fila 2\n");
    imprimeFila(f2);
    destroiFila(f1);
    destroiFila(f2);
    return 0;
}