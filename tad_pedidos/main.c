#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

int main() {
    Pedido* pedido = criaPedido();
    int op, result, qtde;
    float preco;
    char nome[MAX_NOME];

    printf("=== Lista de Pedidos ===\n");
    printf("Status: %s\n", pedido->status);

    do {
        printf("\n01 - Adicionar Item\n");
        printf("02 - Remover Item\n");
        printf("03 - Listar Itens\n");
        printf("04 - Definir Endereço\n");
        printf("00 - Finalizar Pedido\n");
        
        while (1) {
            printf("Escolha a operação desejada: ");
            result = scanf("%d", &op);
    
            if (result != 1 || op < 0 || op > 4) {
                printf("Entrada inválida!\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            } else {
                break;
            }
        }

        switch (op) {
            case 01: {
                Item *a;
                a = criaItem();
                digitarItem(a);
                adicionarItem(*a, pedido);
                break;
            }
    
            case 02: {
                int item;
                do {
                    if (pedido->numItens == 0) {
                        printf("\nNão há itens na lista de pedidos\n");
                        break;
                    } else {
                        listaItens(pedido);
                        printf("0 - Sair\n");
                        printf("Escolha o item a ser removido: ");
                        scanf("%d", &item);
                        removerItem(pedido->itens[item-1], pedido);
                    }
                } while (item != 0);
                break;
            }

            case 03: {
                if (pedido->numItens == 0) {
                    printf("\nNão há itens na lista de pedidos\n");
                    break;
                } else listaItens(pedido);
                break;
            }

            case 04: {
                char ch, nome[MAX_NOME];

                if (strlen(pedido->endereco) == 0) {
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    printf("\nEndereço: ");
                    fgets(nome, MAX_NOME, stdin);
                    definirEndereco(pedido, nome);
                } else {
                    printf("\nUm endereço já está registrado: %s", pedido->endereco);
                    printf("Deseja mudar? [s/n]: ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &ch);

                    if (ch == 's') {
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        printf("\nEndereço: ");
                        fgets(nome, MAX_NOME, stdin);
                        definirEndereco(pedido, nome);
                    } else break;
                }
                break;
            }
        }

    } while (op != 0);
    
    alterarStatus(pedido, "Preparando");
    finalizarPedido(pedido);

    return 0;
}