/*
+----------------- File: matriz.h -----------------------+
| Matriz Estatica                                       |
|					      		                        |
|					      		                        |
| Implementado por Arthur Piloto Silva em 02/06/2025    |
+-------------------------------------------------------+
*/
#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct{
    int dados[MAX][MAX];
    int lin, col;
} Matriz;

void zeraMatriz(Matriz* m) {
    for (int i = 0; i < m->lin; i++) {
        for (int j = 0; j < m->col; j++) m->dados[i][j] = 0; 
    }
}

Matriz* criaMatriz(int l, int c) {
    Matriz* m = (Matriz*) malloc (sizeof(Matriz));
    if (m != NULL) {
        if (l <= 0 || c <= 0 || l > MAX || c > MAX) {
            printf("Valores invalidos, matriz nao criada!\n");
            return NULL;
        }
        m->lin = l;
        m->col = c;
        zeraMatriz(m);
    }
    return m;
}

void destroiMatriz(Matriz* m) {
    if (m != NULL) free(m);
}

int preencheAleatorio(Matriz* m, int ini, int fim) {
    if (m == NULL) return 0;
    srand(time(NULL));
    for (int i = 0; i < m->lin; i++) {
        for (int j = 0; j < m->col; j++) m->dados[i][j] = ini + rand() % (fim-ini + 1);
    }
    return 1;
}

int insereElem(Matriz* m, int elem, int l, int c) {
    if (m == NULL) return 0;
    if (l < 0 || c < 0 || l >= m->lin || c >= m->col) {
        printf("Valores invalidos, elem nao inserido!\n");
        return 0;
    }
    m->dados[l][c] = elem;
    return 1;
}

int consultaElem(Matriz* m, int *p, int l, int c) {
    if (m == NULL) return 0;
    if (l < 0 || c < 0 || l >= m->lin || c >= m->col) {
        printf("Valores invalidos, elem nao existe!\n");
        return 0;
    }
    *p = m->dados[l][c];
    return 1;
}

void imprime(Matriz* m) {
    if (m == NULL) return;
    printf("Matriz %d x %d:\n", m->lin, m->col);
    for (int i = 0; i < m->lin; i++) {
        for (int j = 0; j < m->col; j++) printf("\t%d", m->dados[i][j]);
        printf("\n");
    }
    printf("\n");
}

int e_matrizQuadrada(Matriz *m) {
    if (m == NULL) return 0;
    return (m->lin == m->col);
}

Matriz* criaTriangularSup(Matriz* m) {
    if (m == NULL) return NULL;
    if (!e_matrizQuadrada(m)) {
        printf("Matriz nao Quadrada!\n");
        return NULL;
    }
    Matriz* ts = criaMatriz(m->lin, m->col);
    for (int i = 0; i < m->lin; i++) {
        for (int j = 0; j < m->col; j++) {
            if (i <= j) ts->dados[i][j] = m->dados[i][j];
        }
    }
    return ts;
}

Matriz* criaTriangularInf(Matriz* m) {
    if (m == NULL) return NULL;
    if (!e_matrizQuadrada(m)) {
        printf("Matriz nao Quadrada!\n");
        return NULL;
    }
    Matriz* ti = criaMatriz(m->lin, m->col);
    for (int i = 0; i < m->lin; i++) {
        for (int j = 0; j < m->col; j++) {
            if (i >= j) ti->dados[i][j] = m->dados[i][j];
        }
    }
    return ti;
}

Matriz* criaDiagonal(Matriz* m) {
    if (m == NULL) return NULL;
    if (!e_matrizQuadrada(m)) {
        printf("Matriz nao Quadrada!\n");
        return NULL;
    }
    Matriz* d = criaMatriz(m->lin, m->col);
    for (int i = 0; i < m->lin; i++) d->dados[i][i] = m->dados[i][i];
    return d;
}

int e_Simetrica(Matriz* m) {
    if (m == NULL) return 0;
    if (!e_matrizQuadrada(m)) {
        printf("Matriz nao Quadrada!\n");
        return 0;
    }
    for (int i = 0; i < m->lin; i++) {
        for (int j = i+1; j < m->col; j++) {
            if (m->dados[i][j] != m->dados[j][i]) return 0;
        }
    }
    return 1;
}

Matriz* criaTransposta(Matriz* m) {
    if (m == NULL) return NULL;
    Matriz* t = criaMatriz(m->col, m->lin);
    for (int i = 0; i < m->lin; i++) {
        for(int j = 0; j < m->col; j++) t->dados[j][i] = m->dados[i][j];
    }
    return t;
}

Matriz* somaMatriz(Matriz* m1, Matriz* m2) {
    if (m1 == NULL || m2 == NULL) return NULL;
    if (m1->lin != m2->lin || m1->col != m2->col) {
        printf("Dimensoes incompativeis para soma!\n");
        return NULL;
    }
    Matriz* result = criaMatriz(m1->lin, m1->col);
    if (result != NULL) {
        for (int i = 0; i < m1->lin; i++) {
            for (int j = 0; j < m1->col; j++) {
                result->dados[i][j] = m1->dados[i][j] + m2->dados[i][j];
            }
        }
    }
    return result;
}

Matriz* subtraiMatriz(Matriz* m1, Matriz* m2) {
    if (m1 == NULL || m2 == NULL) return NULL;
    if (m1->lin != m2->lin || m1->col != m2->col) {
        printf("Dimensoes incompativeis para subtracao!\n");
        return NULL;
    }

    Matriz* result = criaMatriz(m1->lin, m1->col);
    if (result != NULL) {
        for (int i = 0; i < m1->lin; i++) {
            for (int j = 0; j < m1->col; j++) {
                result->dados[i][j] = m1->dados[i][j] - m2->dados[i][j];
            }
        }
    }
    return result;
}

Matriz* multiplicaMatriz(Matriz* m1, Matriz* m2) {
    if (m1 == NULL || m2 == NULL) return NULL;
    if (m1->col != m2->lin) {
        printf("Dimensoes incompativeis para multiplicacao!\n");
        return NULL;
    }

    Matriz* result = criaMatriz(m1->lin, m2->col);
    if (result != NULL) {
        for (int i = 0; i < m1->lin; i++) {
            for (int j = 0; j < m2->col; j++) {
                int sum = 0;
                for (int k = 0; k < m1->col; k++) {
                    sum += m1->dados[i][k] * m2->dados[k][j];
                }
                result->dados[i][j] = sum;
            }
        }
    }
    return result;
}
#endif