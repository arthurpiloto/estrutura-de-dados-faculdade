#include <stdio.h>
#include "abp.h"

int main() {
    ABP* minhaABP = criaABP();
    int opcao, elemento;

    do {
        printf("\n--- Menu ABP ---\n");
        printf("1- Criar ABP\n");
        printf("2- Inserir um elemento\n");
        printf("3- Buscar um elemento\n");
        printf("4- Remover um elemento\n");
        printf("5- Imprimir a ABP em ordem\n");
        printf("6- Imprimir a ABP em pré-ordem\n");
        printf("7- Imprimir a ABP em pós-ordem\n");
        printf("8- Mostrar a quantidade de nós na ABP\n");
        printf("9- Mostra todos os caminhos de nós folha até a raiz\n");
        printf("10- Destruir a ABP\n");
        printf("11- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (minhaABP != NULL) {
                    destroiABP(minhaABP);
                }
                minhaABP = criaABP();
                if (minhaABP != NULL) {
                    printf("ABP criada/recriada com sucesso.\n");
                } else {
                    printf("Erro ao criar ABP.\n");
                }
                break;
            case 2:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                if (insereElem(minhaABP, elemento)) {
                    printf("Elemento %d inserido com sucesso.\n", elemento);
                } else {
                    printf("Falha ao inserir elemento ou elemento já existe.\n");
                }
                break;
            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &elemento);
                if (pesquisa(minhaABP, elemento)) {
                    printf("Elemento %d encontrado na ABP.\n", elemento);
                } else {
                    printf("Elemento %d não encontrado na ABP.\n", elemento);
                }
                break;
            case 4:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                if (removeElem(minhaABP, elemento)) {
                    printf("Elemento %d removido com sucesso.\n", elemento);
                } else {
                    printf("Falha ao remover elemento ou elemento inexistente.\n");
                }
                break;
            case 5:
                imprime(minhaABP);
                break;
            case 6: // Para pré-ordem, reuse imprime ou chame diretamente
                printf("\nPre Ordem: ");
                if (minhaABP != NULL && *minhaABP != NULL) {
                    pre_ordem(*minhaABP, 0);
                } else {
                    printf("Arvore Vazia!\n");
                }
                printf("\n");
                break;
            case 7: // Para pós-ordem, reuse imprime ou chame diretamente
                printf("\nPos Ordem: ");
                if (minhaABP != NULL && *minhaABP != NULL) {
                    pos_ordem(*minhaABP, 0);
                } else {
                    printf("Arvore Vazia!\n");
                }
                printf("\n");
                break;
            case 8:
                if (minhaABP != NULL && *minhaABP != NULL) {
                    printf("Quantidade de nós na ABP: %d\n", contaNos(*minhaABP));
                } else {
                    printf("Arvore Vazia! Quantidade de nós: 0\n");
                }
                break;
            case 9:
                mostraTodosCaminhosFolhaRaiz(minhaABP);
                break;
            case 10:
                destroiABP(minhaABP);
                minhaABP = NULL;
                printf("ABP destruída com sucesso.\n");
                break;
            case 11:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 11);

    if (minhaABP != NULL) { // Garante que a ABP é destruída ao sair
        destroiABP(minhaABP);
    }

    return 0;
}