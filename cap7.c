#include <stdio.h>
#include <stdlib.h>
#define ex03

// ------------------------------------------------------------------

#ifdef ex01

    /*
        1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
            Receba dados via teclado em uma funcao e imprima estes conteudos no video,
            em outra funcao, no seguinte formato.
            Estrutura: char, int, long, float, double, unsigned char, unsigned int,
                        unsigned long

                    10        20        30        40        50        60        70
            1234567890123456789012345678901234567890123456789012345678901234567890
                char      int       long                float               double
                      unsigned char       unsigned int        unsigned long
    */

struct dados {
    char carac;
    int inteiro;
    long longo;
    float flutuante;
    double dble;
    unsigned char semc;
    unsigned int semi;
    unsigned long seml;
};

struct dados receberDados()
{
    struct dados dados;

    printf("Valor CHAR: ");
    scanf("%c", &dados.carac);

    getchar();
    printf("Valor INT: ");
    scanf("%d", &dados.inteiro);

    getchar();
    printf("Valor LONG: ");
    scanf("%ld", &dados.longo);

    getchar();
    printf("Valor FLOAT: ");
    scanf("%f", &dados.flutuante);
    getchar();

    printf("Valor DOUBLE: ");
    scanf("%lf", &dados.dble);
    getchar();

    printf("Valor UNSIGNED CHAR: ");
    scanf("%c", &dados.semc);

    printf("Valor UNSIGNED INT: ");
    scanf("%u", &dados.semi);

    getchar();
    printf("Valor UNSIGNED LONG: ");
    scanf("%lu", &dados.seml);

    return dados;
}

int imprimirDados(struct dados receber)
{
    printf("       10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %c         %-11d    %-11ld        %8.1e        %9.1e\n", receber.carac, receber.inteiro, receber.longo, receber.flutuante, receber.dble);
    printf("             %c                %-10u              %-10lu", receber.semc, receber.semi, receber.seml);

}

int main()
{
    struct dados dados = receberDados();

    imprimirDados(dados);

    return 0;
}
#endif // ex01

// ------------------------------------------------------------------

#ifdef ex02

    /*
        2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
            estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
            e imprima-os no video em uma funcao. Utilize vetor de estruturas.
            Faça um menu com uma opcao para saida do programa.
            Estrutura: nome, end, cidade, estado, cep
    */

struct contato {
    char nome;
    char end;
    char cidade;
    char estado;
    char cep;
};

int receberContato(struct contato contatos[4], int tamanho)
{
    for(int i = 0; i < tamanho; i++) {
        printf("Contato %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", &contatos[i].nome);

        printf("Endereco: ");
        scanf("%s", &contatos[i].end);

        getchar();
        printf("Cidade: ");
        scanf("%s", &contatos[i].cidade);

        printf("Estado: ");
        scanf("%s", &contatos[i].estado);

        printf("CEP: ");
        scanf("%s", &contatos[i].cep);
    }
}

int imprimirContatos(struct contato contatos[4], int tamanho)
{
    printf("Dados dos Contatos:\n");

    for(int i = 0; i < tamanho; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Endereco: %s\n", contatos[i].end);
        printf("Cidade: %s\n", contatos[i].cidade);
        printf("Estado: %s\n", contatos[i].estado);
        printf("CEP: %s", contatos[i].cep);
    }
}

int main()
{
    int tamanho = 4;
    struct contato contatos[tamanho];

    receberContato(contatos, tamanho);
    imprimirContatos(contatos, tamanho);

    return 0;
}

#endif // ex02

// ------------------------------------------------------------------

#ifdef ex03

    /*
        3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
            teclado na funcao main(). Faca uma funcao que calcule o numero de dias
            entre elas e mostre o resultado no video na funcao main().
            Utilize vetor de estruturas.
            Estrutura: dia, mes, ano
    */

    struct data {
    int dia;
    int mes;
    int ano;
};

int calcularDias(struct data data1, struct data data2) {
    int dias1 = data1.dia + data1.mes * 30 + data1.ano * 365;
    int dias2 = data2.dia + data2.mes * 30 + data2.ano * 365;
    return dias2 - dias1;
}

int main() {
    struct data data1, data2;

    printf("Digite a primeira data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);

    printf("Digite a segunda data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    int dias = calcularDias(data1, data2);

    printf("O numero de dias entre as duas datas e: %d\n", dias);

    return 0;
}

#endif // ex03

// ------------------------------------------------------------------

#ifdef ex04

/*  Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faça um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
        */

struct Pessoa {
    char nome[20];
    float peso;
    float altura;
};

void receberDados(struct Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", pessoas[i].nome);

        printf("Digite o peso da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].peso);

        printf("Digite a altura da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].altura);
    }
}

void imprimirDados(struct Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Dados da pessoa %d:\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Altura: %.2f\n", pessoas[i].altura);
    }
}

void calcularIMC(struct Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        float imc = pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura);
        printf("IMC da pessoa %d: %.2f\n", i+1, imc);
    }
}

int main() {
    struct Pessoa pessoas[4];
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Receber dados\n");
        printf("2 - Imprimir dados\n");
        printf("3 - Calcular IMC\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                receberDados(pessoas, 4);
                break;
            case 2:
                imprimirDados(pessoas, 4);
                break;
            case 3:
                calcularIMC(pessoas, 4);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;

}
#endif // ex04

// ------------------------------------------------------------------
