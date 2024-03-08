#include <stdio.h>
#include <stdlib.h>
#define ex06

#ifdef ex01

/*  1 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main(). */


int compararStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0') {
        return 1;
    }

    return 0;
}

int main() {
    char palavra1[11];
    char palavra2[11];

    printf("Digite a primeira palavra: \n");
    scanf("%s", palavra1);

    printf("Digite a segunda palavra: \n");
    scanf("%s", palavra2);

    int result = compararStrings(palavra1, palavra2);

    if (result) {
        printf("As palavras sao iguais.\n");
    } else {
        printf("As palavras sao diferentes.\n");
    }

    return 0;
}

#endif //ex01

#ifdef ex02

/* 2 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main(). */


int receberValores(int *numPnt) {
    printf("Digite um numero: ");
    scanf("%d", numPnt);
}

char receberOperacao() {
    char operacao;
    printf("Digite a operacao (+, -, *, /, =): ");
    scanf(" %c", &operacao);
    return operacao;
}

int executarOperacao(int *somaPnt, int numero, char operacao) {
    switch (operacao) {
        case '+':
            *somaPnt += numero;
            break;
        case '-':
            *somaPnt -= numero;
            break;
        case '*':
            *somaPnt *= numero;
            break;
        case '/':
            if (numero != 0) {
                *somaPnt /= numero;
            } else {
                printf("Divisao por zero!\n");
            }
            break;
        default:
            printf("Operacao invalida!\n");
    }
}

int main() {
    char tecla, operacao;
    int numero, soma = 0;

    int *numPnt = &numero;
    int *somaPnt = &soma;

    while (operacao != '='){

        receberValores(numPnt);
        operacao = receberOperacao();
        if (operacao == '=') {
            printf("Resultado acumulado: %d\n", *somaPnt);
        } else {
            executarOperacao(somaPnt, numero, operacao);
        }

    }
    return 0;
}


#endif

#ifdef ex03

#include <stdio.h>

char listarLetras(char *letraPnr, char *vetor, int tamanho) {
    for (int x = 0; x < tamanho; x++) {
        if (*letraPnr == vetor[x]) {
            return *letraPnr;
        }
    }
    return '\0';  // Retorna '\0' se a letra não for encontrada
}

int main() {
    char vetor[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    char letra;
    printf("Digite uma letra: \n");
    scanf(" %c", &letra);

    char *letraPnr = &letra;
    char retorno = listarLetras(letraPnr, vetor, tamanho);

    if (retorno != '\0') {
        printf("A letra %c foi encontrada no vetor.\n", retorno);
    } else {
        printf("A letra %c nao foi encontrada no vetor.\n", letra);
    }

    return 0;
}


#endif // ex03

#ifdef ex04

/*  4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long */

struct Dados {
    char caractere;
    int inteiro;
    long longo;
    float flutuante;
    double duplo;
    unsigned char uCaractere;
    unsigned int uInteiro;
    unsigned long uLongo;
};

int receberDados(struct Dados *dados) {
    printf("Digite um caractere: ");
    scanf(" %c", &dados->caractere);

    printf("Digite um inteiro: ");
    scanf("%d", &dados->inteiro);

    printf("Digite um longo: ");
    scanf("%ld", &dados->longo);

    printf("Digite um flutuante: ");
    scanf("%f", &dados->flutuante);

    printf("Digite um duplo: ");
    scanf("%lf", &dados->duplo);

    printf("Digite um unsigned char: ");
    scanf(" %c", &dados->uCaractere);

    printf("Digite um unsigned inteiro: ");
    scanf("%u", &dados->uInteiro);

    printf("Digite um unsigned longo: ");
    scanf("%lu", &dados->uLongo);
}

int imprimirDados(struct Dados *dados) {
    printf("         10        20        30        40        50        60        70");
    printf("\n1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-10c%-10d%-20ld%-20f%-10lf \n", dados->caractere, dados->inteiro, dados->longo, dados->flutuante, dados->duplo);
    printf("          %-20c%-20u%lu\n", dados->uCaractere, dados->uInteiro, dados->uLongo);
}

int main() {
    struct Dados dados;

    receberDados(&dados);
    imprimirDados(&dados);

    return 0;
}

#endif // ex04

#ifdef ex05

struct Contato {
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[3];
    char cep[10];
};

int receberContatos(struct Contato *contatos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: ");
        scanf("%49s", contatos[i].nome);

        printf("Endereco: ");
        scanf("%49s", contatos[i].end);
        getchar();

        printf("Cidade: ");
        scanf("%49s", contatos[i].cidade);

        printf("Estado: ");
        scanf("%2s", contatos[i].estado);

        printf("CEP: ");
        scanf("%9s", contatos[i].cep);
    }
}

int imprimirContatos(struct Contato *contatos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\nDados do Contato %d:\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Endereco: %s\n", contatos[i].end);
        printf("Cidade: %s\n", contatos[i].cidade);
        printf("Estado: %s\n", contatos[i].estado);
        printf("CEP: %s\n", contatos[i].cep);
    }
}

int main() {
    struct Contato contatos[4];
    int opcao;
    int tamanho = sizeof(contatos) / sizeof(contatos[0]);

    do {
        printf("\nMenu:\n");
        printf("1. Receber Contatos\n");
        printf("2. Imprimir Contatos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                receberContatos(contatos, tamanho);
                break;
            case 2:
                imprimirContatos(contatos, tamanho);
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

#endif // ex05

#ifdef ex06

struct Contato {
    char nome[50];
    char endereco[50];
    char cidade[50];
    char estado[3];
    char cep[10];
};

int receberContatos(struct Contato *contatos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: ");
        scanf("%49s", contatos[i].nome);

        printf("Endereco: ");
        scanf("%49s", contatos[i].endereco);

        getchar(); // Limpar o buffer do teclado

        printf("Cidade: ");
        scanf("%49s", contatos[i].cidade);

        printf("Estado: ");
        scanf("%2s", contatos[i].estado);

        printf("CEP: ");
        scanf("%9s", contatos[i].cep);
    }
}

int imprimirContatos(struct Contato *contatos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\nDados do Contato %d:\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Endereco: %s\n", contatos[i].endereco);
        printf("Cidade: %s\n", contatos[i].cidade);
        printf("Estado: %s\n", contatos[i].estado);
        printf("CEP: %s\n", contatos[i].cep);
    }
}

int compararNomes(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }

    return *str1 == '\0' && *str2 == '\0';
}

int procurarContato(struct Contato *contatos, int tamanho, char *nomeProcurado) {
    for (int i = 0; i < tamanho; i++) {
        if (compararNomes(contatos[i].nome, nomeProcurado)) {
            printf("Contato encontrado:\n");
            imprimirContatos(&contatos[i], 1);
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

int alterarContato(struct Contato *contatos, int tamanho, char *nomeProcurado) {
    for (int i = 0; i < tamanho; i++) {
        if (compararNomes(contatos[i].nome, nomeProcurado)) {
            printf("Digite as novas informacoes para o Contato %d:\n", i + 1);
            receberContatos(&contatos[i], 1);
            printf("Contato alterado com sucesso.\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

int excluirContato(struct Contato *contatos, int *tamanho, char *nomeProcurado) {
    for (int i = 0; i < *tamanho; i++) {
        if (compararNomes(contatos[i].nome, nomeProcurado)) {
            for (int j = i; j < *tamanho - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*tamanho)--;
            printf("Contato excluido com sucesso.\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

int main() {
    struct Contato contatos[4];
    int tamanho = 0;
    int opcao;
    char nomeProcurado[50];

    do {
        printf("\nMenu:\n");
        printf("1. Receber Contatos\n");
        printf("2. Imprimir Contatos\n");
        printf("3. Procurar Contato\n");
        printf("4. Alterar Contato\n");
        printf("5. Excluir Contato\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                receberContatos(contatos, sizeof(contatos) / sizeof(contatos[0]));
                tamanho = sizeof(contatos) / sizeof(contatos[0]);
                break;
            case 2:
                imprimirContatos(contatos, tamanho);
                break;
            case 3:
                printf("Digite o nome do contato a ser procurado: ");
                scanf("%s", nomeProcurado);
                procurarContato(contatos, tamanho, nomeProcurado);
                break;
            case 4:
                printf("Digite o nome do contato a ser alterado: ");
                scanf("%s", nomeProcurado);
                alterarContato(contatos, tamanho, nomeProcurado);
                break;
            case 5:
                printf("Digite o nome do contato a ser excluido: ");
                scanf("%s", nomeProcurado);
                excluirContato(contatos, &tamanho, nomeProcurado);
                break;
            case 6:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

#endif // ex06
