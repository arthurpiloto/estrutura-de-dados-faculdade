#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade_se.h"

int main() {
    FilaP *f1 = criaFila();
    FilaP *f2 = criaFila();
    inserePrio(f1, 10, 5);
    inserePrio(f1, 20, 3);
    inserePrio(f1, 30, 8);
    inserePrio(f2, 15, 2);
    inserePrio(f2, 25, 7);
    inserePrio(f2, 35, 4);
    printf("Fila 1:\n");imprime(f1);
    printf("Fila 2:\n");imprime(f2);
    printf("Unindo filas...\n");uneFilas(f1, f2);
    printf("\nFila 1:\n");imprime(f1);
    printf("Fila 2:\n");imprime(f2);
    destroiFila(f1);
    destroiFila(f2);
    return 0;
}