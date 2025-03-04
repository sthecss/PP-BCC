#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "funcoes.h"

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
char lerChar() {
    char valor;
    printf("->");
    scanf(" %c", &valor);
    return toupper(valor);
}

int dobro(int numQlq)
{
    return numQlq * 2;
}
void dobrarNumero() {
    printf ("\n- Digite um numero inteiro qualquer: ");
    int num = lerInt();
    printf ("- O dobro desse numero eh: [ %d ]\n", dobro(num));
}

void dataPorExtenso() {
    int dia, mes, ano;
    printf ("\n- Digite a data, separada por / (Ex 14/03/2024)\n");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    data(dia,mes,ano);
    printf("\n");
}
void data(int dia, int mes, int ano) {
    printf("%d de", dia);
    switch ( mes )
    {
        case 1:
            printf(" Janeiro ");                break;
        case 2:
            printf (" Fevereiro ");             break;
        case 3:
            printf(" Março" );                  break;
        case 4:
            printf (" Abril ");                 break;
        case 5:
            printf(" Maio ");                   break;
        case 6:
            printf(" Junho ");                  break;
        case 7:
            printf(" Julho" );                  break;
        case 8:
            printf(" Agosto ");                 break;
        case 9:
            printf (" Setembro ");              break;
        case 10:
            printf(" Outubro ");                break;
        case 11:
            printf (" Novembro ");              break;
        case 12:
            printf (" Dezembro ");              break;
        default:
            printf("[ Invalido. ]");            break;
    }
    printf("de %d", ano);
}

void positivoOunegativo() {
    printf("\n- Digite um numero: ");
    int num = lerInt();

    printf("\n[ Retornara ( 1 ) se for positivo ] \n[ Retornara ( -1 ) se for negativo ] \n[ E retornara ( 0 ) se for 0 ]");

    printf("\n-> E o retorno foi [ %d ]\n", verificarPosOuNeg (num));
}
int verificarPosOuNeg(int num) {
    return (num > 0) ? 1 : ( (num < 0) ? -1 : 0 );
}

void seEhQuadradoPerfeito() {
    int num;
    printf("- Digite um numero para verificar se e quadrado perfeito: ");
    scanf("%d", &num);

    int resultado = verificaQuadradoPerfeito(num);

    if (resultado == 1)
        printf("\n[ O numero E um quadrado perfeito! ]\n");
    else
        printf("\n[ O numero NAO E um quadrado perfeito! ]\n");
}
int verificaQuadradoPerfeito(int num) {
    if (num < 0) return -1;
    int raiz = (int) round(sqrt(num));
    return (raiz * raiz == num) ? 1 : -1;
}

void conversaoSegundos() {
    printf("\n- Digite as horas: ");
    int hora = lerInt();
    printf("\n- Digite os minutos: ");
    int minuto = lerInt();
    printf("\n- Digite os segundos: ");
    int segundo = lerInt();

    printf("\n- A conversao para segundos ficou em [ %d ]\n", conversaoHMS(hora, minuto, segundo));
}
int conversaoHMS(int hora, int minuto, int segundo) {
    return (hora * 3600) + (minuto * 60) + segundo;
}

void mediaAritOuPond() {
    printf("- Digite a primeira nota: ");
    int notaUm = lerInt();
    printf("\n- Digite a segunda nota: ");
    int notaDois = lerInt();
    printf("\n- Digite a terceira nota: ");
    int notaTres = lerInt();

    printf("\n- Digite (A) para média aritmética ou (P) para média ponderada: ");
    char tipo = lerChar();

    if (tipo != 'A' && tipo != 'P') {
        printf("\nOpção inválida! Digite A ou P.\n");
        return;
    }

    float resultado = calcularMedia(notaUm, notaDois, notaTres, tipo);
    printf("\nA média %s das três notas é: [ %.2f ]\n", (tipo == 'A') ? "aritmética" : "ponderada", resultado);
}
float calcularMedia(int notaUm, int notaDois, int notaTres, char tipo) {
    return (tipo == 'A') ?
        (notaUm + notaDois + notaTres) / 3.0 :
        ((notaUm * 5) + (notaDois * 3) + (notaTres * 2)) / 10.0;
}

void somarDigitos() {
    printf("\n- Digite um numero: ");
    int num = lerInt();

    if (num <= 0)
        printf("\n [ INVALIDO ]\n");
    else
        printf("\n- A soma dos digitos do numero %d eh: [ %d ]\n", num, somaDosDigitos (num));
}
int somaDosDigitos(int num) {
    if (num == 0) return 0; // Caso base
    return (num % 10) + somaDosDigitos(num / 10); // Passo recursivo
}

void nomearTriangulo() {
    printf("\n- Digite primeiro lado do triangulo ");
    int ladoA = lerInt();
    printf("\n- Digite segundo lado do triangulo ");
    int ladoB = lerInt();
    printf("\n- Digite terceiro lado do triangulo ");
    int ladoC = lerInt();

    if (verificaExistenciaTriangulo(ladoA, ladoB, ladoC)) {
        printf("\n- O triângulo existe!\n");
        determinaTipoTriangulo(ladoA, ladoB, ladoC);
    } else {
        printf("\n=== Triângulo INVÁLIDO, tente de novo :) ===\n");
    }
}
int verificaExistenciaTriangulo(int ladoA, int ladoB, int ladoC) {
    return (ladoA > 0 && ladoB > 0 && ladoC > 0 &&
            ladoA < ladoB + ladoC &&
            ladoB < ladoA + ladoC &&
            ladoC < ladoA + ladoB);
}
void determinaTipoTriangulo(int ladoA, int ladoB, int ladoC) {
    printf("\n- Com isso, podemos determinar que esse triângulo é ");

    if (ladoA == ladoB && ladoB == ladoC) {
        printf("[ Equilátero! ]\n");
    } else if (ladoA != ladoB && ladoA != ladoC && ladoB != ladoC) {
        printf("[ Escaleno! ]\n");
    } else {
        printf("[ Isósceles! ]\n");
    }
}

void somarNumerosEntreXeZ() {
    printf("\n- Digite o primeiro número inteiro positivo, X: ");
    int numUm = lerInt();
    printf("\n- Digite o segundo número inteiro positivo, Z: ");
    int numDois = lerInt();

    if (numUm <= 0 || numDois <= 0) {
        printf("\nOs números devem ser inteiros positivos!\n");
        return;
    }

    int resultado = somaEntreNumeros(numUm, numDois);

    printf("\n- A soma dos números entre ambos é: [ %d ].\n", resultado);
}
int somaEntreNumeros(int numUm, int numDois) {
    if (numUm > numDois) {
        int temp = numUm;
        numUm = numDois;
        numDois = temp;
    }
    int soma = 0;
    for (int i = numUm + 1; i < numDois; i++) {
        soma += i;
    }
    return soma;
}

int contarPrimosAbaixoDeN(int n);
int ehPrimo(int num);

void primosAbaixoDeN(){
    printf("\n- Digite um número inteiro positivo (> 1) para contar os primos abaixo dele: ");
    int numero = lerInt();

    if (numero <= 1) {
        printf("\n[ INVÁLIDO ] O número deve ser maior que 1.\n");
        return;
    }

    printf("\n- A quantidade de números primos abaixo de %d é: %d\n", numero, contarPrimosAbaixoDeN(numero));
}
int contarPrimosAbaixoDeN(int n) {
    int contador = 0;

    for (int i = 2; i < n; i++) {
        if (ehPrimo(i)) {
            contador++;
        }
    }
    return contador;
}
int ehPrimo(int num) {
    if (num < 2) return 0; // 0 e 1 não são primos
    if (num == 2) return 1; // 2 é primo

    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return 0; // Não é primo

    return 1; // É primo
}

void construtorDePiramides() {
    printf("\nEscolha o tipo de pirâmide:\n");
    printf("1 - Piramide simples\n");
    printf("2 - Triangulo lateral\n");
    printf("3 - Triangulo centralizado\n");
    printf("\n- Digite sua escolha: ");
    int tipo = lerInt();

    printf("\n- Digite o tamanho desejado: ");
    int tamanho = lerInt();

    printf("\n- Digite o simbolo que deseja usar: ");
    char simbolo = lerChar();

    switch (tipo) {
        case 1:
            piramideSimples(tamanho, simbolo);          break;
        case 2:
            trianguloLateral(tamanho, simbolo);         break;
        case 3:
            trianguloCentralizado(tamanho, simbolo);    break;
        default:
            printf("\nTipo inválido!\n");
    }
}
void piramideSimples(int tamanho, char simbolo) {
    for (int linha = 1; linha <= tamanho; linha++) {
        for (int coluna = 1; coluna <= linha; coluna++) {
            printf("%c", simbolo);
        }
        printf("\n");
    }
}
void trianguloLateral(int tamanho, char simbolo) {
    for (int i = 1; i <= tamanho; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", simbolo);
        }
        printf("\n");
    }
    for (int i = tamanho - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            printf("%c", simbolo);
        }
        printf("\n");
    }
}
void trianguloCentralizado(int tamanho, char simbolo) {
    for (int linha = 1; linha <= tamanho; linha++) {
        for (int espacos = 0; espacos < tamanho - linha; espacos++) {
            printf(" ");
        }
        for (int estrelas = 0; estrelas < (2 * linha - 1); estrelas++) {
            printf("%c", simbolo);
        }
        printf("\n");
    }
}