#include <stdio.h>
#include "funcoes.h"

int main() {
    int opcao;

    do {
        printf("\n =============== Menu de Exercicios ===============\n");
        printf("1. Ler e imprimir vetor\n");
        printf("2. Remover vogais de uma string\n");
        printf("3. Simular memoria\n");
        printf("4. Inicializar e exibir vetor com 1500 elementos\n");
        printf("5. Preencher vetor com N valores aleatorios\n");
        printf("0. Sair\n");
        printf("\nEscolha um exercicio: ");
        opcao = lerInt();

        switch (opcao) {
            case 1: lerEImprimirVetor(); break;
            case 2: removerVogaisDaString(); break;
            case 3: simularMemoria(); break;
            case 4: inicializarEVetor(); break;
            case 5: preencherVetorComAleatorios(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
