#include <stdio.h>
#include <stdlib.h>

    char medic01[21];
    char medic02[21];
    char medic03[21];
    char data_consulta01[11];
    char data_consulta02[11];
    char data_consulta03[11];

    char nomeMedico[21];
    char dataConsulta[11];

int entradaDados()
{
    FILE *consulta;

    consulta = fopen("arquivo.txt", "w");

    printf("\nNome Completo: ");
    gets(medic01);
    printf("\nData da Consulta (dd/mm/yyyy): ");
    gets(data_consulta01);

    fwrite(medic01, sizeof(medic01), 1, consulta);
    fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);

    printf("\nNome Completo: ");
    gets(medic02);
    printf("\nData da Consulta (dd/mm/yyyy): ");
    gets(data_consulta02);

    fwrite(medic02, sizeof(medic02), 1, consulta);
    fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);

    printf("\nNome Completo: ");
    gets(medic03);
    printf("\nData da Consulta (dd/mm/yyyy): ");
    gets(data_consulta03);

    fwrite(medic03, sizeof(medic03), 1, consulta);
    fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);

    fclose(consulta);

    return;
}

int listaDados()
{
    FILE *consulta;

    consulta = fopen("arquivo.txt", "r");

    fread(medic01, sizeof(medic01), 1, consulta);
    fread(data_consulta01, sizeof(data_consulta01), 1, consulta);

    fread(medic02, sizeof(medic02), 1, consulta);
    fread(data_consulta02, sizeof(data_consulta02), 1, consulta);

    fread(medic03, sizeof(medic03), 1, consulta);
    fread(data_consulta03, sizeof(data_consulta03), 1, consulta);

    printf("Medico: %s\n", medic01);
    printf("Data de Consulta: %s\n", data_consulta01);

    printf("\nMedico: %s\n", medic02);
    printf("Data de Consulta: %s\n", data_consulta02);

    printf("\nMedico: %s\n", medic03);
    printf("Data de Consulta: %s\n", data_consulta03);

    fclose(consulta);

    return;
}

int pesquisaMedico()
{
    int cont, i;

    FILE *consulta;

    consulta = fopen("arquivo.txt", "r");

    printf("Nome do medico que quer consultar: ");
    gets(nomeMedico);

    fread(medic01, sizeof(medic01), 1, consulta);
    fread(data_consulta01, sizeof(data_consulta01), 1, consulta);

    fread(medic02, sizeof(medic02), 1, consulta);
    fread(data_consulta02, sizeof(data_consulta02), 1, consulta);

    fread(medic03, sizeof(medic03), 1, consulta);
    fread(data_consulta03, sizeof(data_consulta03), 1, consulta);

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic01[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic01[i] == '\0') {
            printf("Voce pesquisou o medico: %s\n", nomeMedico);
            printf("Data de Consulta: %s", data_consulta01);
            return;
        }

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic02[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic02[i] == '\0') {
             printf("Voce pesquisou o medico: %s\n", nomeMedico);
             printf("Data de Consulta: %s", data_consulta02);
             return;
        }

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic03[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic03[i] == '\0') {
             printf("Voce pesquisou o medico: %s\n", nomeMedico);
             printf("Data de Consulta: %s", data_consulta03);
             return;
        }

    printf("Nao existe o nome desse medico");

    fclose(consulta);

    return;
}

int pesquisaConsulta()
{
    int cont, i;

    FILE *consulta;

    consulta = fopen("arquivo.txt", "r");

    printf("Data da consulta que deseja consultar: ");
    gets(dataConsulta);

    fread(medic01, sizeof(medic01), 1, consulta);
    fread(data_consulta01, sizeof(data_consulta01), 1, consulta);

    fread(medic02, sizeof(medic02), 1, consulta);
    fread(data_consulta02, sizeof(data_consulta02), 1, consulta);

    fread(medic03, sizeof(medic03), 1, consulta);
    fread(data_consulta03, sizeof(data_consulta03), 1, consulta);

    for(i = 0; dataConsulta[i] != '\0'; i++) {
        if(dataConsulta[i] != data_consulta01[i]) {
           break;
        }
    }
        if(dataConsulta[i] == '\0' && data_consulta01[i] == '\0') {
            printf("Medico: %s\n", medic01);
            printf("Data de Consulta: %s", dataConsulta);
            return;
        }

    for(i = 0; dataConsulta[i] != '\0'; i++) {
        if(dataConsulta[i] != data_consulta02[i]) {
           break;
        }
    }
        if(dataConsulta[i] == '\0' && data_consulta02[i] == '\0') {
            printf("Medico: %s\n", medic02);
            printf("Data de Consulta: %s", dataConsulta);
            return;
        }

    for(i = 0; dataConsulta[i] != '\0'; i++) {
        if(dataConsulta[i] != data_consulta03[i]) {
           break;
        }
    }
        if(dataConsulta[i] == '\0' && data_consulta03[i] == '\0') {
            printf("Medico: %s\n", medic03);
            printf("Data de Consulta: %s", dataConsulta);
            return;
        }

    printf("Essa data nao existe no sistema.");

    fclose(consulta);

    return;
}

int alterarDados()
{
    int i;

    FILE *consulta;

    consulta = fopen("arquivo.txt", "r");

    fread(medic01, sizeof(medic01), 1, consulta);
    fread(data_consulta01, sizeof(data_consulta01), 1, consulta);

    fread(medic02, sizeof(medic02), 1, consulta);
    fread(data_consulta02, sizeof(data_consulta02), 1, consulta);

    fread(medic03, sizeof(medic03), 1, consulta);
    fread(data_consulta03, sizeof(data_consulta03), 1, consulta);

    fclose(consulta);

    consulta = fopen("arquivo.txt", "w");

    printf("Nome do Medico: ");
    gets(nomeMedico);

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic01[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic01[i] == '\0') {
            printf("Alterar nome do medico: ");
            gets(medic01);
            printf("Alterar a Data de Consulta: ");
            gets(data_consulta01);
            fwrite(medic01, sizeof(medic01), 1, consulta);
            fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);
            fwrite(medic02, sizeof(medic02), 1, consulta);
            fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);
            fwrite(medic03, sizeof(medic03), 1, consulta);
            fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);
            fclose(consulta);
            return;
        }

    consulta = fopen("arquivo.txt", "w");

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic02[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic02[i] == '\0') {
            printf("Alterar nome do medico: ");
            gets(medic02);
            printf("Alterar a Data de Consulta: ");
            gets(data_consulta02);
            fwrite(medic01, sizeof(medic01), 1, consulta);
            fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);
            fwrite(medic02, sizeof(medic02), 1, consulta);
            fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);
            fwrite(medic03, sizeof(medic03), 1, consulta);
            fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);
            fclose(consulta);
            return;
        }


    consulta = fopen("arquivo.txt", "w");

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic03[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic03[i] == '\0') {
            printf("Alterar nome do medico: ");
            gets(medic03);
            printf("Alterar a Data de Consulta: ");
            gets(data_consulta03);
            fwrite(medic01, sizeof(medic01), 1, consulta);
            fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);
            fwrite(medic02, sizeof(medic02), 1, consulta);
            fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);
            fwrite(medic03, sizeof(medic03), 1, consulta);
            fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);
            fclose(consulta);
            return;
        }

    return;
}

int excluirDados()
{
    int i;

    FILE *consulta;

    consulta = fopen("arquivo.txt", "r");

    fread(medic01, sizeof(medic01), 1, consulta);
    fread(data_consulta01, sizeof(data_consulta01), 1, consulta);

    fread(medic02, sizeof(medic02), 1, consulta);
    fread(data_consulta02, sizeof(data_consulta02), 1, consulta);

    fread(medic03, sizeof(medic03), 1, consulta);
    fread(data_consulta03, sizeof(data_consulta03), 1, consulta);

    fclose(consulta);

    consulta = fopen("arquivo.txt", "w");

    printf("Nome do Medico: ");
    gets(nomeMedico);

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic01[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic01[i] == '\0') {
            medic01[0] = '\0';
            data_consulta01[0] = '\0';
            fwrite(medic01, sizeof(medic01), 1, consulta);
            fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);
            fwrite(medic02, sizeof(medic02), 1, consulta);
            fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);
            fwrite(medic03, sizeof(medic03), 1, consulta);
            fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);
            fclose(consulta);
            return;
        }

    consulta = fopen("arquivo.txt", "w");

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic02[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic02[i] == '\0') {
            medic02[0] = '\0';
            data_consulta02[0] = '\0';
            fwrite(medic01, sizeof(medic01), 1, consulta);
            fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);
            fwrite(medic02, sizeof(medic02), 1, consulta);
            fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);
            fwrite(medic03, sizeof(medic03), 1, consulta);
            fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);
            fclose(consulta);
            return;
        }


    consulta = fopen("arquivo.txt", "w");

    for(i = 0; nomeMedico[i] != '\0'; i++) {
        if(nomeMedico[i] != medic03[i]) {
           break;
        }
    }
        if(nomeMedico[i] == '\0' && medic03[i] == '\0') {
            medic03[0] = '\0';
            data_consulta03[0] = '\0';
            fwrite(medic01, sizeof(medic01), 1, consulta);
            fwrite(data_consulta01, sizeof(data_consulta01), 1, consulta);
            fwrite(medic02, sizeof(medic02), 1, consulta);
            fwrite(data_consulta02, sizeof(data_consulta02), 1, consulta);
            fwrite(medic03, sizeof(medic03), 1, consulta);
            fwrite(data_consulta03, sizeof(data_consulta03), 1, consulta);
            fclose(consulta);
            return;
        }

    return;
}

int saida()
{
    exit(0);
}

int main()
{

    int escolha;
    char tecla;

    printf("Menu:\n");

    printf("1. Entrada de dados.\n");

    printf("2. Lista todos os dados na tela.\n");

    printf("3. Pesquisa um medico pelo nome completo e mostra todo os dados na tela.\n");

    printf("4. Pesquisa pela data de consulta e mostra todos na tela.\n");

    printf("5. Altera dados. Pesquisa pelo nome completo do medico.\n");

    printf("6. Exclui dados. Pesquisa pelo nome completo do medico.\n");

    printf("7. Saida.\n");

    printf("_______________________________________________________________");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &escolha);
    getchar();

    do {
        switch (escolha) {

            case 1:
               entradaDados();
                break;

           case 2:
                listaDados();
                break;

            case 3:
                pesquisaMedico();
                break;

            case 4:
                pesquisaConsulta();
                break;

            case 5:
                alterarDados();
                break;

            case 6:
                excluirDados();
                break;

            case 7:
                printf("Saindo...");
                saida();

            default:
                printf("Numero invalido.");
                break;
        }

        printf("\n_______________________________________________________________");


        printf("\nQuer tentar de novo? (y/n) ");
        getchar();
        tecla = getchar();
    } while(tecla == 'y' || tecla == 'Y');

    return 0;
}
