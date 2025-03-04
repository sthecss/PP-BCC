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
 * usando estudo básico para resolver problemas do dia a dia.
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
    int escolha;

    do {
        exibirTextos();
        printf("Escolha o exercicio (1-16) ou 0 para sair: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: somaSucessorAntecessor();       break;
            case 2: calculaHipotenusa();            break;
            case 3: calculaVolumeCilindro();        break;
            case 4: aumentoSalario();               break;
            case 5: divisaoPremio();                break;
            case 6: calculaSalario();               break;
            case 7: ajudaVendedor();                break;
            case 8: calculaDegraus();               break;
            case 9: converteLetra();                break;
            case 10: inverteNumero();               break;
            case 11: imprimeDigitos();              break;
            case 12: converteTempo();               break;
            case 13: calculaTerminoExperimento();   break;
            case 14: calculaAnoNascimento();        break;
            case 15: calculaDistanciaOrigem();      break;
            case 16: divisaoPremioAmigos();         break;
            case 0: printf("Saindo...\n");    break;
            default: printf("Escolha invalida! Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
