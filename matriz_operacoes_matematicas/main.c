#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz *m1 = criaMatriz(5, 5);
    Matriz *m2 = criaMatriz(5, 5);
    preencheAleatorio(m1, 10, 30);
    preencheAleatorio(m2, 0, 20);
    imprime(m1);
    imprime(m2);
    Matriz *m3 = somaMatriz(m1, m2);
    printf("Soma:\n");imprime(m3);
    m3 = subtraiMatriz(m1, m2);
    printf("Subtração:\n");imprime(m3);
    m3 = multiplicaMatriz(m1, m2);
    printf("Multiplicação:\n");imprime(m3);
    destroiMatriz(m1);
    destroiMatriz(m2);
    return 0;
}