/**
* @file main.c
 * @author Sthe CSS
 * @version 2.0
 *
 * @section LICENSE
 *
 * Este programa é distribuído na esperança de ser útil, mas
 * SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de
 * COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM PROPÓSITO ESPECÍFICO.
 *
 * @section DESCRIPTION
 *
 * Este programa implementa um menu interativo com diversas funcionalidades,
 * incluindo leitura e impressão de números, cálculos algébricos básicos,
 * conversões de temperatura e cálculo de áreas. O usuário pode escolher
 * uma opção do menu para executar a funcionalidade desejada.
 *
 * @section DEPENDENCIAS
 * NÃO rode a main.c sem os arquivos funcoes.c e funcoes.h baixados.
 * Para compilar, rode no terminal:
 * gcc main.c funcoes.c -o programa
 * ./programa
 *
 */

#include <stdio.h>
#include "funcoes.h"

int main() {
    int opcao;
    do {
        printf("\nMenu de opcoes:\n");
        printf("1 - Ler e imprimir numeros\n");
        printf("2 - Lendo mais de um input por vez\n");
        printf("3 - Contas algebricas basicas\n");
        printf("4 - Conversoes de temperatura\n");
        printf("5 - Calcular areas\n");

        printf("0 - Sair\n");
        printf("Escolha uma opcao : ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: lerEimprimirNumeros();  break;
            case 2: nInputs();              break;
            case 3: contasAlgebricas();     break;
            case 4: conversaoTemperatura(); break;
            case 5: converterAreas();       break;

            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
    return 0;
}
