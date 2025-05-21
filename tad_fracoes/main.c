#include <stdio.h>
#include <stdlib.h>
#include "fracoes.h"

int main() {
    int nA, nB, nC, dA, dB, dC, op, result;
    Fracao *A, *B, *C;

    printf("===== CALCULADORA DE FRAÇÕES =====\n");
    printf("Crie as duas frações desejadas para cálculo:\n");

    printf("\nFração 01\n");
    printf("Numerador: ");
    scanf("%d", &nA);
    printf("Denominador: ");
    scanf("%d", &dA);
    A = criaFracao(nA, dA);
    imprimeFracao(A);
    printf("\n");

    printf("\nFração 02\n");
    printf("Numerador: ");
    scanf("%d", &nB);
    printf("Denominador: ");
    scanf("%d", &dB);
    B = criaFracao(nB, dB);
    imprimeFracao(B);
    printf("\n");

    do {
        printf("\n===== OPERAÇÕES =====\n");
        printf("01 - Somar frações\n");
        printf("02 - Subtrair frações\n");
        printf("03 - Multiplicar frações\n");
        printf("04 - Dividir frações\n");
        printf("05 - Simplificar frações\n");
        printf("06 - Mostrar decimal\n");
        printf("00 - Sair\n");

        while (1) {
            printf("\nEscolha a operação desejada: ");
            result = scanf("%d", &op);

            if (result != 1 || op < 0 || op > 6) {
                printf("Entrada inválida!\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            } else {
                break;
            }
        }

        switch (op) {
            case 01: {
                C = somaFracoes(A, B);
                imprimeFracao(A);
                printf(" + ");
                imprimeFracao(B);
                printf(" = ");
                imprimeFracao(C);
                printf("\n");
                printf("\n");
                break;
            }

            case 02: {
                C = subtraiFracoes(A, B);
                imprimeFracao(A);
                printf(" - ");
                imprimeFracao(B);
                printf(" = ");
                imprimeFracao(C);
                printf("\n");
                break;
            }

            case 03: {
                C = multiplicaFracoes(A, B);
                imprimeFracao(A);
                printf(" x ");
                imprimeFracao(B);
                printf(" = ");
                imprimeFracao(C);
                printf("\n");
                break;
            }

            case 04: {
                C = divideFracoes(A, B);
                imprimeFracao(A);
                printf(" / ");
                imprimeFracao(B);
                printf(" = ");
                imprimeFracao(C);
                printf("\n");
                break;
            }

            case 05: {
                printf("Fração 01\n");
                imprimeFracao(A);
                printf(" = ");
                if (simplificaFracao(A)) {
                    imprimeFracao(A);
                    printf("\n");
                } else {
                    printf("Erro na simplificação\n");
                }
                
                printf("Fração 02\n");
                imprimeFracao(B);
                printf(" = ");
                if (simplificaFracao(B)) {
                    imprimeFracao(B);
                    printf("\n");
                } else {
                    printf("Erro na simplificação\n");
                }

                break;
            }

            case 06: {
                float decA, decB;
                decA = mostraDecimal(A);
                decB = mostraDecimal(B);

                printf("Fração 01\n");
                imprimeFracao(A);
                printf(" = %.2f\n", decA);

                printf("Fração 02\n");
                imprimeFracao(B);
                printf(" = %.2f\n", decB);
                
                break;
            }
        }

    } while (op != 0);

    return 0;
}
