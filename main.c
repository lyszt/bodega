#include "sentinela.h"



int main() {
    Sentinela sentinela = {NULL, NULL};

    while (true) {
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
                break;
            case 6:
                mostrarClientes(&sentinela);
                break;
            case 7:
                printf("Encerrando o programa...\n");
                liberarBebidas(&sentinela);
                liberarClientes(&sentinela);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}
