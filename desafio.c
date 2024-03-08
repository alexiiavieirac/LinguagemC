#include <stdio.h>
#include <stdlib.h>

#define MAX_MEDICO 21
#define MAX_CELULAR 11
#define MAX_DATA_CONSULTA 11

typedef struct {
    char medico[MAX_MEDICO];
    char celular[MAX_CELULAR];
    char data_consulta[MAX_DATA_CONSULTA];
} Dados;

int compararStrings(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

unsigned int comprimentoString(const char *str) {
    unsigned int tamanho = 0;
    while (*str++ != '\0') {
        tamanho++;
    }
    return tamanho;
}

void copiarString(char *dest, const char *src) {
    while ((*dest++ = *src++) != '\0');
}

int entradaDados(FILE *arquivo, Dados *dados) {
    printf("\nNome Completo do Medico: ");
    fgets(dados->medico, MAX_MEDICO, stdin);
    dados->medico[comprimentoString(dados->medico) - 1] = '\0';

    printf("Celular do Medico: ");
    fgets(dados->celular, MAX_CELULAR, stdin);
    dados->celular[comprimentoString(dados->celular) - 1] = '\0';

    printf("Data da Consulta (dd/mm/yyyy): ");
    fgets(dados->data_consulta, MAX_DATA_CONSULTA, stdin);
    dados->data_consulta[comprimentoString(dados->data_consulta)] = '\0';

    fseek(arquivo, 0, SEEK_END);
    fwrite(dados, sizeof(Dados), 1, arquivo);

    printf("\nDados inseridos com sucesso!\n");
}

int listarDados(FILE *arquivo) {
    Dados dados;

    fseek(arquivo, 0, SEEK_SET);

    printf("\n--- Dados Armazenados ---\n");

    while (fread(&dados, sizeof(Dados), 1, arquivo) == 1) {
        if (dados.medico[0] != '!') {
            printf("Medico: %s\n", dados.medico);
            printf("Celular: %s\n", dados.celular);
            printf("Data da Consulta: %s\n", dados.data_consulta);
            printf("------------------------\n");
        }
    }
}

int pesquisarMedico(FILE *arquivo, const char *nomeMedico) {
    Dados dados;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&dados, sizeof(Dados), 1, arquivo) == 1) {
        if (compararStrings(dados.medico, nomeMedico) == 0 && dados.medico[0] != '!') {
            printf("\nMedico: %s\n", dados.medico);
            printf("Celular: %s\n", dados.celular);
            printf("Data da Consulta: %s\n", dados.data_consulta);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nMedico nao encontrado.\n");
    }
}

int pesquisarCelular(FILE *arquivo, const char *celularMedico) {
    Dados dados;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&dados, sizeof(Dados), 1, arquivo) == 1) {
        if (compararStrings(dados.celular, celularMedico) == 0 && dados.medico[0] != '!') {
            printf("\nMedico: %s\n", dados.medico);
            printf("Celular: %s\n", dados.celular);
            printf("Data da Consulta: %s\n", dados.data_consulta);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nMedico com o celular especificado nao encontrado.\n");
    }
}

int pesquisarDataConsulta(FILE *arquivo, const char *dataConsulta) {
    Dados dados;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&dados, sizeof(Dados), 1, arquivo) == 1) {
        if (compararStrings(dados.data_consulta, dataConsulta) == 0 && dados.medico[0] != '!') {
            printf("\nMedico: %s\n", dados.medico);
            printf("Celular: %s\n", dados.celular);
            printf("Data da Consulta: %s\n", dados.data_consulta);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNenhuma consulta encontrada nessa data.\n");
    }
}

int alterarDados(FILE *arquivo, const char *nomeMedico) {
    Dados dados;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&dados, sizeof(Dados), 1, arquivo) == 1) {
        if (compararStrings(dados.medico, nomeMedico) == 0 && dados.medico[0] != '!') {
            printf("\nMedico: %s\n", dados.medico);
            printf("Celular: %s\n", dados.celular);
            printf("Data da Consulta: %s\n", dados.data_consulta);

            printf("\nDigite o novo nome completo do medico: ");
            fgets(dados.medico, MAX_MEDICO, stdin);
            dados.medico[comprimentoString(dados.medico) - 1] = '\0';

            printf("Digite o novo celular do medico: ");
            fgets(dados.celular, MAX_CELULAR, stdin);
            dados.celular[comprimentoString(dados.celular) - 1] = '\0';

            printf("Digite a nova data da consulta (dd/mm/yyyy): ");
            fgets(dados.data_consulta, MAX_DATA_CONSULTA, stdin);
            dados.data_consulta[comprimentoString(dados.data_consulta)] = '\0';

            fseek(arquivo, -sizeof(Dados), SEEK_CUR);
            fwrite(&dados, sizeof(Dados), 1, arquivo);

            encontrado = 1;
            break;
        }
    }

    fseek(arquivo, 0, SEEK_SET);

    if (!encontrado) {
        printf("\nMedico nao encontrado.\n");
    } else {
        printf("\nDados alterados com sucesso!\n");
    }

    return encontrado;
}

int excluirDados(FILE *arquivo, const char *nomeMedico) {
    Dados dados;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&dados, sizeof(Dados), 1, arquivo) == 1) {
        if (compararStrings(dados.medico, nomeMedico) == 0) {
            dados.medico[0] = '!';

            fseek(arquivo, -sizeof(Dados), SEEK_CUR);

            fwrite(&dados, sizeof(Dados), 1, arquivo);

            fseek(arquivo, 0, SEEK_CUR);

            encontrado = 1;
            break;
        }
    }

    fseek(arquivo, 0, SEEK_SET);

    if (!encontrado) {
        printf("\nMedico nao encontrado.\n");
    } else {
        printf("\nDados marcados como excluidos com sucesso!\n");
    }

    return encontrado;
}


int main() {
    FILE *arquivo = fopen("arquivo.txt", "w+");

    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Pesquisar um medico pelo nome completo\n");
        printf("4 - Pesquisar um celular pelo numero completo\n");
        printf("5 - Pesquisar pela data da consulta\n");
        printf("6 - Alterar dados\n");
        printf("7 - Excluir dados\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                Dados novosDados;
                entradaDados(arquivo, &novosDados);
                break;
            }
            case 2:
                listarDados(arquivo);
                break;
            case 3: {
                char nomeMedico[MAX_MEDICO];
                printf("\nDigite o nome completo do medico: ");
                fgets(nomeMedico, MAX_MEDICO, stdin);
                nomeMedico[comprimentoString(nomeMedico) - 1] = '\0';
                pesquisarMedico(arquivo, nomeMedico);
                break;
            }
            case 4: {
                char celularMedico[MAX_CELULAR];
                printf("\nDigite o celular do medico para pesquisar: ");
                fgets(celularMedico, MAX_CELULAR, stdin);
                celularMedico[comprimentoString(celularMedico) - 1] = '\0';
                pesquisarCelular(arquivo, celularMedico);
                break;
            }
            case 5: {
                char dataConsulta[MAX_DATA_CONSULTA];
                printf("\nDigite a data da consulta (dd/mm/yyyy): ");
                fgets(dataConsulta, MAX_DATA_CONSULTA, stdin);
                dataConsulta[comprimentoString(dataConsulta) - 1] = '\0';
                pesquisarDataConsulta(arquivo, dataConsulta);
                break;
            }
            case 6: {
                char nomeMedico[MAX_MEDICO];
                printf("\nDigite o nome completo do medico que deseja alterar os dados: ");
                fgets(nomeMedico, MAX_MEDICO, stdin);
                nomeMedico[comprimentoString(nomeMedico) - 1] = '\0';
                alterarDados(arquivo, nomeMedico);
                break;
            }
            case 7: {
                char nomeMedico[MAX_MEDICO];
                printf("\nDigite o nome completo do medico que deseja excluir os dados: ");
                fgets(nomeMedico, MAX_MEDICO, stdin);
                nomeMedico[comprimentoString(nomeMedico) - 1] = '\0';
                excluirDados(arquivo, nomeMedico);
                break;
            }
            case 8:
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 8);

    fclose(arquivo);

    return 0;
}

