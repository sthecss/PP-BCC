#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "funcoes.h"

#define LIMITE 2000000

int lerInt() {
    int valor;
    printf("->");
    scanf("%d", &valor);
    return valor;
}
float lerFloat() {
    float valor;
    printf("->");
    scanf("%f", &valor);
    return valor;
}
char lerChar() {
    char valor;
    printf("->");
    scanf(" %c", &valor);
    return toupper(valor);
}

void somaMultiplos3e5() {
    int num = 1, testeDoTres, testeDoCinco, meta = 1000, soma=0;

    do
    {
        testeDoTres = num % 3;      testeDoCinco = num % 5;

        if (testeDoTres==0)
            soma = soma + num;
        else if (testeDoCinco==0)
            soma = soma + num;
        num++;
    } while (num < meta);

    printf("\n- A soma de todos os numeros abaixo de 1000, multiplos de 3 ou 5 eh de: [ %d ].", soma);
}
void distribuicaoLancamentos2d6() {
    int d1, d2, vezes, i;

    srand(time(NULL));

    printf("\n-> Quer rodar os dados quantas vezes? ");
    vezes= lerInt();

    printf("\n- - Sera rodado %d vezes os dados! - - \n", vezes);

    for (i = 0; i < vezes; i++)
    {
        printf("\n- Vamos girar os dados...\n");
        sleep(1);

        d1 =  1 + ( rand() % 6 );
        d2 =  1 + ( rand() % 6 );

        printf("\n- Dado 1: %d", d1);
        printf("\n- Dado 2: %d\n", d2);

        if (d1 > d2)
            printf("[ D1 > D2 ]\n");
        else if (d1 < d2)
            printf("[ D2 > D1 ]\n");
        else if (d1 == d2)
            printf("[ D1 = D2 ]\n");
    }

}
void calcularPotenciasRaiz() {
    float quad, cubo, raiz;

    while (1) {
        printf("\n[ Digite um numero negativo para sair ]"
                     "\n-> Digite o numero: ");
        float num = lerFloat();

        if (num < 0)
            break;

        quad = num * num;
        cubo = num * num * num;
        raiz = sqrt(num);

        printf("\n- Quadrado : %.2f", quad);
        printf("\n- Cubo     : %.2f", cubo);
        printf("\n- Raiz     : %.2f\n", raiz);
    }
}
void calculadoraBasica() {
    int nUm, nDois, op;

    do {
        // Menu de opções
        printf("\nCalculadora!\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n");
        printf("Digite o numero referente a operacao que deseja realizar: ");
        op = lerInt();

        if (op < 1 || op > 5) {
            printf("> > Opcao invalida. Tente novamente. < <\n");
            continue;
        }

        if (op == 5) {
            printf("\n[ Voltando... ]\n");
            return;
        }

        printf("\n-> Digite o primeiro numero: ");
        nUm = lerInt();

        printf("\n-> Digite o segundo numero: ");
        nDois = lerInt();

        switch (op) {
            case 1: // Adição
                printf("\n-> A soma eh igual a: %d\n", nUm + nDois);
            break;

            case 2: // Subtração
                printf("\n-> A subtracao eh igual a: %d\n", nUm - nDois);
            break;

            case 3: // Multiplicação
                printf("\n-> A multiplicacao eh igual a: %d\n", nUm * nDois);
            break;

            case 4: // Divisão
                if (nDois != 0) {
                    printf("\n-> A divisao eh igual a: %.2f\n", (float)nUm / nDois); // Usando float para resultado decimal
                } else {
                    printf("Erro: Divisao por zero nao permitida.\n");
                }
            break;
        }
    } while (op != 5); // Repetir até que o usuário escolha sair
}
void saqueCaixaEletronico() {
    int saque;

    printf("\n[ Serão entregues apenas valores inteiros ] ");

    printf("\n-> Digite o valor do saque: ");
    scanf("%d", &saque);

    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    int quantidadeNotas;

    printf("\nNotas entregues:\n");

    for (int i = 0; i < 7; i++) {
        quantidadeNotas = saque / notas[i]; // Calcula a quantidade de notas necessárias

        if (quantidadeNotas > 0) {
            printf("- %d nota(s) de R$%d\n", quantidadeNotas, notas[i]);
            saque = saque % notas[i]; // Atualiza o valor restante do saque
        }
    }

    if (saque > 0)
        printf("\nErro: O valor do saque nao pode ser atendido com as notas disponiveis.\n");
}
void somaNumerosAbaixoDoisMilhoes() {
    bool ehPrimo[LIMITE + 1];
    long long soma = 0;

    for (int i = 2; i <= LIMITE; i++) { // Inicializa o array, assumindo que todos os números são primos
        ehPrimo[i] = true;
    }

    for (int i = 2; i <= sqrt(LIMITE); i++) {
        if (ehPrimo[i])
            for (int j = i * i; j <= LIMITE; j += i) // Marca todos os múltiplos de i como não primos
                ehPrimo[j] = false;

    }

    for (int i = 2; i <= LIMITE; i++) {
        if (ehPrimo[i])
            soma += i;
    }

    printf("\n[ A soma dos primos abaixo de %d eh: %lld ]\n", LIMITE, soma);
}
void contarNumerosPrimos() {
    int inicio, fim, soma = 0;

    printf("\n-> Digite um intervalo para saber quantos primos existem"
           "\nEX: (inicio fim)\n-> ");
    scanf("%d %d", &inicio, &fim);

    if (inicio >= fim) {
        printf("Erro: O inicio deve ser menor que o fim.\n");
        return;
    }

    for (int num = inicio; num <= fim; num++) {
        int ehPrimo = 1;

        if (num < 2) {
            ehPrimo = 0;
        } else {
            for (int cont = 2; cont < num; cont++) {
                if (num % cont == 0) {
                    ehPrimo = 0;
                    break;
                }
            }
        }

        if (ehPrimo)
            soma++;
    }
    printf("\n[ A quantidade de numeros primos entre %d e %d eh: %d ]\n", inicio, fim, soma);
}
void trianguloFloyd() {
    int linhas, cont, vx;
    int numero = 1;

    printf("Digite a quantidade de linhas desejada: ");
    linhas = lerInt();

    for (vx = 1; vx <= linhas; vx++) {
        for (cont = 1; cont <= vx; cont++) {
            printf("%d ", numero);
            numero++; // Incrementa o número a cada impressão
        }
        printf("\n");
    }
}
