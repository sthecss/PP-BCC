#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int lerInt() {
    int num;
    scanf("%d", &num);
    while (getchar() != '\n');
    return num;
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

// ======================== Funções para Vetores ========================

void lerVetorOrdemInversa() {
    int vet[6];

    printf("\n| Pense em 6 valores | ");

    for (int i = 0; i < 6; i++) {
        printf("\n-> Digite um valor para [%d]: ", i);
        vet[i] = lerInt();
    }
    printf("\nOrdem inversa: ");
    for (int i = 5; i >= 0; i--) {
        printf("%d |", vet[i]);
    }
    printf("\n");
}


void encontrarNumerosPrimos() {
    int vet[10];

    printf("\n| Pense em 10 valores | \n");

    for (int i = 0; i < 10; i++) {
        printf("-> Digite um numero para [%d]: ", i);
        vet[i] = lerInt();
    }
    for (int i = 0; i < 10; i++) {
        int primo = 1;
        if (vet[i] < 2) primo = 0;
        for (int j = 2; j * j <= vet[i]; j++) {
            if (vet[i] % j == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) {
            printf("\n-> Numero %d eh primo (posicao %d)", vet[i], i);
        }
    }
}

void analisarParesImpares() {
    int vet[6], somaPares = 0, qtdImpares = 0;

    printf("\n| Pense em 6 valores | \n");

    for (int i = 0; i < 6; i++) {
        printf("-> Digite um numero para [%d]: ", i);
        vet[i] = lerInt();
    }
    for (int i = 0; i < 6; i++) {
        if (vet[i] % 2 == 0) {
            printf("\n [ Numero %d eh par ]", vet[i]);
            somaPares += vet[i];
        } else {
            printf("\n [ Numero %d eh impar ]", vet[i]);
            qtdImpares++;
        }
    }
    printf("\n\n-> Soma dos pares: %d", somaPares);
    printf("\n-> Quantidade de impares: %d\n", qtdImpares);
}

void armazenarNumerosDiferentes() {
    int vet[10], num, i, repetido;

    printf("\n| Pense em 10 valores | \n");

    for (i = 0; i < 10; i++) {
        do {
            repetido = 0;
            printf("-> Digite um numero para [%d]: ", i);
            num = lerInt();
            for (int j = 0; j < i; j++) {
                if (vet[j] == num) {
                    repetido = 1;
                    printf("\n[ Numero repetido! Digite outro. ]\n");
                    break;
                }
            }
        } while (repetido);
        vet[i] = num;
    }
    printf("\n[ Numeros armazenados ]");
    for (i = 0; i < 10; i++) {
        printf("%d | ", vet[i]);
    }
    printf("\n");
}

// ======================== Funções para Matrizes ========================

void preencherMatrizDiagonal() {
    int mat[5][5] = {0};
    for (int i = 0; i < 5; i++) mat[i][i] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d | ", mat[i][j]);
        }
        printf("\n");
    }
}

void encontrarMaiorValorMatriz() {
    int mat[4][4], maior = 0, lin, col;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("-> Digite valor para [%d][%d]: ", i, j);
            mat[i][j] = lerInt();
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                lin = i;
                col = j;
            }
        }
    }
    printf("\n| Maior valor: %d na posicao [%d][%d]\n", maior, lin, col);
}

void buscarValorNaMatriz() {
    int opcao;
    printf("Escolha uma opcao:\n");
    printf("1 - Carregar matriz 3x3 com valores aleatorios\n");
    printf("2 - Preencher matriz 2x2 manualmente\n");
    printf("Opcao: ");
    opcao = lerInt();

    int mat[3][3];
    int x, encontrado = 0;

    if (opcao == 1) {
        srand(time(NULL));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = rand() % 100;
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    } else if (opcao == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("Digite valor para [%d][%d]: ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
    } else {
        printf("Opcao invalida!\n");
        return;
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &x);
    for (int i = 0; i < (opcao == 1 ? 3 : 2); i++) {
        for (int j = 0; j < (opcao == 1 ? 3 : 2); j++) {
            if (mat[i][j] == x) {
                printf("Valor encontrado em [%d][%d]\n", i, j);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) printf("Valor nao encontrado.\n");
}