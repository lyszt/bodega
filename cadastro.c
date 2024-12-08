#include "sentinela.h"


void cadastrarBebida(Sentinela *sentinela) {
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    nova->next = NULL;
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    while(nova->codigo <= 0){
        scanf("Código: %d", &nova->codigo);
    }
    Bebida *atual = sentinela->head;
    while (atual) {
        if (atual->codigo == nova->codigo) {
            printf("Código já existe. Digite um novo código.\n");
            free(nova);
            return;
        }
        atual = atual->next;
    }

    int is_valid = false;
    while(!is_valid){
        scanf("Nome: %s", nova->nome);
        for(int i = 0; i < strlen(nova->nome); i++ ){
            if ((nova->nome[i] >= 65 && nova->nome[i] <= 90) || (nova->nome[i] >= 97 && nova->nome[i] <= 122))
             {
              is_valid = true;
             }
             else if(strlen(nova->nome) == i){
                break;
             }
        }
    }
    while(nova->volume <= 0){
        scanf("Volume: %f", &nova->volume);
    }
    while(nova->preco <= 0){
        scanf("Preço: %f", &nova->preco);
    }
    while(nova->quantidade <= 0){
        scanf("Quantidade em estoque: %d", &nova->quantidade);
    }
    while(nova->teorAlcoolico != 1 && nova->teorAlcoolico != 0){
        scanf("Teor alcoólico (0 = Não alcoólica, 1 = Alcoólica): %d", &nova->teorAlcoolico);
    }

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
    scanf("Código do cliente: %d", &novo->codigo);

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

    int is_valid = false;
    while(!is_valid){
        scanf("Nome: %s", novo->nome);
        for(int i = 0; i < strlen(novo->nome); i++ ){
            if ((novo->nome[i] >= 65 && novo->nome[i] <= 90) || (novo->nome[i] >= 97 && novo->nome[i] <= 122))
            {
                is_valid = true;
            }
            else if(strlen(novo->nome) == i){
                break;
            }
        }
    }
    scanf("CPF do cliente: %12s", novo->cpf);
    while(novo->idade <= 0){
        scanf("Idade do cliente: %d", &novo->idade);
    }
    while(novo->vendeFiado != 0 && novo->vendeFiado != 1){
        scanf("Vende fiado (0 = Não, 1 = Sim): %d", &novo->vendeFiado);
    }

    atual = novo;
}