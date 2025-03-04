/**
* @file main.c
 * @author Sthe CSS
 * @version 1.0
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
 * tendo como foco a manipulacao lógica condicional. O usuário pode escolher
 * uma opção do menu para executar a funcionalidade desejada.
 *
 * @section DEPENDENCIAS
 * NÃO rode a main.c sem os arquivos funcoes.c e funcoes.h baixados.
 * Para compilar, rode no terminal:
 * gcc main.c funcoes.c menu.c -o programa
 * ./programa
 *
 */

#include <stdio.h>
#include <string.h>
#include "menu.h"

int main() {
    int paginaAtual = 1;
    int totalPaginas = 2;
    char escolha[10];

    do {
        exibirMenu(paginaAtual);

        printf("\nEscolha uma opcao (ou P para proxima pagina, A para pagina anterior): ");
        scanf("%s", escolha);
        getchar();

        paginacao(&paginaAtual, totalPaginas, escolha);

    } while (strcmp(escolha, "0") != 0);

    return 0;
}

