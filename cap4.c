#include <stdio.h>
#include <stdlib.h>
#define ex05

// CAPÍTULO 4.

//_________________________________________________________________________________________________________________________

#ifdef ex01

    /*
        1 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
            decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
            e o outro tera´ as componentes de ordem par.
            Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
            deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.
    */

    int Victor[10];
    int Impares[5];
    int Pares[5];

int main()
{
    int p = 0;
    int i = 0;

    for (int x = 0; x < 10; x++){
    printf("\nDigite um numero: \n");
    scanf("%i \n", &Victor[x]);

        if (Victor[x] % 2) {
            Pares[p] = Victor[x];
            p++;
        } else {
            Impares[i] = Victor[x];
            i++;
        }
    }

    printf("\nOs numeros digitados foram: \n");

    for (int x = 0; x < 10; x++){
        printf("\n %i \n", Victor[x]);
    }

    printf("\nOs numeros pares foram: \n");

    for (int x = 0; x < 5; x++){
        printf("\n %i \n", Pares[x]);
    }
    printf("\nOs numeros impares foram: \n");

    for (int x = 0; x < 5; x++){
        printf("\n %i \n", Impares[x]);
    }

    return 0;
}

#endif // ex01

//_________________________________________________________________________________________________________________________

#ifdef ex02

    /*
        2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
            decomponha em dois outros vetores. Um tera� as componentes de valor impar
            e o outro tera� as componentes de valor par.
            Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
            programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.
    */

    int Victor[10];
    int Impares[10];
    int tamP;
    int tamI;
    int Pares[10];

int main()
{
    int p = 0;
    int i = 0;

    for (int x = 0; x < 10; x++){
    printf("\nDigite um numero: \n");
    scanf("%i \n", &Victor[x]);

        if (Victor[x] % 2 == 0) {
            Pares[p] = Victor[x];
            p++;
        } else {
            Impares[i] = Victor[x];
            i++;
        }
    }

    printf("\nOs numeros digitados foram: \n");

    for (int x = 0; x < 10; x++){
        printf("\n %i \n", Victor[x]);
    }

    printf("\nOs numeros pares foram: \n");

    for (int x = 0; x < 10; x++){
        printf("\n %i \n", Pares[x]);
    }
    printf("\nOs numeros impares foram: \n");

    for (int x = 0; x < 10; x++){
        printf("\n %i \n", Impares[x]);
    }

    return 0;
}

#endif // ex02

//_________________________________________________________________________________________________________________________

#ifdef ex03

    /*
        3 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
            que recebe os dados via teclado para esses 2 vetores. Usando o operador
            adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
            resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
            dos 6 elementos dos vetores.
    */

    int vet1[2][3];
    int vet2[2][3];
    int vet3[2][3];

int main()
{
    char tecla;

    do{
        for(int x = 0; x < 2; x++) {
            for(int y = 0; y < 3; y++) {
                printf("Digite um numero: ");
                scanf("%i", &vet1[x][y]);
            }
        }

        printf("OIII");

        for(int x = 0; x < 2; x++) {
            for(int y = 0; y < 3; y++) {
                printf("Digite um numero: ");
                scanf("%i", &vet2[x][y]);
            }
        }
        printf("Deseja continuar? (n/y) ");
        getchar();
        tecla = getchar();

    }while(tecla == 'y' || tecla == 'Y');

    return 0;
}

#endif // ex03

//_________________________________________________________________________________________________________________________

#ifdef ex04

    /*
        4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
            que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
            ordenados.
    */

int main() {
   int valores[10];

    do{
       printf("Digite 10 numeros inteiros:\n");
       for (int i = 0; i < 10; i++) {
           printf("Digite o %do numero: ", i + 1);
           scanf("%d", &valores[i]);

           for (int j = i; j > 0 && valores[j] < valores[j - 1]; j--) {
               int temp = valores[j];
               valores[j] = valores[j - 1];
               valores[j - 1] = temp;
           }
       }

       printf("\nValores ordenados:\n");
       for (int i = 0; i < 10; i++) {
           printf("%d ", valores[i]);
       }

        printf("\n");

        printf("Deseja continuar? (n/y) ");
        getchar();
        tecla = getchar();

    } while(tecla == 'y' || tecla == 'Y');

   return 0;
}
#endif // ex04

//_________________________________________________________________________________________________________________________

#ifdef ex05

/*
        5 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
            3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

                    10        20        30        40        50
            12345678901234567890123456789012345678901234567890
              int                 long                unsigned
                        float               double
              int                 long                unsigned
                        float               double
              int                 long                unsigned
                        float               double
    */

int num1, num2, num3;
long longo1, longo2, longo3;
unsigned NA1, NA2, NA3;
float flutuante1, flutuante2, flutuante3;
double duplo1, duplo2, duplo3;
char tecla;

int main(){

    do{

    printf("Insira numeros inteiros: \n");
    scanf("%i", &num1);

    printf("Insira numeros inteiros: \n");
    scanf("%i", &num2);

    printf("Insira numeros inteiros: \n");
    scanf("%i", &num3);

    printf("Insira valores long: \n");
    scanf("%ld", &longo1);

    printf("Insira valores long: \n");
    scanf("%ld", &longo2);

    printf("Insira valores long: \n");
    scanf("%ld", &longo3);

    printf("Insira valores unsigned: \n");
    scanf("%lu", &NA1);

    printf("Insira valores unsigned: \n");
    scanf("%lu", &NA2);

    printf("Insira valores unsigned: \n");
    scanf("%lu", &NA3);

    printf("Insira valores flutuantes: \n");
    scanf("%f", &flutuante1);

    printf("Insira valores flutuantes: \n");
    scanf("%f", &flutuante2);

    printf("Insira valores flutuantes: \n");
    scanf("%f", &flutuante3);

    printf("Insira valores duplos: \n");
    scanf("%lf", &duplo1);

    printf("Insira valores duplos: \n");
    scanf("%lf", &duplo2);

    printf("Insira valores duplos: \n");
    scanf("%lf", &duplo3);

    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-19i %-19ld %u\n", num1, longo1, NA1);
    printf("            %-19f %lf\n", flutuante1, duplo1);
    printf("  %-19i %-19ld %u\n", num2, longo2, NA2);
    printf("            %-19f %lf\n", flutuante2, duplo2);
    printf("  %-19i %-19ld %u\n", num3, longo3, NA3);
    printf("            %-19f %lf\n", flutuante3, duplo3);

    printf("Deseja continuar? (n/y) ");
        getchar();
        tecla = getchar();

    }while(tecla == 'y' || tecla == 'Y');
        return 0;
}


#endif // ex05

//_________________________________________________________________________________________________________________________





















