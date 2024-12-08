#include "sentinela.h"


void cadastrarBebida(Sentinela *sentinela) {
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    nova->next = NULL;
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    while(nova->codigo <= 0){
        printf("Código: ");
        scanf("%d", &nova->codigo);
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

    printf("Nome: ");
    int is_valid = false;
    while(!is_valid){
        scanf("%s", nova->nome);
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
        printf("Volume (ml): ");
        scanf("%f", &nova->volume);
    }
    while(nova->preco <= 0){
        printf("Preço: ");
        scanf("%f", &nova->preco);
    }
    while(nova->quantidade <= 0){
        printf("Quantidade em estoque: ");
        scanf("%d", &nova->quantidade);
    }
    while(nova->teorAlcoolico != 1 && nova->teorAlcoolico != 0){
    printf("Teor alcoólico (0 = Não alcoólica, 1 = Alcoólica): ");
    scanf("%d", &nova->teorAlcoolico);
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
    int is_valid = false;
    while(!is_valid){
        scanf("%s", novo->nome);
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
    printf("CPF do cliente: ");
    scanf("%12s", novo->cpf);
    while(novo->idade <= 0){
        printf("Idade do cliente: \n");
        scanf("%d", &novo->idade);
    }
    while(novo->vendeFiado != 0 && novo->vendeFiado != 1){
        printf("Vende fiado (0 = Não, 1 = Sim): ");
        scanf("%d", &novo->vendeFiado);
    }

    atual = novo;
}