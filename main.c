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

void cadastrarBebida(Sentinela *sentinela) {
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    printf("Código: ");
    scanf("%d", &nova->codigo);

    // Check if code already exists
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
    printf("Volume (ml): ");
    scanf("%f", &nova->volume);
    printf("Preço: ");
    scanf("%f", &nova->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &nova->quantidade);
    printf("Teor alcoólico (0 = Não alcoólica, 1 = Alcoólica): ");
    scanf("%d", &nova->teorAlcoolico);
    nova->next = NULL;

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
                printf("Cliente possui %d anos e %s possui %d teor alcólico. Não é possivel realizar a venda!");
            }
            atualBebida->quantidade -= quantidade;
            printf("Venda realizada com sucesso!\n");
            return;
        }
        atualBebida = atualBebida->next;
    }
    printf("Bebida com código %d não encontrada.\n", codigo);
}

void liberarBebidas(Sentinela *sentinela) {
    while (sentinela->head) {
        Cliente *aux = sentinela->head;
        sentinela->head = sentinela->head->next;
        free(aux);
    }
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

printf("Nome do cliente: ");
scanf("%s", novo->nome);
printf("CPF do cliente: ");
scanf("%12s", novo->cpf);
printf("Idade do cliente: ");
scanf("%d", &novo->idade);
printf("Vende fiado (0 = Não, 1 = Sim): ");
scanf("%d", &novo->vendeFiado);

atual = novo;
}

void mostrarClientes(Sentinela *sentinela) {
    if (!sentinela->headCliente) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    Cliente *atual = sentinela->headCliente;
    while (atual) {
        printf("Código: %d | Nome: %s | CPF: %s | Idade: %d | Vender fiado: %d\n",
               atual->codigo, atual->nome, atual->cpf, atual->idade, atual->vendeFiado ? "Sim" : "Não");
        atual = atual->next;
    }
}

void liberarClientes(Sentinela *sentinela) {
    while (sentinela->headCliente) {
        Cliente *aux = sentinela->headCliente;
        sentinela->headCliente = sentinela->headCliente->next;
        free(aux);
    }
}

int main() {
    Sentinela sentinela = {NULL, NULL};

    while (1) {
        int opcao;
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar bebida\n");
        printf("2. Mostrar bebidas\n");
        printf("3. Comprar bebida\n");
        printf("4. Vender bebida\n");
        printf("5. Cadastrar cliente\n");
        printf("6. Mostrar clientes\n");
        printf("7. Sair do sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarBebida(&sentinela);
                break;
            case 2:
                mostrarBebidas(&sentinela);
                break;
            case 3:
                comprarBebida(&sentinela);
                break;
            case 4:
                venderBebida(&sentinela);
                break;
            case 5:
                cadastrarCliente(&sentinela);
            case 6:
                mostrarCliente(&sentinela);
            case 7:
                printf("Encerrando o programa...\n");
                liberarBebidas(&sentinela.head);
                liberarClientes(&sentinela.headCliente);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
