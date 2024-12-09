#include "sentinela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void cadastrarBebida(Sentinela *sentinela)
{
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    nova->next = NULL;
    if (!nova)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    char codigoStr[10];
    printf("Código: ");
    fgets(codigoStr, sizeof(codigoStr), stdin);
    nova->codigo = strtol(codigoStr, NULL, 10);

    Bebida *atual = sentinela->head;
    while (atual)
    {
        if (atual->codigo == nova->codigo)
        {
            printf("Código já existe. Digite um novo código.\n");
            free(nova);
            return;
        }
        atual = atual->next;
    }

    char nome[100];
    char volumeStr[20];
    char precoStr[20];
    char quantidadeStr[20];
    char teorAlcoolicoStr[20];

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; 
    strncpy(nova->nome, nome, sizeof(nova->nome) - 1);
    nova->nome[sizeof(nova->nome) - 1] = '\0';

    printf("Volume: ");
    fgets(volumeStr, sizeof(volumeStr), stdin);
    nova->volume = strtof(volumeStr, NULL);

    printf("Preço: ");
    fgets(precoStr, sizeof(precoStr), stdin);
    nova->preco = strtof(precoStr, NULL);

    printf("Quantidade em estoque: ");
    fgets(quantidadeStr, sizeof(quantidadeStr), stdin);
    nova->quantidade = strtol(quantidadeStr, NULL, 10);

    printf("Teor alcoólico (0 = Não alcoólica, 1 = Alcoólica): ");
    fgets(teorAlcoolicoStr, sizeof(teorAlcoolicoStr), stdin);
    nova->teorAlcoolico = strtol(teorAlcoolicoStr, NULL, 10);

    if (sentinela->head == NULL)
    {
        sentinela->head = nova;
    }
    else
    {
        Bebida *ultimo = sentinela->head;
        while (ultimo->next != NULL)
        {
            ultimo = ultimo->next;
        }
        ultimo->next = nova;
    }
    printf("Bebida cadastrada com sucesso!\n");
}

void cadastrarCliente(Sentinela *sentinela)
{
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->next = NULL;

    char codigoStr[10];
    printf("Código do cliente: ");
    fgets(codigoStr, sizeof(codigoStr), stdin);
    novo->codigo = strtol(codigoStr, NULL, 10);

    // Checagem se o codigo digitado já existe
    Cliente *atual = sentinela->headCliente;
    while (atual)
    {
        if (atual->codigo == novo->codigo)
        {
            printf("Código já existe. Digite um novo código.\n");
            free(novo);
            return;
        }
        atual = atual->next;
    }

    char nome[100];
    char cpf[13];
    char idadeStr[10];
    char vendeFiadoStr[10];

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';

    printf("CPF do cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    strncpy(novo->cpf, cpf, sizeof(novo->cpf) - 1);
    novo->cpf[sizeof(novo->cpf) - 1] = '\0';

    printf("Idade do cliente: ");
    fgets(idadeStr, sizeof(idadeStr), stdin);
    novo->idade = strtol(idadeStr, NULL, 10);

    printf("Vende fiado (0 = Não, 1 = Sim): ");
    fgets(vendeFiadoStr, sizeof(vendeFiadoStr), stdin);
    novo->vendeFiado = strtol(vendeFiadoStr, NULL, 10);

    if (sentinela->headCliente == NULL)
    {
        sentinela->headCliente = novo;
    }
    else
    {
        Cliente *ultimo = sentinela->headCliente;
        while (ultimo->next != NULL)
        {
            ultimo = ultimo->next;
        }
        ultimo->next = novo;
    }
}
