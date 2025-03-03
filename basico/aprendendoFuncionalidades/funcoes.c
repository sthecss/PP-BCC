#include <stdio.h>
#include <math.h>
#include "funcoes.h"

// ========================================================

void lerEimprimirNumeros() {
    int opcao;
    do {
        printf("\n1 - Ler e imprimir numero inteiro\n");
        printf("2 - Ler e imprimir numero real\n");
        printf("0 - Voltar\n");
        opcao = lerInt();

        switch(opcao) {
            case 1: printf("Numero digitado: %d\n", lerInt()); break;
            case 2: printf("Numero digitado: %.2f\n", lerFloat()); break;
        }
    } while(opcao != 0);
}

int lerInt() {
    int valor;
    printf("->");
    scanf("%d", &valor);
    return valor;
}

float lerFloat() {
    float valor;
    printf("->");
    scanf("%f", &valor);
    return valor;
}

// ========================================================

void nInputs() {
    int opcao;
    do {
        printf("\n1 - Um input por vez\n");
        printf("2 - Todos de uma vez\n");
        printf("0 - Voltar\n");
        opcao = lerInt();

        switch(opcao) {
            case 1: lerUmPorVez(); break;
            case 2: lerVariosDeUmaVez(); break;
        }
    } while(opcao != 0);
}

void lerVariosDeUmaVez() {
    int num1, num2, num3;
    printf("Digite tres numeros inteiros separados por espaco : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("Numeros digitados: %d, %d, %d\n", num1, num2, num3);
}

void lerUmPorVez() {
    printf("Insira um valor por vez :\n");
    int num1 = lerInt();
    int num2 = lerInt();
    int num3 = lerInt();
    printf("Numeros digitados: %d, %d, %d\n", num1, num2, num3);
}

// ========================================================

void contasAlgebricas() {
    int opcao;
    do {
        printf("\n1 - Soma de tres numeros\n");
        printf("2 - O quadrado de um numero\n");
        printf("3 - Quinta parte de um numero\n");
        printf("4 - Media Aritimetica\n");
        printf("0 - Voltar\n");
        opcao = lerInt();

        switch(opcao) {
            case 1: somaTresNumeros();            break;
            case 2: calcularQuadrado();           break;
            case 3: calcularQuintaParte();        break;
            case 4: calcularMediaAritmetica();    break;
            case 0: printf("Saindo...\n");  break;
        }
    } while(opcao != 0);
}

void somaTresNumeros() {
    printf("Digite tres numeros inteiros: ");
    int num1 = lerInt(), num2 = lerInt(), num3 = lerInt();
    printf("A soma dos tres valores eh: %d\n", num1 + num2 + num3);
}

void calcularQuadrado() {
    printf("Digite um numero: ");
    float num = lerFloat();
    printf("Quadrado do numero (multiplicacao): %.2f\n", num * num);
    printf("Quadrado do numero (pow): %.2f\n", pow(num, 2));
}

void calcularQuintaParte() {
    printf("Digite um numero: ");
    float num = lerFloat();
    printf("A quinta parte eh: %.2f\n", num / 5);
}

void calcularMediaAritmetica() {
    float notaUm,notaDois,notaTres,notaQuatro, mediaArit;

    printf ("-\n-> Iremos calcular a média de 4 notas. Insira um por vez\n");

    // Leituras:
    notaUm = lerFloat();   notaDois = lerFloat();   notaTres = lerFloat();   notaQuatro = lerFloat();

    mediaArit= (notaUm + notaDois + notaTres+ notaQuatro)/4;
    printf ("A media desses quatro valores eh: [ %.2f ]\n", mediaArit);
}

// ========================================================

void conversaoTemperatura() {
    int opcao;
    do {
        printf("\n1 - Celsius para Fahrenheit\n");
        printf("2 - Fahrenheit para Celsius\n");
        printf("3 - Kelvin para Celsius\n");
        printf("4 - Celsius para Kelvin\n");
        printf("0 - Voltar\n");
        opcao = lerInt();

        switch(opcao) {
            case 1: celsiusParaFahrenheit(); break;
            case 2: fahrenheitParaCelsius(); break;
            case 3: kelvinParaCelsius(); break;
            case 4: celsiusParaKelvin(); break;
        }
    } while(opcao != 0);
}

void celsiusParaFahrenheit() {
    printf("Digite a temperatura em Celsius: ");
    float c = lerFloat();
    printf("Temperatura em Fahrenheit: %.2f\n", c * 9.0 / 5.0 + 32);
}

void fahrenheitParaCelsius() {
    printf("Digite a temperatura em Fahrenheit: ");
    float f = lerFloat();
    printf("Temperatura em Celsius: %.2f\n", (f - 32) * 5.0 / 9.0);
}

void kelvinParaCelsius() {
    printf("Digite a temperatura em Kelvin: ");
    float k = lerFloat();
    printf("Temperatura em Celsius: %.2f\n", k - 273.15);
}

void celsiusParaKelvin() {
    printf("Digite a temperatura em Celsius: ");
    float c = lerFloat();
    printf("Temperatura em Kelvin: %.2f\n", c + 273.15);
}

// ========================================================

void converterAreas() {
    int opcao;
    do {
        printf("\n1 - Metros quadrados para Acres\n");
        printf("2 - Acres para Metros quadrados\n");
        printf("3 - Metros quadrados para Hectares\n");
        printf("4 - Hectares para Metros quadrados\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: metrosParaAcres(); break;
            case 2: acresParaMetros(); break;
            case 3: metrosParaHectares(); break;
            case 4: hectaresParaMetros(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}

void metrosParaAcres() {
    printf("Digite a area em metros quadrados: ");
    float metros = lerFloat();
    printf("Area em acres: %.6f\n", metros * 0.000247);
}

void acresParaMetros() {
    printf("Digite a area em acres: ");
    float acres = lerFloat();
    printf("Area em metros quadrados: %.2f\n", acres * 4048.58);
}

void metrosParaHectares() {
    printf("Digite a area em metros quadrados: ");
    float metros = lerFloat();
    printf("Area em hectares: %.4f\n", metros * 0.0001);
}

void hectaresParaMetros() {
    printf("Digite a area em hectares: ");
    float hectares = lerFloat();
    printf("Area em metros quadrados: %.2f\n", hectares * 10000);
}

// ========================================================