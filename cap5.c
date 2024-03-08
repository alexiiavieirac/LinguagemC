#include <stdio.h>
#include <stdlib.h>
#define ex01

// CAPÍTULO 5.

// ----------------------------------------------------------------------------------------

#ifdef ex01

    /*
        1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
            funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
            DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
            (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)
    */

char string1[10];
char string2[10];

int comparar(p1, p2)
{
    int cont = 0, cont2, x;
    cont2 = 1;
    while(cont < 10 && cont2 == 1) {
        if(string1[cont] == string2[cont]) {
            cont2 = 1;
        } else if(string1[cont] != string2[cont]) {
            cont2 = 0;
        }
        cont++;
    }
    return cont2;
}

int main()
{
    int arm;

    printf("Digite uma palavra: ");
    gets(&string1[0]);

    printf("Digite uma palavra: ");
    gets(&string2[0]);

    arm = comparar();

    printf("Resultado: %d", arm);

    return 0;
}

#endif //ex01

// ----------------------------------------------------------------------------------------

#ifdef ex02

    /*
        2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
            e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
            globais)

                    10        20        30        40        50
            12345678901234567890123456789012345678901234567890
            nome1                                   nome5
                        nome2               nome4
                                nome3

    */

char vet1[8];
char vet2[8];
char vet3[8];
char vet4[8];
char vet5[8];

int main()
{

    printf("Nome: ");
    gets(&vet1[0]);

    printf("Nome: ");
    gets(&vet2[0]);

    printf("Nome: ");
    gets(&vet3[0]);

    printf("Nome: ");
    gets(&vet4[0]);

    printf("Nome: ");
    gets(&vet5[0]);

    printf("                10        20        30        40        50\n");
    printf("        12345678901234567890123456789012345678901234567890\n");
    printf("        %-10s                                   %-50s\n", vet1, vet5);
    printf("                    %-20s               %-40s\n", vet2, vet4);
    printf("                              %-30s", vet3);

    return 0;
}
#endif // ex02

// ----------------------------------------------------------------------------------------

#ifdef ex03

    /*
        3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
            calcula o comprimento de uma string recebida via teclado. Mostre o valor do
            comprimento na funcao main().
            (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)
    */

int calcularComprimento(char str[])
{
    int comprimento = 0;

    while(str[comprimento] != '\0') {
        comprimento++;
    }
    return comprimento;
}

int main()
{
    char string[100];

    printf("Digite uma string: ");
    gets(&string[0]);

    int comprimento = calcularComprimento(string);

    printf("O comprimento da String: %d", comprimento);

    return 0;
}
#endif // ex03

// ----------------------------------------------------------------------------------------

#ifdef ex04

    /*
        4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
            para letras maiusculas. (nao pode usar funcao de biblioteca)
    */

int main()
{
    char vet[11];

    printf("Digite algo (max 10 caracteres): ");
    gets(vet);

    for(int i = 0; vet[i] != '\0'; i++) {
        // Esta condição verifica se o caractere atual em cadeia[i] é uma letra minúscula (no intervalo 'a' a 'z').
        if(vet[i] >= 'a' && vet[i] <= 'z') {
            vet[i] = vet[i] - 32;
        }
    }

    printf("A palavra em Maiuscula: %s", vet);

    return 0;
}
#endif // ex04

// ----------------------------------------------------------------------------------------

#ifdef ex05

    /*
        5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
            para letras minusculas. (nao pode usar funcao de biblioteca)
    */

int main()
{
    char vet[11];

    printf("Digite algo em letras MAIUSCULAS (max 10): ");
    gets(vet);

    for(int i = 0; vet[i] != '\0'; i++) {
        if(vet[i] >= 'A' && vet[i] <= 'Z') {
            vet[i] = vet[i] + 32;
        }
    }

    printf("A palavra em Minuscula: %s", vet);

    return 0;
}
#endif // ex05







