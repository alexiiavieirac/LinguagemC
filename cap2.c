#include <stdio.h>
#include <stdlib.h>
#define ex01

// CAPÍTULO 2.

//_________________________________________________________________________________________________________________________

#ifdef ex01

    /*
        1 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
            instantes em que a ligacao foi iniciada e concluida.
            Escreva um programa que recebe via teclado dois instantes dados em
            horas, minutos e segundo e determina o intervalo de tempo
            (em horas, minutos e segundos) decorrido entre eles.
    */

int main()
{
    char tecla;
    int inicioHoras, inicioMinutos, inicioSegundos;
    int fimHoras, fimMinutos, fimSegundos;
    int difHoras, difMin, difSeg;

    do{
        printf("Digite o instante de inicio (horas, minutos, segundos): ");
        scanf("%d %d %d", &inicioHoras, &inicioMinutos, &inicioSegundos);

        printf("Digite o instante do fim(horas, minutos, segundos): ");
        scanf("%d %d %d", &fimHoras, &fimMinutos, &fimSegundos);

        difSeg = fimSegundos - inicioSegundos;
        difMin = fimMinutos - inicioMinutos;
        difHoras = fimHoras - inicioHoras;

        if(difSeg < 0) {
            difSeg += 60;
            difMin--;
            break;
        }

        if(difMin < 0) {
            difMin += 60;
            difHoras--;
            break;
        }

        printf("Intervalo de Tempo: %dh %dmin %dseg\n", difHoras, difMin, difSeg);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &tecla);
    } while(tecla != 'n' && tecla != 'N');

    return 0;
}

#endif // ex01

//_________________________________________________________________________________________________________________________

#ifdef ex02

    /*
        2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
            pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
            comando if-else.
    */

int main()
{
    int minInferior = 1, maxSuperior = 99;
    int numero, chute;
    char resposta, tecla;

    printf("Pense em um numero entre 1 e 99.\n");

    do{
        do {
            numero = (minInferior + maxSuperior) / 2; // Chute o número do meio do intervalo.

            printf("O palpite e %d ?\n", numero);
            printf("Digite '=' se o palpite estiver correto.\n");
            printf("Digite '>' se o palpite for alto.\n");
            printf("Digite '<' se o palpite for baixo.\n");
            scanf(" %c", &resposta);

            if (resposta == '>') {
                minInferior = numero + 1; // O número pensado é maior que o chute.
            } else if (resposta == '<') {
                maxSuperior = numero - 1; // O número pensado é menor que o chute.
            }

        } while (resposta != '=');

        printf("O numero que voce pensou e: %d\n", numero);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &tecla);
    } while (tecla != 'n' && tecla != 'N');

    return 0;
}

#endif // ex02

//_________________________________________________________________________________________________________________________

#ifdef ex03

    /*
        3 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
            Conte o n. de tentativas e imprima o resultado no video.
    */

int main()
{
    int minInferior = 1, maxSuperior = 99;
    int numero, chute;
    char resposta, tecla;
    int tentativas = 0;

    printf("Pense em um numero entre 1 e 99.\n");

    do{
        do {
            numero = (minInferior + maxSuperior) / 2; // Chute o número do meio do intervalo.

            printf("O palpite e %d ?\n", numero);
            printf("Digite '=' se o palpite estiver correto.\n");
            printf("Digite '>' se o palpite for alto.\n");
            printf("Digite '<' se o palpite for baixo.\n");
            scanf(" %c", &resposta);

            switch (resposta) {
                case '=':
                    printf("Numero pensado: %d\n", numero);
                    break;
                case '>':
                    minInferior = numero + 1; // O número pensado é maior que o chute.
                    break;
                case '<':
                    maxSuperior = numero - 1; // O número pensado é menor que o chute.
                    break;
                default:
                    printf("Entrada inválida. Use '=', '>', ou '<'.\n");
                    break;
            }

            tentativas++;

        } while (resposta != '=');

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &tecla);
    } while (tecla != 'n' && tecla != 'N');

    return 0;
}

#endif // ex03

//_________________________________________________________________________________________________________________________

#ifdef ex04

    /*
        4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
            consumidos por um carro em um percurso.
            Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
            abaixo:
            CONSUMO (km/l) MENSAGEM
            menor que 8    Venda o carro!
            entre 8 e 14   Economico!
            maior que 14   Super economico!
    */

int main()
{
    char tecla;
    float litrosGasolina, km, consumo;

    do {
        printf("Quilometros rodados: ");
        scanf("%f", &km);

        printf("Quantidade de gasolina utilizada: ");
        scanf("%f", &litrosGasolina);

        consumo = (litrosGasolina / km);

        if (consumo < 8) {
            printf("Consumo: %.2f km/l.\n", consumo);
            printf("Venda o carro!");
        } else if (consumo >= 8 && consumo <= 14) {
            printf("Consumo: %.2f km/l.\n", consumo);
            printf("Economico!");
        } else {
            printf("Consumo: %.2f km/l.\n", consumo);
            printf("Super economico!");
        }

        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &tecla);

    } while (tecla != 'n' && tecla != 'N');

    return 0;
}

#endif // ex04

//_________________________________________________________________________________________________________________________

#ifdef ex05

    /*
        5 - Escreva um programa que receba via teclado numeros inteiros positivos.
            Quando o numero digitado for negativo o programa deve parar e calcula a
            media dos valores positivos digitados.
    */

int main()
{
    char tecla;
    int numero, contador = 0, soma = 0;

    do {
        while (1) {
            printf("Digite um numeros: ");
            scanf("%d", &numero);

            if (numero < 0) {
                break;
            }

            soma = soma + numero;
            contador++;
         }

         if (contador > 0) {
            float media = (float) soma / contador;
            printf("Media dos numeros positivos: %.2f\n", media);
         } else {
            printf("Nenhum numero positivo foi inserido.\n");
         }

        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &tecla);
    } while (tecla != 'n' && tecla != 'N');

    return 0;
}

#endif // ex05

//_________________________________________________________________________________________________________________________
