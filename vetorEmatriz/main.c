#include <stdio.h>
#include "funcoes.h"

int main() {
    int opcao;

    do {
        printf("\n =============== Menu de Exercicios ===============\n");
        printf("1 - Ler vetor e exibir ordem inversa\n");
        printf("2 - Encontrar numeros primos no vetor\n");
        printf("3 - Analisar pares e impares no vetor\n");
        printf("4 - Armazenar numeros diferentes no vetor\n");
        printf("5 - Preencher matriz com diagonal principal 1\n");
        printf("6 - Encontrar maior valor da matriz\n");
        printf("7 - Buscar valor na matriz\n");
        printf("0 - Sair\n");
        printf("\n-> Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: lerVetorOrdemInversa(); break;
            case 2: encontrarNumerosPrimos(); break;
            case 3: analisarParesImpares(); break;
            case 4: armazenarNumerosDiferentes(); break;
            case 5: preencherMatrizDiagonal(); break;
            case 6: encontrarMaiorValorMatriz(); break;
            case 7: buscarValorNaMatriz(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
