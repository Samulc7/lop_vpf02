#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

typedef struct {
    char nome[50];
    char cargo[30];
    float salario;
} Funcionario;

int main() {
    FILE *arquivo;
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int total = 0;
    float somaSalarios = 0.0;

    arquivo = fopen("funcionarios.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Ignora o cabeçalho
    char linha[200];
    fgets(linha, sizeof(linha), arquivo);

    // Lê os dados dos funcionários
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%49[^,],%29[^,],%f",
               funcionarios[total].nome,
               funcionarios[total].cargo,
               &funcionarios[total].salario);

        somaSalarios += funcionarios[total].salario;
        total++;
    }

    fclose(arquivo);

    // Exibe o relatório
    printf("\n===== RELATORIO DE FUNCIONARIOS =====\n\n");

    for (int i = 0; i < total; i++) {
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salario: R$ %.2f\n", funcionarios[i].salario);
        printf("-----------------------------------\n");
    }

    printf("Total de funcionarios: %d\n", total);

    if (total > 0) {
        printf("Media salarial: R$ %.2f\n", somaSalarios / total);
    }

    return 0;
}