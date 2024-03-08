#include <stdio.h>
#include <stdlib.h>
#define ex01

// CAPÍTULO 1.

//_________________________________________________________________________________________________________________________

#ifdef ex01

    /*
        1 - Escreva um programa que receba via teclado um tempo em segundos e converta
            para horas, minutos e segundos.
            Ex.: recebe 3850 segundos que converte para 1h 4min 10s.
    */

int main()
{
    int totalSegundos, horas, minutos, segundos;

    printf("Digite os segundos: ");
    scanf("%d", &totalSegundos);

    horas = totalSegundos / 3600;
    totalSegundos = totalSegundos % 3600;

    minutos = totalSegundos / 60;
    segundos = totalSegundos % 60;

    printf("Tempo convertido: %dh %dmin %ds", horas, minutos, segundos);
}

#endif // ex01

//_________________________________________________________________________________________________________________________

#ifdef ex02

    /*
        2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
            long, int, float, double e um char e imprima-os no video no seguinte
            formato:

                     10        20        30        40        50        60
             12345678901234567890123456789012345678901234567890123456789012345
                 short               long                int
                           float               double              char
    */

main()
{
    short shortVar;
    long longVar;
    int intVar;
    float floatVar;
    double doubleVar;
    char charVar;

    printf("Digite um valor Short: ");
    scanf("%hd", &shortVar);

    printf("Digite um valor Long: ");
    scanf("%ld", &longVar);

    printf("Digite um valor Int: ");
    scanf("%d", &intVar);

    printf("Digite um valor Float: ");
    scanf("%f", &floatVar);

    printf("Digite um valor Double: ");
    scanf("%lf", &doubleVar);

    printf("Digite um caractere: ");
    scanf(" %c", &charVar);

    printf("\n        10        20        30        40        50        60         70       80        90\n");
    printf("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("       %-10hd          %-30ld%-50d\n", shortVar, longVar, intVar);
    printf("             %-20.2f %-40.2lf   %-60c", floatVar, doubleVar, charVar);

    return 0;
}

#endif // ex02

//_________________________________________________________________________________________________________________________

#ifdef ex03

    /*
        3 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
            variável auxiliar.
    */

int main()
{
    int totalSegundos, horas, minutos, segundos;

    printf("Digite os segundos: ");
    scanf("%d", &totalSegundos);

    horas = totalSegundos / 3600;
    totalSegundos = totalSegundos % 3600;

    minutos = totalSegundos / 60;
    segundos = totalSegundos % 60;

    printf("Tempo convertido: %dh %dmin %ds", horas, minutos, segundos);
}

#endif // ex03

//_________________________________________________________________________________________________________________________

#ifdef ex04

    /*
        4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
            outro número formado pelos dígitos invertidos do número lido.
            Ex: NúmeroLido = 123
                NúmeroGerado = 321
    */

int main()
{
    int numero_lido, numero_gerado = 0;

    printf("Digite um numero inteiro, positivo de tres digitos: ");
    scanf("%d", &numero_lido);

    printf("Numero lido: %d\n", numero_lido);

    if (numero_lido >= 100 && numero_lido <= 999) {

        /* Aqui começa o processo de inversão dos dígitos.
        O loop while executa enquanto o numeroLido for maior que zero.
        A cada iteração do loop, a variável digito recebe o último dígito do numeroLido usando a operação de módulo % 10.
        O numeroGerado é atualizado multiplicando por 10 e somando o dígito, o que move os dígitos existentes para a esquerda e insere o novo dígito na unidade.
        A linha numeroLido /= 10; remove o último dígito do numeroLido, avançando para o próximo dígito da direita. */

        while (numero_lido > 0) {
            int digito = numero_lido % 10;
            numero_gerado = numero_gerado * 10 + digito;
            numero_lido = numero_lido / 10;
        }
        printf("Numero gerado: %d", numero_gerado);
    } else {
        printf("O numero deve ser positivo e ter tres numeros.");
    }

    return 0;
}

#endif // ex04

//_________________________________________________________________________________________________________________________

#ifdef ex05

    /*
        5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
            multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
            teclado.
            Ex: menor multiplo de 13 maior que 100. Resultado: 104.
    */

int main()
{
    int numero, limiteMinimo;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("Digite o limite minimo: ");
    scanf("%d", &limiteMinimo);

    /* Para encontrar o próximo múltiplo de 13 após 100, precisamos dividir 100 por 13 e arredondar para cima, obtendo 8.
    Ou seja, existem 8 múltiplos de 13 que são menores ou iguais a 100 (8 * 13 = 104).
    Portanto, o próximo múltiplo após 100 é 104.*/

    int multiplo = (limiteMinimo / numero + 1) * numero;

    printf("O menor multiplo de %d maior que %d, e: %d.", numero, limiteMinimo, multiplo);

    return 0;
}

#endif // ex05

//_________________________________________________________________________________________________________________________
