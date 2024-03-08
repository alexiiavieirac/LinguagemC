#include <stdio.h>
#include <stdlib.h>
#define ex01


#ifdef ex01

/*  1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global */

char palavra1[11];
char palavra2[11];

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

#endif // 01

#ifdef ex02

/*  2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */

    char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

char listarLetras (char letra, char *vetor) {

    for(int x = 0; x < 13; x++) {

        if (letra == vetor[x]){

            return vetor[x];

        }

        else{
            printf("%c \n", vetor[x]);

        }

    }

    return;

}

int main (){

    char letra;

    printf("Digite uma letra: \n");
    scanf("%c", &letra);

    char retorno = listarLetras(letra, vetor);

    printf("%c\n", retorno); // A letra pesquisada para so valor igual, caso contrário roda tudo até o final.

    return 0;
}

#endif // ex02

#ifdef ex03

/* Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char */

int main() {
    short shortVar;
    long longVar;
    int intVar;
    float floatVar;
    double doubleVar;
    char charVar;
    unsigned long UnsLg;
    unsigned char UnsCr;

    short *srtPnt = &shortVar;
    long *lngPnt = &longVar;
    int *inPnt = &intVar;
    float *fltPnt = &floatVar;
    double *dbPnt = &doubleVar;
    char *cPnt = &charVar;
    unsigned long *UnsLP = &UnsLg;
    unsigned char *UnsCP = &UnsCr;

    printf("Digite um valor Short: ");
    scanf("%hd", srtPnt);

    printf("Digite um valor Long: ");
    scanf("%ld", lngPnt);

    printf("Digite um valor Int: ");
    scanf("%d", inPnt);

    printf("Digite um valor Float: ");
    scanf("%f", fltPnt);

    printf("Digite um valor Double: ");
    scanf("%lf", dbPnt);

    printf("Digite um caractere: ");
    scanf(" %c", cPnt);
    getchar();

    printf("Digite um valor long: ");
    scanf("%lu", UnsLP);
    getchar();

    printf("Digite um caractere: ");
    scanf(" %c", UnsCP);

    printf("\n        10        20        30        40        50        60         70       80        90\n");
    printf("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-20hd%-20ld%d\n", *srtPnt, *lngPnt, *inPnt);
    printf("              %-20.2f%-20.2lf%c\n", *fltPnt, *dbPnt, *cPnt);
    printf("         %-20lu%-20c\n", *UnsLP, *UnsCP);

    return 0;
}

#endif // ex03

#ifdef ex04

/*  4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro. */

    int main() {
    char tecla;
    int numero, contador = 0, soma = 0;

    int *numPrt = &numero;
    int *somaPrt = &soma;

    do {
        while (1) {
            printf("Digite um numero: \n");
            scanf("%d", numPrt);

            if (*numPrt < 0) {
                break;
            }

            *somaPrt += *numPrt;
            contador++;
        }

        if (contador > 0) {
            float media = (float)(*somaPrt) / contador;
            printf("Media dos numeros positivos: %.2f\n", media);
        } else {
            printf("Nenhum numero positivo foi inserido.\n");
        }

        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &tecla);
    } while (tecla != 'n' && tecla != 'N');

    return 0;
}
#endif // ex04


#ifdef ex05

/*  5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
    estrutura: nome, end, cidade, estado, cep */

struct Contato {
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[3];
    char cep[10];
};

// Variável global para o vetor de estruturas
struct Contato contatos[4];

// Função para receber dados via teclado
void receberContato(struct Contato *contato) {
    printf("Nome: ");
    scanf("%49s", contato->nome);

    printf("Endereco: ");
    scanf("%49s", contato->end);

    getchar(); // Limpar o buffer do teclado

    printf("Cidade: ");
    scanf("%49s", contato->cidade);

    printf("Estado: ");
    scanf("%2s", contato->estado);

    printf("CEP: ");
    scanf("%9s", contato->cep);
}

// Função para imprimir dados usando ponteiros
void imprimirContato(struct Contato *contato) {
    printf("Nome: %s\n", contato->nome);
    printf("Endereco: %s\n", contato->end);
    printf("Cidade: %s\n", contato->cidade);
    printf("Estado: %s\n", contato->estado);
    printf("CEP: %s\n", contato->cep);
}

// Função principal
int main() {
    int tamanho = sizeof(contatos) / sizeof(contatos[0]);

    // Loop para receber dados
    for (int i = 0; i < tamanho; i++) {
        printf("Contato %d:\n", i + 1);
        receberContato(&contatos[i]);
    }

    // Loop para imprimir dados
    for (int i = 0; i < tamanho; i++) {
        printf("\nDados do Contato %d:\n", i + 1);
        imprimirContato(&contatos[i]);
    }

    return 0;
}

#endif // ex05

#ifdef ex06

/*  6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    estrutura: dia, mes e ano */

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int main() {
    Data data1, data2;
    Data *ptr1 = &data1;
    Data *ptr2 = &data2;

    printf("Digite a primeira data (DD MM AAAA): Ps: 'De os espaços para calcular corretamente.'");
    scanf("%d %d %d", &(ptr1->dia), &(ptr1->mes), &(ptr1->ano));

    printf("Digite a segunda data (DD MM AAAA): ");
    scanf("%d %d %d", &(ptr2->dia), &(ptr2->mes), &(ptr2->ano));

    int dias1 = ptr1->dia + ptr1->mes * 30 + ptr1->ano * 365;
    int dias2 = ptr2->dia + ptr2->mes * 30 + ptr2->ano * 365;

    int diferenca = dias2 - dias1;

    printf("O numero de dias entre as duas datas e: %d\n", diferenca);

    return 0;
}

#endif // ex06
