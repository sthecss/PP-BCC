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

        if (opcao >= 1 && opcao <= 10) {
            printf("\n-> Voce escolheu a opcao %d.\n", opcao);

            switch (opcao) {
                case 1: dobrarValores(); break;
                case 2: encontrarSubstring(); break;
                case 3: imprimirArray(); break;
                case 4: separarPartesFloat(); break;
                case 5: encontrarMaiorElemento(); break;
                case 6: contarNegativos(); break;
                case 7: somarArrays(); break;
                case 8: imprimirMaiorElemento(); break;
                case 9: calcularMedias(); break;
                case 10: calcularRaizes(); break;
            }
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

void exibirMenu(int pagina) {
    int inicio = (pagina - 1) * 5 + 1;
    int fim = inicio + 4;

    printf("\n____________________ Menu de Exercicios (Pagina %d) ____________________\n", pagina);

    for (int i = inicio; i <= fim; i++) {
        switch (i) {
            case 1: printf("0%d. Dobrar valores de um array\n", i); break;
            case 2: printf("0%d. Encontrar substring em uma string\n", i); break;
            case 3: printf("0%d. Imprimir array\n", i); break;
            case 4: printf("0%d. Separar parte inteira e fracionaria de um float\n", i); break;
            case 5: printf("0%d. Encontrar maior elemento e sua ocorrencia\n", i); break;
            case 6: printf("0%d. Contar numeros negativos em um array\n", i); break;
            case 7: printf("0%d. Somar posicoes de dois arrays\n", i); break;
            case 8: printf("0%d. Ler um vetor, e imprimir N elementos por linha\n", i); break;
            case 9: printf("0%d. Calcular medias simples e ponderada\n", i); break;
            case 10: printf("0%d. Calcular raizes de uma equacao do segundo grau\n", i); break;
            default: break;
        }
    }
    printf("\n0. Sair\n");
    printf("P. Proxima pagina\n");
    printf("A. Pagina anterior\n");
}


