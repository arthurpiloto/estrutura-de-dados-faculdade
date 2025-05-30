#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade_heap.h"

void exibeMenu() {
    printf("\n===== OPERAÇÕES =====\n");
    printf("01 - Criar Fila\n");
    printf("02 - Inserir um item pela prioridade\n");
    printf("03 - Ver o início da Fila\n");
    printf("04 - Remover um item\n");
    printf("05 - Imprimir a Fila\n");
    printf("06 - Mostrar o tamanho da Fila\n");
    printf("07 - Destruir a Fila\n");
    printf("08 - Sair\n");
}

int main() {
    FilaP *fp = NULL;
    int op, result, elem, prio, infoRemovido, prioRemovido;
    do {
        exibeMenu();
        while (1) {
            printf("\nEscolha a operação desejada: ");
            result = scanf("%d", &op);

            if (result != 1 || op < 0 || op > 8) {
                printf("Entrada inválida!\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            } else {
                break;
            }
        }

        switch (op) {
            case 01: {
                if (fp != NULL) {
                    printf("A fila já existe. Destrua-a antes de criar uma nova (Opção 7).\n");
                } else {
                    fp = criaFila();
                    if (fp != NULL) {
                        printf("Fila de prioridade criada com sucesso!\n");
                    } else {
                        printf("Erro ao criar a fila de prioridade.\n");
                    }
                }
                break;
            }

            case 02: {
                if (fp == NULL) printf("Por favor, crie a fila primeiro (Opção 1).\n");
                else if (estaCheia(fp)) printf("A fila esta cheia.\n");
                else {
                    printf("Elemento: "); scanf("%d", &elem);
                    printf("Prioridade: "); scanf("%d", &prio);
                    if (inserePrio(fp, elem, prio)) printf("Elemento, %d Prioridade: %d inserido com sucesso!\n", elem, prio);
                    else printf("Erro ao inserir elemento.\n");
                }
                break;
            }

            case 03: {
                if (fp == NULL) printf("Por favor, crie a fila primeiro (Opção 1).\n");
                else if (estaVazia(fp)) printf("A fila está vazia.\n");
                else printf("Elemento: %d, Prioridade: %d\n", fp->dados[0].info, fp->dados[0].prio);
                break;
            }

            case 04: {
                if (fp == NULL) printf("Por favor, crie a fila primeiro (Opção 1).\n");
                else if (estaVazia(fp)) printf("A fila está vazia.\n");
                else {
                    if (removePrio(fp, &infoRemovido, &prioRemovido)) {
                        printf("Elemento, %d Prioridade: %d removido com sucesso!\n", infoRemovido, prioRemovido);
                    } else printf("Erro ao remover elemento.\n");
                }
                break;
            }

            case 05: {
                if (fp == NULL) printf("Por favor, crie a fila primeiro (Opção 1).\n");
                else if (estaVazia(fp)) printf("A fila está vazia.\n");
                else imprime(fp);
                break;
            }

            case 06: {
                if (fp == NULL) printf("Por favor, crie a fila primeiro (Opção 1).\n");
                else printf("Tamanho atual da fila: %d\n", tamanhoFila(fp));
                break;
            }

            case 07: {
                if (fp == NULL) printf("Por favor, crie a fila primeiro (Opção 1).\n");
                else {
                    destroiFila(fp);
                    fp = NULL;
                    printf("Fila destruída com sucesso!\n");
                }
                break;
            }

            case 8: {
                if (fp != NULL) destroiFila(fp);
                printf("Saindo do programa. Até mais!\n");
                break;
            }
        }
    } while (op != 8);
    return 0;
}