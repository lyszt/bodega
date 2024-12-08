#include "sentinela.h"

void mostrarBebidas(Sentinela *sentinela) {
    if (!sentinela->head) {
        printf("Nenhuma bebida cadastrada.\n");
        return;
    }
    Bebida *atual = sentinela->head;
    while (atual) {
        printf("Código: %d | Nome: %s | Volume: %.2fml | Preço: R$%.2f | Estoque: %d | Alcoólico: %s\n",
               atual->codigo, atual->nome, atual->volume, atual->preco, atual->quantidade,
               atual->teorAlcoolico ? "Sim" : "Não");
        atual = atual->next;
    }
}


void mostrarClientes(Sentinela *sentinela) {
    if (!sentinela->headCliente) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    Cliente *atual = sentinela->headCliente;
    while (atual) {
        printf("Código: %d | Nome: %s | CPF: %s | Idade: %d | Vender fiado: %s\n",
               atual->codigo, atual->nome, atual->cpf, atual->idade, atual->vendeFiado ? "Sim" : "Não");
        atual = atual->next;
    }
}