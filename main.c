#include <stdio.h>
#include <stdlib.h>

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
