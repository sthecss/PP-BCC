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

        if (opcao >= 1 && opcao <= 18) {
            printf("\n-> Voce escolheu a opcao %d.\n", opcao);

            switch (opcao) {
                case 1: maiorNumero(); break;
                case 2: raizQuadrada(); break;
                case 3: parOuImpar(); break;
                case 4: menorMaiorSubtracao(); break;
                case 5: emprestimoConcedido(); break;
                case 6: mediaNotas(); break;
                case 7: diaDaSemana(); break;
                case 8: tipoTriangulo(); break;
                case 9: aposentadoria(); break;
                case 10: precoComImposto(); break;
                case 11: consumoCarro(); break;
                case 12: calcularMedia(); break;
                case 13: provaMatematica(); break;
                case 14: cardapioLanchonete(); break;
                case 15: aumentoPreco(); break;
                case 16: tarifaEstacionamento(); break;
                case 17: reajusteSalarial(); break;
                case 18: custoConsumidor(); break;
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
            case 1: printf("0%d. Maior numero\n", i); break;
            case 2: printf("0%d. Raiz quadrada\n", i); break;
            case 3: printf("0%d. Par ou impar\n", i); break;
            case 4: printf("0%d. Menor, maior e subtracao\n", i); break;
            case 5: printf("0%d. Emprestimo concedido\n", i); break;
            case 6: printf("0%d. Media das notas\n", i); break;
            case 7: printf("0%d. Dia da semana\n", i); break;
            case 8: printf("0%d. Tipo de triangulo\n", i); break;
            case 9: printf("0%d. Aposentadoria\n", i); break;
            case 10: printf("0%d. Preco com imposto\n", i); break;
            case 11: printf("0%d. Consumo do carro\n", i); break;
            case 12: printf("0%d. Calcular media\n", i); break;
            case 13: printf("0%d. Prova de matematica\n", i); break;
            case 14: printf("0%d. Cardapio da lanchonete\n", i); break;
            case 15: printf("0%d. Aumento de preco\n", i); break;
            case 16: printf("0%d. Tarifa de estacionamento\n", i); break;
            case 17: printf("0%d. Reajuste salarial\n", i); break;
            case 18: printf("0%d. Custo ao consumidor\n", i); break;
            default: break;
        }
    }
    printf("\n0. Sair\n");
    printf("P. Proxima pagina\n");
    printf("A. Pagina anterior\n");
}


