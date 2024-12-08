#include "sentinela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void cadastrarBebida(Sentinela *sentinela) {
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    nova->next = NULL;
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    printf("Código: ");
    scanf("%d", &nova->codigo);

    Bebida *atual = sentinela->head;
    while (atual) {
        if (atual->codigo == nova->codigo) {
            printf("Código já existe. Digite um novo código.\n");
            free(nova);
            return;
        }
        atual = atual->next;
    }

    printf("Nome: ");
    scanf("%s", nova->nome);

    printf("Volume: ");
    scanf("%f", &nova->volume);

    printf("Preço: ");
    scanf("%f", &nova->preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &nova->quantidade);

    printf("Teor alcoólico (0 = Não alcoólica, 1 = Alcoólica): ");
    scanf("%d", &nova->teorAlcoolico);


    if (sentinela->head == NULL) {
        sentinela->head = nova;
    } else {
        Bebida *ultimo = sentinela->head;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = nova;
    }
    printf("Bebida cadastrada com sucesso!\n");
}

void cadastrarCliente(Sentinela *sentinela) {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->next = NULL;
    printf("Código do cliente: ");
    scanf("%d", &novo->codigo);

    // Checagem se o codigo digitado já existe
    Cliente *atual = sentinela->headCliente;
    while (atual) {
        if (atual->codigo == novo->codigo) {
            printf("Código já existe. Digite um novo código.\n");
            free(novo);
            return;
        }
        atual = atual->next;
    }

    printf("Nome: ");
    scanf("%s", novo->nome);
    printf("CPF do cliente: ");
    scanf("%12s", novo->cpf);

    printf("Idade do cliente: ");
    scanf("%d", &novo->idade);

    printf("Vende fiado (0 = Não, 1 = Sim): ");
    scanf("%d", &novo->vendeFiado);

    if (sentinela->headCliente == NULL) {
        sentinela->headCliente = novo;
    } else {
        Cliente *ultimo = sentinela->headCliente;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = novo;
    }
}
