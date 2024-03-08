#include <stdio.h>
#include <stdlib.h>
#define ex01

// CAPÍTULO 6.

// ______________________________________________________

#ifdef ex01

    /*
        1 - Escreva um programa que receba via teclado 2 numeros inteiros e
            imprima-os no video com o resultado das 4 operacoes aritmeticas.
    */

int main()
{
    int numero1, numero2, soma, multiplicacao, subtracao;
    float divisao;

    printf("Informe um numero: ");
    scanf("%i", &numero1);

    printf("Informe mais um numero: ");
    scanf("%i", &numero2);

    soma = numero1 + numero2;
    subtracao = numero1 - numero2;
    multiplicacao = numero1 * numero2;

    if(numero2 != 0) {
        divisao = numero1 / numero2;
    } else {
        printf("Erro. Divisao por zero.");
    }

    printf("Soma -> %i + %i = %i\n", numero1, numero2, soma);
    printf("Subtracao -> %i - %i = %i\n", numero1, numero2, subtracao);
    printf("Multiplicacao -> %i * %i = %i\n", numero1, numero2, multiplicacao);
    printf("Divisao -> %i / %i = %.1f \n", numero1, numero2, divisao);

    return 0;
}
#endif // ex01

// ______________________________________________________

#ifdef ex02

    /*
        2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
            composta.
    */

int main()
{
    int x, y, z;
    float w;

    printf("Informe um numero: ");
    scanf("%i", &x);

    printf("Informe mais um numero: ");
    scanf("%i", &y);

    printf("Informe mais um numero: ");
    scanf("%i", &z);

    printf("Informe mais um numero: ");
    scanf("%f", &w);

    x += x;
    y -= y;
    z *= z;
    w /= w;

    printf("Soma -> %i\n", x);
    printf("Subtracao -> %i\n", y);
    printf("Multiplicacao -> %i\n", z);
    printf("Divisao -> %.2f\n", w);

    return 0;
}
#endif // ex02

// ______________________________________________________

#ifdef ex03

    /*
        3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
            dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
            data (dia, mes e ano) atual.
    */

int main()
{
    int dia_nasc, mes_nasc, ano_nasc;
    int dia_autal, mes_atual, ano_atual;
    int dias, meses, anos;

    printf("Dia do Nascimento: ");
    scanf("%i", &dia_nasc);

    printf("Mes do Nascimento: ");
    scanf("%i", &mes_nasc);

    printf("Ano do Nascimento: ");
    scanf("%i", &ano_nasc);

    printf("________________________________________________________\n");

    printf("Data do seu Nascimento: %i/%i/%i", dia_nasc, mes_nasc, ano_nasc);

    printf("\n________________________________________________________\n");

    printf("Dia de Hoje: ");
    scanf("%i", &dia_autal);

    printf("Mes atual: ");
    scanf("%i", &mes_atual);

    getchar();

    printf("Ano atual: ");
    scanf("%i", &ano_atual);

    printf("________________________________________________________\n");

    anos = ano_atual - ano_nasc;

    meses = mes_atual - mes_nasc;

    dias = dia_autal - dia_nasc;

    if(dias < 0) {
        meses--;
        dias += 30;
    }

    if(meses < 0) {
        anos--;
        meses += 12;
    }

    printf("Idade: %i anos, %i meses, %i dias",anos, meses, dias);

    return 0;
}
#endif // ex03

// ______________________________________________________

#ifdef ex04

    /*
        4 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
            Determine o dia da semana desta data.
    */

int main()
{
    int dia, mes, ano;

    printf("Dia de Hoje: ");
    scanf("%i", &dia);

    printf("Mes atual: ");
    scanf("%i", &mes);

    printf("Ano atual: ");
    scanf("%i", &ano);

    printf("________________________________________________________\n");

    printf("Data: %i/%i/%i\n", dia, mes, ano);

    if(mes < 3) {
        mes += 12;
        ano--;
    }

    int K = ano % 100;
    int J = ano / 100;

    int diaSemana = (dia + ((13 * (mes + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    //0 - Sabado; 1 - Domingo; 2 - Segunda; 3 - Terca; 4 - Quarta; 5 - Quinta; 6 - Sexta.

    const char* dia_Semana[] = {"Sabado", "Domingo", "Segunda-Feira", "Terca-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira"};

    printf("Dia da Semana: %s", dia_Semana[diaSemana]);

    return 0;
}
#endif // ex04

// ______________________________________________________

#ifdef ex05

    /*
        5 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
            as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
            video no formato decimal e hexadecimal.
    */

int main()
{
    int numero1, numero2;

    printf("________________________________________________________\n");

    printf("Informe um numero: ");
    scanf("%d", &numero1);

    printf("Informe mais um numero: ");
    scanf("%d", &numero2);

    int andResultado = numero1 & numero2;
    int orResultado = numero1 | numero2;
    int xOrResultado = numero1 ^ numero2;

    printf("________________________________________________________\n");

    printf("AND: \n");
    printf("Decimal: %d\n", andResultado);
    printf("Hexadecimal: 0x%x", andResultado);

    printf("\n________________________________________________________\n");

    printf("OR: \n");
    printf("Decimal: %d\n", orResultado);
    printf("Hexadecimal: 0x%x", orResultado);

    printf("\n________________________________________________________\n");

    printf("XOR: \n");
    printf("Decimal: %d\n", xOrResultado);
    printf("Hexadecimal: 0x%x", xOrResultado);

    printf("\n________________________________________________________\n");

    return 0;
}
#endif // ex05

// ______________________________________________________
