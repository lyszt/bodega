#ifndef SENTINELA_H
#define SENTINELA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bebida {
    int codigo;
    char nome[50];
    float volume;
    float preco;
    int quantidade;
    int teorAlcoolico; // 0 for non-alcoholic, 1 for alcoholic
    struct Bebida *next;
} Bebida;

typedef struct Cliente {
    int codigo;
    char nome[50];
    char cpf[13];
    int idade;
    int vendeFiado; // 0 for no, 1 for yes
    struct Cliente *next;
} Cliente;

typedef struct Sentinela {
    Bebida *head;
    Cliente *headCliente;
} Sentinela;

void cadastrarCliente(Sentinela *sentinela);
void cadastrarBebida(Sentinela *sentinela);

void mostrarClientes(Sentinela *sentinela);
void mostrarBebidas(Sentinela *sentinela);

void liberarClientes(Sentinela *sentinela);
void liberarBebidas(Sentinela *sentinela);

void comprarBebida(Sentinela *sentinela);
void venderBebida(Sentinela *sentinela);
#endif