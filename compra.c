#include "sentinela.h"

void comprarBebida(Sentinela *sentinela) {
    int codigo, quantidade;
    printf("Digite o Código da Bebida: ");
    scanf("%d", &codigo);

    Bebida *atual = sentinela->head;
    while (atual) {
        if (atual->codigo == codigo) {
            printf("Quantidade que deseja adicionar ao estoque da bebida %s: ", atual->nome);
            scanf("%d", &quantidade);
            atual->quantidade += quantidade;
            printf("Estoque atualizado com sucesso!\n");
            return;
        }
        atual = atual->next;
    }
    printf("Bebida com código %d não encontrada.\n", codigo);
}

void venderBebida(Sentinela *sentinela) {
    int codigo, quantidade;
    char cpf[13];
    printf("Digite o CPF do cliente: ");
    scanf("%12s", cpf);

    Cliente *atualCliente = sentinela->headCliente;
    while (atualCliente) {
        if (strcmp(atualCliente->cpf, cpf) == 0) {
            break;
        }
        atualCliente = atualCliente->next;
    }

    if (!atualCliente) {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
        return;
    }

    printf("Digite o Código da Bebida: ");
    scanf("%d", &codigo);

    Bebida *atualBebida = sentinela->head;
    while (atualBebida) {
        if (atualBebida->codigo == codigo) {
            printf("Quantidade que deseja vender: ");
            scanf("%d", &quantidade);
            if (atualBebida->quantidade < quantidade) {
                printf("Estoque insuficiente. Estoque atual: %d\n", atualBebida->quantidade);
                return;
            }
            if( atualBebida->teorAlcoolico > 0 && atualCliente->idade < 18){
                printf("Bebida possui teor alcóolico e cliente não possui idade para consumir esta bebida.");
            }
            atualBebida->quantidade -= quantidade;
            printf("Venda realizada com sucesso!\n");
            return;
        }
        atualBebida = atualBebida->next;
    }
    printf("Bebida com código %d não encontrada.\n", codigo);
}
