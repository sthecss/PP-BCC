#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void paginacao(int *paginaAtual, int totalPaginas, char escolha[]) {
    if (strcmp(escolha, "P") == 0 || strcmp(escolha, "p") == 0) {
        if (*paginaAtual < totalPaginas) {
            (*paginaAtual)++;
        } else {
            printf("\n- Voce ja esta na ultima pagina.\n");
        }
    } else if (strcmp(escolha, "A") == 0 || strcmp(escolha, "a") == 0) {
        if (*paginaAtual > 1) {
            (*paginaAtual)--;
        } else {
            printf("\n- Voce ja esta na primeira pagina.\n");
        }
    } else if (strcmp(escolha, "0") == 0) {
        printf("Saindo...\n");
    } else {
        int opcao = atoi(escolha); // Converte a string para int

        if (opcao >= 1 && opcao <= 11) {
            printf("\n-> Voce escolheu a opcao %d.\n", opcao);

            switch (opcao) {
                case 1: somaMultiplos3e5(); break;
                case 2: distribuicaoLancamentos2d6(); break;
                case 3: calcularPotenciasRaiz(); break;
                case 4: calculadoraBasica(); break;
                case 5: saqueCaixaEletronico(); break;
                case 6: somaNumerosAbaixoDoisMilhoes(); break;
                case 7: contarNumerosPrimos(); break;
                case 8: trianguloFloyd(); break;
            }
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

void exibirMenu(int pagina) {
    int inicio = (pagina - 1) * 4 + 1;
    int fim = inicio + 3;

    printf("\n____________________ Menu de Exercicios (Pagina %d) ____________________\n", pagina);

    for (int i = inicio; i <= fim; i++) {
        switch (i) {
            case 1: printf("0%d. Soma de todos os numeros multiplos de 3 e 5, abaixo de 1000\n", i); break;
            case 2: printf("0%d. A relacao de N lancamentos entre 2d6\n", i); break;
            case 3: printf("0%d. Loop de N valores, mostrando quadrado, cubo e raiz quadrada\n", i); break;
            case 4: printf("0%d. Calculadora basica entre dois numeros\n", i); break;
            case 5: printf("0%d. Saque de um cliente num caixa eletronico\n", i); break;
            case 6: printf("0%d. Soma de todos os numeros abaixo de dois milhoes\n", i); break;
            case 7: printf("0%d. Quantidade de numeros primos existentes entre A e B\n", i); break;
            case 8: printf("0%d. Triangulo de Floyd, com quantidade de linhas N\n", i); break;
            default: break;
        }
    }
    printf("\n0. Sair\n");
    printf("P. Proxima pagina\n");
    printf("A. Pagina anterior\n");
}


