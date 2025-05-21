#ifndef FRACOES_H
#define FRACOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerador, denominador;
} Fracao;

Fracao* criaFracao(int numerador, int denominador) {
    Fracao *f;
    f = (Fracao*)malloc(sizeof(Fracao));

    if (f != NULL) {
        if (denominador != 0) {
            f->numerador = numerador;
            f->denominador = denominador;
        }
    }

    return f;
}

void liberaFracao(Fracao* f) {
    free(f);
}

int fracaoMdc(Fracao* f1, Fracao* f2) {
    int a = f1->denominador;
    int b = f2->denominador;
    
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int fracaoMmc(Fracao* f1, Fracao* f2) {
    int a = f1->denominador;
    int b = f2->denominador;
    return a * (b / fracaoMdc(f1, f2));
}

void imprimeFracao(Fracao* f) {
    printf("%d/%d", f->numerador, f->denominador);
}

Fracao* somaFracoes(Fracao* f1, Fracao* f2) {
    if (f1 == NULL || f2 == NULL) return 0;
    Fracao *f3 = criaFracao(0, 0);

    if (f1->denominador == f2->denominador) {
        f3->numerador = f1->numerador + f2->numerador;
        f3->denominador = f1->denominador;
    } else {
        f3->denominador = fracaoMmc(f1, f2);

        int nDenominadorf1 = f3->denominador  / f1->denominador;
        int nNumeradorf1 = nDenominadorf1 * f1->numerador;
        int nDenominadorf2 = f3->denominador  / f2->denominador;
        int nNumeradorf2 = nDenominadorf2 * f2->numerador;

        f3->numerador = nNumeradorf1 + nNumeradorf2;
    }

    return f3;
}

Fracao* subtraiFracoes(Fracao* f1, Fracao* f2) {
    if (f1 == NULL || f2 == NULL) return 0;
    Fracao *f3 = criaFracao(0, 0);

    if (f1->denominador == f2->denominador) {
        f3->numerador = f1->numerador + f2->numerador;
        f3->denominador = f1->denominador;
    } else {
        f3->denominador = fracaoMmc(f1, f2);

        int nDenominadorf1 = f3->denominador  / f1->denominador;
        int nNumeradorf1 = nDenominadorf1 * f1->numerador;
        int nDenominadorf2 = f3->denominador  / f2->denominador;
        int nNumeradorf2 = nDenominadorf2 * f2->numerador;

        f3->numerador = nNumeradorf1 - nNumeradorf2;
    }

    return f3;
}

Fracao* multiplicaFracoes(Fracao* f1, Fracao* f2) {
    if (f1 == NULL || f2 == NULL) return 0;
    Fracao *f3 = criaFracao(0, 0);

    f3->numerador = f1->numerador * f2->numerador;
    f3->denominador = f1->denominador * f2->denominador;

    return f3;
}

Fracao* divideFracoes(Fracao* f1, Fracao* f2) {
    if (f1 == NULL || f2 == NULL) return 0;
    Fracao *f3 = criaFracao(0, 0);

    f3->numerador = f1->numerador * f2->denominador;
    f3->denominador = f1->denominador * f2->numerador;

    return f3;
}

int simplificaFracao(Fracao* f) {
    if (f == NULL) return 0;
    int i, maior = 0;
    if (f->numerador > f->denominador) maior = f->numerador;
    else maior = f->denominador;
    
    for (i = 2; i < maior; i++) {
        if (f->numerador % i == 0 && f->denominador % i == 0) {
            f->numerador = f->numerador / i;
            f->denominador = f->denominador / i;
            i = 1;
        }
    }

    return 1;
}

float mostraDecimal(Fracao* f) {
    if (f == NULL) return 0;
    float result = f->numerador / (float)f->denominador;
    return result;
}


#endif
