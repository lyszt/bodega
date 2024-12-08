#include "sentinela.h"

void liberarBebidas(Sentinela *sentinela) {
    while (sentinela->head) {
        Bebida *aux = sentinela->head;
        sentinela->head = sentinela->head->next;
        free(aux);
    }
}
void liberarClientes(Sentinela *sentinela) {
    while (sentinela->headCliente) {
        Cliente *aux = sentinela->headCliente;
        sentinela->headCliente = sentinela->headCliente->next;
        free(aux);
    }
}
