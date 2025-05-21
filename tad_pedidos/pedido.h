#ifndef PEDIDO_H
#define PEDIDO_H
#define MAX_TAM 100
#define MAX_NOME 50
#define MAX_STATUS 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tipoChave;

typedef struct {
    char nome[MAX_NOME];
    float preco;
    int qtde;
} Item;

typedef struct {
    Item itens[MAX_TAM];
    int numItens;
    float total;
    char endereco[MAX_TAM];
    char status[MAX_STATUS];
} Pedido;

Pedido* criaPedido() {
    Pedido* p = (Pedido*)malloc(sizeof(Pedido));
    
    if (p != NULL) {
        p->numItens = 0;
        p->total = 0;
        strcpy(p->status, "pendente");
    }

    return p;
}

void liberaPedido(Pedido *p) {
    free(p);
}

Item* criaItem() {
    Item *item;
    item = (Item*)malloc(sizeof(Item));

    return item;
}

void liberaItem(Item *item) {
    free(item);
}

void digitarItem(Item *item) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\nNome: ");
    if (fgets(item->nome, MAX_NOME, stdin) != NULL) {
        item->nome[strcspn(item->nome, "\n")] = '\0';
    } else {
        item->nome[0] = '\0';
    }

    printf("Preço: ");
    scanf("%f", &item->preco);

    printf("Quantidade: ");
    scanf("%d", &item->qtde);

    while ((ch = getchar()) != '\n' && ch != EOF);
}



int adicionarItem(Item item, Pedido* p) {
    if (p == NULL) return 0;
    if (p->numItens >= MAX_TAM) return 0;

    p->itens[p->numItens] = item;
    p->numItens++;
    p->total += item.preco * item.qtde;

    return 1;
}

int removerItem(Item item, Pedido* p) {
    if (p == NULL) return 0;

    for (int i = 0; i < p->numItens; i++) {
        if (strcmp(p->itens[i].nome, item.nome) == 0) {
            p->total -= item.preco * item.qtde;
            for (int j = i; j < p->numItens - 1; j++) {
                p->itens[j] = p->itens[j + 1];
            }
            p->numItens--;
            return 1;
        }
    }

    return 0;
}

void listaItens(Pedido *p) {
    printf("\n=== Itens ===\n");
    for (int i = 0; i < p->numItens; i++) {
        printf("%d - %s: %d x R$%.2f\n", i+1, p->itens[i].nome, p->itens[i].qtde, p->itens[i].preco);
    }

}

/*
float calularTotal(Pedido *p) {
    if (p == NULL) return 0;
    float total;
    for (int i = 0; i < p->numItens; i++) {
        total += p->itens[i].preco * p->itens[i].qtde;
    }
    return total;
}
*/

int definirEndereco(Pedido* p, char* endereco) {
    if (p == NULL) return 0;
    strcpy(p->endereco, endereco);
    return 1;
}

int alterarStatus(Pedido* p, char* novoStatus) {
    if (p == NULL) return 0;
    strcpy(p->status, novoStatus);
    return 1;
}

void finalizarPedido(Pedido* p) {
    printf("\n=== Pedido Finalizado ===\n");
    printf("Endereço de entrega: %s", p->endereco);
    printf("Status: %s\n", p->status);
    printf("Itens:\n");

    for (int i = 0; i < p->numItens; i++) {
        printf("%d - %s: %d x R$%.2f\n", i+1, p->itens[i].nome, p->itens[i].qtde, p->itens[i].preco);
    }

    printf("Total: R$%.2f\n", p->total);
    free(p);
}


#endif
