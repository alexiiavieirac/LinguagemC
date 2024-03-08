#include <stdio.h>
#include <stdlib.h>
#define ex01

// CAPÍTULO 3.

//_________________________________________________________________________________________________________________________

#ifdef ex01
    /*
        1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
            que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
            mostrado na funcao main().
            Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.
    */

main()
{
    int loop = 1;
    while (loop == 1)
    {
        int entrada = 0;
        int fatorial = 1;

        printf("Digite um numero: ");
        scanf("%i", &entrada);

        while (entrada > 0)
        {
            fatorial *= entrada;
            entrada--;
        }

        printf("Fatorial: %i\n", fatorial);
        printf("Vamos somar os algarismos: \n");
        somaAlgarismos(fatorial);
        printf("\nQuer fazer de novo ? (y/n) ");
        scanf("%i", &loop);
    }

    return 0;
}

somaAlgarismos(int num) {
        int algarismoSoma = 0;
        printf("A soma fica: ");

        while (num > 0) {
            algarismoSoma += (num % 10);
            printf("%i", num%10);
            printf("+");
            num /= 10;
        }
        printf(" = %i", algarismoSoma);
    }
#endif // ex01

//_________________________________________________________________________________________________________________________

#ifdef ex02
    /*
        2 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
            funçoes:
            -   Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
                retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
            -   Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
                eles.
            -   Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
                entre eles.
            -   Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.
    */

int main ()
{
    int numero1, numero2, checado, resultado;

    int check(int a, int b) {

        if(a > 0 && b > 0) return 1;
        if(a < 0 && b < 0) return 0;
        return -1;
    }

    int somar(int x, int y) {
        int resp;

        resp = x + y;
        return resp;
    }

    int multi(int x, int y) {
        int resp;

        resp = x * y;
        return resp;
    }

    int divs(int x, int y) {
        int resp;

        resp = x / y;
        return resp;
    }

    printf("Insira um numero: ");
    scanf("%i", &numero1);

    printf("Insira outro numero: ");
    scanf("%i", &numero2);

    checado = check(numero1, numero2);

    if (checado > 0){
        resultado = somar(numero1, numero2);
    }
    else if (checado < 0) {
        resultado = divs(numero1, numero2);
    }
    else {
        resultado = multi(numero1, numero2);
    }

    printf("Resultado: %i", resultado);
}
#endif // ex02

//_________________________________________________________________________________________________________________________

#ifdef ex03
    /*
        3 - Escreva um programa que receba na funcao main() 2 valores inteiros. Escreva
            uma funcao para cada operacoes aritmeticas e passe como parametro os 2
            valores recebidos na funcao main(). Retorne os resultados usando o comando
            return e imprima os 4 resultados no video na funcao main().
    */

    int somaAlgarismos(int x, int y) {
        int resposta = 0;
            resposta = x + y;
        return resposta;
    }
    int diferencaAlgarismos(int x, int y) {
        int resposta;
            resposta = x - y;
        return resposta;
    }
    int multiplicacaoAlgarismos(int x, int y) {
        int resposta;
            resposta = x * y;
        return resposta;
    }
    int divisaoAlgarismos(int x, int y) {
        int resposta;
            resposta = x / y;
        return resposta;
    }

int main() {

    char pararPrograma;
    int primeiroValor, segundoValor, resultado;

     do {
        printf("Informe o primeiro valor: ");
        scanf("%i", &primeiroValor);

        printf("Informe o segundo valor: ");
        scanf("%i", &segundoValor);

        resultado = somaAlgarismos(primeiroValor, segundoValor);
        printf("%i + %i = %i\n", primeiroValor, segundoValor, resultado);

        resultado = diferencaAlgarismos(primeiroValor, segundoValor);
        printf("%i - %i = %i\n", primeiroValor, segundoValor, resultado);

        resultado = multiplicacaoAlgarismos(primeiroValor, segundoValor);
        printf("%i * %i = %i\n", primeiroValor, segundoValor, resultado);

        resultado = divisaoAlgarismos(primeiroValor, segundoValor);
        printf("%i / %i = %i\n", primeiroValor, segundoValor, resultado);

        printf("\nDeseja continuar? (y/n) ");
        getchar();
        pararPrograma = getchar();
    } while(pararPrograma == 'y' || pararPrograma == 'Y');
}
#endif // ex03

//_________________________________________________________________________________________________________________________

#ifdef ex04
    /*
        4 - Reescreva o programa do exercicio anterior para receber via teclado n
            valores. Os n valores nao sao definidos previamente.
    */

    int somaAlgarismos(int x, int y) {
        return x + y;
    }
    int diferencaAlgarismos(int x, int y) {
        return x - y;
    }
    int multiplicacaoAlgarismos(int x, int y) {
        return x * y;
    }
    int divisaoAlgarismos(int x, int y) {
        return x / y;
    }

int main() {

    char pararPrograma;
    int n;
    int valores[n];

    printf("Quantidade de numeros: ");
    scanf("%i", &n);


    for (int i = 0; i < n;i++) {
        printf("Informe o valor %i: ", i + 1);
        scanf("%i", &valores[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("As operacoes entre %i e %i sao essas abaixo: \n", valores[i], valores[j]);
            printf("Soma: %i\n", somaAlgarismos(valores[i], valores[j]));
            printf("Subtracao: %i\n", diferencaAlgarismos(valores[i], valores[j]));
            printf("Multiplicacao: %i\n", multiplicacaoAlgarismos(valores[i], valores[j]));
            printf("Divisao: %i\n", divisaoAlgarismos(valores[i], valores[j]));
        }
    }
}
#endif // ex04

//_________________________________________________________________________________________________________________________

#ifdef ex05
    /*
       5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
           Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
           As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
           mostrado na funcao main().
    */

int operacaoSomar(int x, int y)
{
    return x + y;
}

int operacaoSubtracao(int x, int y)
{
    return x - y;
}

float operacaoDivisao(int x, int y)
{
    if(y != 0) {
        return (float)x / y;
    }
    else {
        printf("Erro. Divisao por zero!\n");
        return 0.0;
    }
}

int operacaoMultiplicacao(int x, int y)
{
    return x * y;
}

int main()
{
    int escolha, numero1, numero2;
    float resultado;
    char tecla;

    do{
        printf("___________________________________________________\n");

        printf("Operacoes: \n");
        printf("1. + (Soma)\n");
        printf("2. - (Subtracao)\n");
        printf("3. / (Divisao)\n");
        printf("4. * (Multiplicacao)\n");

        printf("___________________________________________________\n");

        printf("Informe um numero: ");
        scanf("%d", &numero1);

        printf("Informe mais um numero: ");
        scanf("%d", &numero2);

        printf("___________________________________________________\n");

        printf("Escolha a Operacao que voce deseja realizar: ");
        scanf("%d", &escolha);

        printf("___________________________________________________\n");

        switch(escolha)
        {
            case 1:
                resultado = operacaoSomar(numero1, numero2);
            break;

            case 2:
                resultado = operacaoSubtracao(numero1, numero2);
            break;

            case 3:
                resultado = operacaoDivisao(numero1, numero2);
            break;

            case 4:
                resultado = operacaoMultiplicacao(numero1, numero2);
            break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                continue;
        }

        printf("Voce escolheu a %d a. opcao.\n", escolha);

        if(escolha == 3) {
            printf("Resultado: %.2f\n", resultado);
        }
        else {
            printf("Resultado: %d\n", (int)resultado);
        }
        printf("___________________________________________________\n");

        printf("Deseja continuar? (y/n) ");
        getchar();
        tecla = getchar();
    }while(tecla == 'y' || tecla == 'Y');

    return 0;
}

#endif // ex05

//_________________________________________________________________________________________________________________________
