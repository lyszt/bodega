#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Empresa {
    char nome[50];
    char CNPJ[14];
} Empresa;

typedef struct Bebida {
    int codigo;
    char nome[50];
    float volume;
    float preco;
    int quantidade;
    int teorAlcoolico;
    struct Bebida *proximo;
} Bebida;

typedef struct Cliente {
    int codigo;
    char nome[50];
    char CPF[12];
    int idade;
    int vendeFiado;
    struct Cliente *proximo;
} Cliente;

void cadastrarBebida(Bebida **head) {
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    printf("Código: ");
    scanf("%d", &nova->codigo);
    printf("Nome: ");
    scanf("%s", nova->nome);
    printf("Volume (ml): ");
    scanf("%f", &nova->volume);
    printf("Preço: ");
    scanf("%f", &nova->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &nova->quantidade);
    printf("Teor alcoólico (0 = Não alcoólica): ");
    scanf("%d", &nova->teorAlcoolico);
    nova->proximo = NULL;
    if (*head == NULL) {
        *head = nova;
    } else {
        Bebida *atual = *head;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = nova;
    }
    printf("Bebida cadastrada com sucesso!\n");
}

void mostrarBebidas(Bebida *head) {
    if (!head) {
        printf("Nenhuma bebida cadastrada.\n");
        return;
    }
    Bebida *atual = head;
    while (atual) {
        printf("Código: %d | Nome: %s | Volume: %.2fml | Preço: R$%.2f | Estoque: %d | Alcoólico: %s\n",
               atual->codigo, atual->nome, atual->volume, atual->preco, atual->quantidade,
               atual->teorAlcoolico ? "Sim" : "Não");
        atual = atual->proximo;
    }
}

void liberarBebidas(Bebida **head) {
    while (*head) {
        Bebida *aux = *head;
        *head = (*head)->proximo;
        free(aux);
    }
}

void cadastrarCliente(Cliente **head) {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    printf("Código: ");
    scanf("%d", &novo->codigo);
    printf("Nome: ");
    scanf("%s", novo->nome);
    printf("CPF: ");
    scanf("%s", novo->CPF);
    printf("Idade: ");
    scanf("%d", &novo->idade);
    printf("Vende fiado (0 = Não, 1 = Sim): ");
    scanf("%d", &novo->vendeFiado);
    novo->proximo = NULL;
    if (*head == NULL || (*head)->idade > novo->idade) {
        novo->proximo = *head;
        *head = novo;
    } else {
        Cliente *atual = *head;
        while (atual->proximo && atual->proximo->idade <= novo->idade) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    printf("Cliente cadastrado com sucesso!\n");
}

void mostrarClientes(Cliente *head) {
    if (!head) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    Cliente *atual = head;
    while (atual) {
        printf("Código: %d | Nome: %s | CPF: %s | Idade: %d | Fiado: %s\n",
               atual->codigo, atual->nome, atual->CPF, atual->idade,
               atual->vendeFiado ? "Sim" : "Não");
        atual = atual->proximo;
    }
}

void liberarClientes(Cliente **head) {
    while (*head) {
        Cliente *aux = *head;
        *head = (*head)->proximo;
        free(aux);
    }
}

int main() {
    Bebida *bebidas = NULL;
    Cliente *clientes = NULL;

    while (1) {
        int opcao;
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar bebida\n");
        printf("2. Mostrar bebidas\n");
        printf("3. Cadastrar cliente\n");
        printf("4. Mostrar clientes\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarBebida(&bebidas);
                break;
            case 2:
                mostrarBebidas(bebidas);
                break;
            case 3:
                cadastrarCliente(&clientes);
                break;
            case 4:
                mostrarClientes(clientes);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                liberarBebidas(&bebidas);
                liberarClientes(&clientes);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
