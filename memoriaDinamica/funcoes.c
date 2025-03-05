#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
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

void lerEImprimirVetor() {
    int *vet, tamanho;

    printf("\n- Qual o tamanho do vetor?: ");
    tamanho = lerInt();

    vet = (int*)malloc(tamanho * sizeof(int));
    if (vet == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("\n- Digite um valor para a posicao [%d]: ", i);
        vet[i] = lerInt();
    }

    printf("\n> > Dado os valores para cada posicao, o vetor ficou da seguinte forma: ");
    for (int i = 0; i < tamanho; i++) {
        printf("\n- O valor da [%d] posicao eh [%d]", i, vet[i]);
    }
    printf("\n");

    free(vet);
}

void removerVogaisDaString() {
    int tamanho;
    char *str, *novaStr;

    printf("\n- Digite o [tamanho] da frase: ");
    tamanho = lerInt();

    str = (char *)malloc((tamanho + 1) * sizeof(char));
    if (str == NULL) {
        printf("Erro na alocação de memória!\n");
        return;
    }

    printf("\n- Digite a sua [frase]: ");
    fgets(str, tamanho + 1, stdin);

    novaStr = (char *)malloc((tamanho + 1) * sizeof(char));
    if (novaStr == NULL) {
        printf("Erro na alocação de memória!\n");
        free(str);
        return;
    }

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!strchr("aeiouAEIOU", str[i])) {
            novaStr[j++] = str[i];
        }
    }
    novaStr[j] = '\0';

    printf("\n- A frase sem vogais ficou: %s", novaStr);

    free(str);
    free(novaStr);
}

void simularMemoria() {
    int *ponteiro, memoria, opcao, valor, posicao;

    do {
        printf("\n- Quantos bytes quer alocados do tipo inteiro (multiplo de 4): ");
        memoria = lerInt();
    } while (memoria % 4 != 0);

    ponteiro = (int *)malloc(memoria * sizeof(int));
    if (ponteiro == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return;
    }

    for (int i = 0; i < memoria; i++) {
        ponteiro[i] = 0;
    }

    do {
        printf("\n< < < < < < O QUE VOCE PODE FAZER > > > > > > \n");
        printf("1) Inserir um valor em uma posicao\n");
        printf("2) Ver qual valor esta contido em uma posicao\n");
        printf("[Para sair] digite algo que nao seja (1) ou (2).\n\n\tO que voce deseja? : ");
        opcao = lerInt();

        switch (opcao) {
            case 1:
                printf("\n- Digite a posicao que quer preencher: ");
                posicao = lerInt();

                if (posicao >= 0 && posicao < memoria) {
                    printf("\n- Digite o valor que quer guardar nessa posicao: ");
                    valor = lerFloat();
                    ponteiro[posicao] = valor;
                    printf("\nPOSICAO [%d]. . . . . VALOR GUARDADO [%d]\n", posicao, ponteiro[posicao]);
                } else {
                    printf("\n[OPS!] Posicao invalida! Tente novamente!\n");
                }
                break;

            case 2:
                printf("\n- Digite a posicao que quer saber o valor guardado: ");
                posicao = lerInt();

                if (posicao >= 0 && posicao < memoria) {
                    printf("\nVALOR CONTIDO NA POSICAO %d: %d\n", posicao, ponteiro[posicao]);
                } else {
                    printf("\n[OPS!] Posicao invalida! Tente novamente!\n");
                }
                break;

            default:
                opcao = 0;
                break;
        }
    } while (opcao == 1 || opcao == 2);
    free(ponteiro);
}

void inicializarEVetor() {
    int *ponteiro = (int *)calloc(1500, sizeof(int));
    if (ponteiro == NULL) {
        printf("\nErro na alocacao de memoria!\n");
        return;
    }

    int zeros = 0;
    for (int i = 0; i < 1500; i++)
        if (ponteiro[i] == 0) zeros++;

    printf("\n- O vetor tem %d posicoes preenchidas com 0.\n", zeros);

    for (int i = 0; i < 1500; i++)
        ponteiro[i] = 0;

    printf("\n- As 10 primeiras posicoes:");
    for (int i = 0; i < 10; i++)
        printf("\n- POSICAO [%d]: %d", i, ponteiro[i]);

    printf("\n\n- As 10 ultimas posicoes:");
    for (int i = 1490; i < 1500; i++)
        printf("\n- POSICAO [%d]: %d", i, ponteiro[i]);

    printf("\n");
    free(ponteiro);
}

void preencherVetorComAleatorios() {
    int tamanho;
    double *ponteiro;

    do {
        printf("\n- Digite quantos valores deseja guardar em um vetor (minimo 10): ");
        tamanho = lerInt();
    } while (tamanho < 10);

    ponteiro = (double *)malloc(tamanho * sizeof(double));
    if (ponteiro == NULL) {
        printf("Erro na alocação de memória!\n");
        return;
    }

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    for (int i = 0; i < tamanho; i++) {
        ponteiro[i] = rand() % 100;
        printf("\n- POSICAO [%d]: %.0f", i, ponteiro[i]);
    }

    free(ponteiro);
}