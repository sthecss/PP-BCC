#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "menu.h"

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
                case 1: dobrarNumero(); break;
                case 2: dataPorExtenso(); break;
                case 3: positivoOunegativo(); break;
                case 4: seEhQuadradoPerfeito(); break;
                case 5: conversaoSegundos(); break;
                case 6: mediaAritOuPond(); break;
                case 7: somarDigitos(); break;
                case 8: nomearTriangulo(); break;
                case 9: somarNumerosEntreXeZ(); break;
                case 10: primosAbaixoDeN(); break;
                case 11: construtorDePiramides(); break;
            }
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

void exibirMenu(int pagina) {
    int inicio = (pagina - 1) * 6 + 1;
    int fim = inicio + 5;

    printf("\n____________________ Menu de Exercicios (Pagina %d) ____________________\n", pagina);

    for (int i = inicio; i <= fim; i++) {
        switch (i) {
            case 1: printf("0%d. Dobrar um valor n\n", i); break;
            case 2: printf("0%d. Escrever por extenso uma data\n", i); break;
            case 3: printf("0%d. Descobrir se um numero eh impar, par ou zero\n", i); break;
            case 4: printf("0%d. Descobrir se um numero eh um quadrado perfeito\n", i); break;
            case 5: printf("0%d. Converter (horas, minutos e segundos) em segundos\n", i); break;
            case 6: printf("0%d. Media ponderada ou aritmetica\n", i); break;
            case 7: printf("0%d. Somar os digitos de um numero\n", i); break;
            case 8: printf("0%d. Saber o tipo de um triangulo\n", i); break;
            case 9: printf("0%d. Soma dos N numeros inteiros num intervalo (X,Z)\n", i); break;
            case 10: printf("%d. Quantidade de primos abaixo de N\n", i); break;
            case 11: printf("%d. Desenhar uma piramide/escada de altura N\n", i); break;
            default: break;
        }
    }
    printf("\n0. Sair\n");
    printf("P. Proxima pagina\n");
    printf("A. Pagina anterior\n");
}


