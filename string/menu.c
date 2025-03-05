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
        int opcao = atoi(escolha);

        if (opcao >= 1 && opcao <= 10) {
            printf("\n-> Voce escolheu a opcao %d.\n", opcao);

            switch (opcao) {
                case 1: inverterString();break;
                case 2: contarESubstituirVogais();break;
                case 3: converterMaiusculasMinusculas();break;
                case 4: removerEspacos();break;
                case 5: substituirCaracteres();break;
                case 6: calcularDesconto();break;
                case 7: criptografarCesar();break;
                case 8: verificarPalindromo();break;
                case 9: concatenarStrings();break;
                case 10: encontrarMaiorProduto();break;
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
            case 1: printf("0%d. Inverter String\n", i); break;
            case 2: printf("0%d. Contar e Substituir Vogais\n", i); break;
            case 3: printf("0%d. Converter Maiusculas <-> Minusculas\n", i); break;
            case 4: printf("0%d. Remover Espacos\n", i); break;
            case 5: printf("0%d. Substituir Caracteres\n", i); break;
            case 6: printf("0%d. Calcular Desconto a Vista\n", i); break;
            case 7: printf("0%d. Criptografar com Código de César\n", i); break;
            case 8: printf("0%d. Verificar Palindromo\n", i); break;
            case 9: printf("0%d. Concatenar Strings\n", i); break;
            case 10: printf("%d. Encontrar Maior Produto de 5 Dígitos Consecutivos\n", i); break;
            default: break;
        }
    }
    printf("\n0. Sair\n");
    printf("P. Proxima pagina\n");
    printf("A. Pagina anterior\n");
}


