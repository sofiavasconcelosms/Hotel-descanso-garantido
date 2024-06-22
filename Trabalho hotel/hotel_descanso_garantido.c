#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cliente {
    char nome[70];
    char endereco[100];
    char telefone[20];
    int codigo;
};

struct funcionario {
    char nome[70];
    char telefone[30];
    char cargo[50];
    float salario;
    int codigo;
};

struct estadia {
    char dataEntrada[70];
    char dataSaida[30];
    int Diarias;
    int nQuarto;
    int codigo;
};

struct quarto {
    int Nquarto;
    int qtdHospedes;
    float valorDiaria;
    char status[30]; // Opcional: poderia ser um enum para melhor clareza
    int ocupado;     // 0 para desocupado, 1 para ocupado
};

void listarReservas(struct cliente clientes[], struct estadia estadias[], struct quarto quartos[], int num_estadias) {
    printf("\n----- Reservas Cadastradas -----\n");
    for (int i = 0; i < num_estadias; i++) {
        printf("Reserva %d:\n", i + 1);
        printf("Cliente:\n");
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Endereço: %s\n", clientes[i].endereco);
        printf("Código do cliente: %d\n", estadias[i].codigo);
        printf("Data de entrada: %s\n", estadias[i].dataEntrada);
        printf("Data de saída: %s\n", estadias[i].dataSaida);
        printf("Diárias: %d\n", estadias[i].Diarias);
        printf("Número do quarto: %d\n", estadias[i].nQuarto);
        printf("Quantidade de hóspedes: %d\n", quartos[estadias[i].nQuarto - 1].qtdHospedes);
        printf("Valor da diária: %.2f\n", quartos[estadias[i].nQuarto - 1].valorDiaria);
        printf("--------------------------------\n");
    }
}

int main(void) {
    struct cliente clientes[100];
    struct funcionario funcionarios[100];
    struct estadia estadias[100];
    struct quarto quartos[10];

    int num_clientes = 0;
    int num_funcionarios = 0;
    int num_estadias = 0;
    int num_quartos = 10; // Atualizado para 10 quartos

    char continuar;
    int opcao;

    srand((unsigned int) time(NULL)); 

    // Inicializando os quartos como desocupados
    for (int i = 0; i < 10; i++) {
        quartos[i].Nquarto = i + 1;
        quartos[i].ocupado = 0; // 0 para desocupado
    }

    do {
        printf("\n--------------------------------\n");
        printf("     Hotel Descanso Garantido\n");
        printf("--------------------------------\n");
        printf("\n----- Menu -----\n");
        printf("1. Fazer uma reserva\n");
        printf("2. Ver reservas cadastradas\n");
        printf("3. Apagar reserva\n");
        printf("4. Cadastrar funcionário\n");
        printf("5. Ver funcionários cadastrados\n");
        printf("6. Verificar status dos quartos\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Opção para fazer uma reserva
                printf("\nInsira os dados do cliente:\n");
                printf("Nome: ");
                scanf(" %[^\n]s", clientes[num_clientes].nome);
                printf("Telefone: ");
                scanf(" %[^\n]s", clientes[num_clientes].telefone);
                printf("Endereço: ");
                scanf(" %[^\n]s", clientes[num_clientes].endereco);

                clientes[num_clientes].codigo = rand() % (999999999 - 1000 + 1) + 1000;

                printf("\nCliente cadastrado com sucesso.\n");

                printf("Agora insira os dados para a estadia:\n");
                printf("Data de entrada: ");
                scanf(" %[^\n]s", estadias[num_estadias].dataEntrada);
                printf("Data de saída: ");
                scanf(" %[^\n]s", estadias[num_estadias].dataSaida);
                printf("Diárias: ");
                scanf("%d", &estadias[num_estadias].Diarias);

                int numero_quarto;
                do {
                    printf("Número do quarto (1 a 10): ");
                    scanf("%d", &numero_quarto);

                    // Verifica se o número do quarto está dentro dos limites
                    if (numero_quarto < 1 || numero_quarto > 10) {
                        printf("Número de quarto inválido. Digite novamente.\n");
                    } else if (quartos[numero_quarto - 1].ocupado) {
                        printf("Quarto já ocupado. Escolha outro quarto.\n");
                    } else {
                        estadias[num_estadias].nQuarto = numero_quarto;
                        quartos[numero_quarto - 1].ocupado = 1; // Marca o quarto como ocupado
                        break;
                    }
                } while (1);

                estadias[num_estadias].codigo = clientes[num_clientes].codigo;

                // Captura dados do quarto
                printf("\nInsira os dados para o quarto:\n");
                printf("Quantidade de hóspedes: ");
                scanf("%d", &quartos[numero_quarto - 1].qtdHospedes);
                printf("Valor da diária: ");
                scanf("%f", &quartos[numero_quarto - 1].valorDiaria);

                printf("\nEstadia cadastrada com sucesso.\n");

                num_clientes++;
                num_estadias++;
                break;

            case 2:
                // Opção para listar reservas cadastradas
                listarReservas(clientes, estadias, quartos, num_estadias);
                break;

            case 3:
                // Opção para apagar reserva
                if (num_estadias == 0) {
                    printf("Não há reservas cadastradas.\n");
                } else {
                    listarReservas(clientes, estadias, quartos, num_estadias);
                    int numero_reserva;
                    do {
                        printf("Digite o número da reserva que deseja apagar (1 a %d): ", num_estadias);
                        scanf("%d", &numero_reserva);

                        if (numero_reserva < 1 || numero_reserva > num_estadias) {
                            printf("Número de reserva inválido. Digite novamente.\n");
                        } else {
                            // Liberar o quarto
                            int num_quarto = estadias[numero_reserva - 1].nQuarto;
                            quartos[num_quarto - 1].ocupado = 0;

                            // Remover a reserva
                            for (int i = numero_reserva - 1; i < num_estadias - 1; i++) {
                                clientes[i] = clientes[i + 1];
                                estadias[i] = estadias[i + 1];
                            }
                            num_estadias--;

                            printf("Reserva apagada com sucesso.\n");
                            break;
                        }
                    } while (1);
                }
                break;

            case 4:
                // Opção para cadastrar funcionário
                printf("\nInsira os dados do funcionário:\n");
                printf("Nome: ");
                scanf(" %[^\n]s", funcionarios[num_funcionarios].nome);
                printf("Telefone: ");
                scanf(" %[^\n]s", funcionarios[num_funcionarios].telefone);
                printf("Cargo: ");
                scanf(" %[^\n]s", funcionarios[num_funcionarios].cargo);
                printf("Salário: ");
                scanf("%f", &funcionarios[num_funcionarios].salario);

                funcionarios[num_funcionarios].codigo = rand() % 999 + 1;

                printf("\nFuncionário cadastrado com sucesso.\n");

                num_funcionarios++;
                break;

            case 5:
                // Opção para listar funcionários cadastrados
                printf("\n----- Funcionários Cadastrados -----\n");
                for (int i = 0; i < num_funcionarios; i++) {
                    printf("Nome: %s\n", funcionarios[i].nome);
                    printf("Telefone: %s\n", funcionarios[i].telefone);
                    printf("Cargo: %s\n", funcionarios[i].cargo);
                    printf("Salário: %.2f\n", funcionarios[i].salario);
                    printf("Código: %d\n", funcionarios[i].codigo);
                    printf("--------------------------------\n");
                }
                break;

            case 6:
                // Opção para verificar status dos quartos
                printf("\n----- Status dos Quartos -----\n");
                for (int i = 0; i < 10; i++) {
                    printf("Número do quarto: %d\n", quartos[i].Nquarto);
                    printf("Quantidade de hóspedes: %d\n", quartos[i].qtdHospedes);
                    printf("Valor da diária: %.2f\n", quartos[i].valorDiaria);
                    printf("Status: %s\n", quartos[i].ocupado ? "Ocupado" : "Desocupado");
                    printf("--------------------------------\n");
                }
                break;

            case 7:
                printf("Fechando o programa...\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
        }

    } while (opcao != 7);

    return 0;
}
