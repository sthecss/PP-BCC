#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "funcoes.h"

#define LIMITE 2000000

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

void dobrarValores() {
    int vet[5];
    int *pont = vet;

    for (int i = 0; i < 5; i++) {
        printf("\n- Armazene o [%d] numero: ", i + 1);
        pont[i] = lerInt();
    }

    for (int i = 0; i < 5; i++) {
        printf("\n- O dobro do numero armazenado na posicao %d eh [%d] ", i, *(pont + i) * 2);
    }
    printf("\n");
}

void encontrarSubstring() {
    char strUm[100], strDois[100];
    int tamanhoUm, tamanhoDois, verificacao;

    printf("\n- Digite a frase [fonte]: ");
    fflush(stdin);
    scanf("%100[^\n]", strUm);

    printf("\n- Digite a frase de [busca]: ");
    fflush(stdin);
    scanf("%100[^\n]", strDois);

    tamanhoUm = strlen(strUm);
    tamanhoDois = strlen(strDois);

    acharPalavra(strUm, strDois, tamanhoUm, tamanhoDois, &verificacao);

    if (verificacao == 0)
        printf("\n- Foi achado!\n");
    else
        printf("\n- Nao foi achado!\n");
}

void acharPalavra(char *strUm, char *strDois, int tamanhoUm, int tamanhoDois, int *verificacao) {
    int achado = 0;

    for (int i = 0; i <= tamanhoUm - tamanhoDois; i++) {
        achado = 1;

        for (int j = 0; j < tamanhoDois; j++) {
            if (*(strUm + i + j) != *(strDois + j)) {
                achado = 0;
                break;
            }
        }

        if (achado == 1) {
            *verificacao = 0;
            return;
        }
    }

    *verificacao = 1;
}

void imprimirArray() {
    char vet[100] ={"Essa frase foi salva no codigo fonte! Brigada por ter selecionado :)"};
    for (int i = 0; i < 100; i++) {
        printf("%c", *(vet + i));
    }
    printf("\n");
}

void separarPartesFloat() {
    float num, fracionado;
    int inteiro;

    printf("\n- Digite um valor real qualquer: ");
    num = lerFloat();

    frac(num, &inteiro, &fracionado);

    printf("\n- Com isso temos que a parte inteira eh de: %d", inteiro);
    printf("\n... Com precisao de 4 casas...\n"
           " Temos como parte fracionada [ %.4f ] \n", fracionado);
}

void frac(float num, int *inteiro, float *fracionado) {
    *inteiro = floor(num);
    *fracionado = num - floor(num);
}

void encontrarMaiorElemento() {
    int N, *ponteiro;

    printf("\n- Digite o tamanho do seu vetor: ");
    N = lerInt();

    ponteiro = (int*) malloc(sizeof(int) * N);

    funcaoDeOcorrencia(N, ponteiro);
}

void funcaoDeOcorrencia(int N, int *ponteiro) {
    int maiorNumero = ponteiro[0], contador = 0;

    for (int i = 0; i < N; i++) {
        printf("\n- Digite um termo para guardar em [%d]: ", i);
        ponteiro[i] = lerInt();
    }

    for (int i = 1; i < N; i++) {
        if (maiorNumero < ponteiro[i])
            maiorNumero = ponteiro[i];
    }

    printf("\n> > O maior elemento eh: [ %d ]\n", maiorNumero);

    for (int i = 0; i < N; i++) {
        if (maiorNumero == ponteiro[i])
            contador++;
    }

    printf("... E ele aparece [ %d ] vez(es) no vetor\n\n", contador);
}

void contarNegativos() {
    int N, ocorrencia;
    float *vet;

    printf("\n- Digite o tamanho do seu vetor: ");
    N = lerFloat();

    vet = (float*) malloc(sizeof(float) * N);

    ocorrencia = negativos(vet, N);

    printf("\n> > Esse vetor tem [ %d ] numero(s) negativo(s)\n", ocorrencia);
}

int negativos(float *vet, int N) {
    int contador = 0;

    for (int i = 0; i < N; i++) {
        printf("\n- Armazene um valor em [%d]: ", i);
        vet[i] = lerFloat();
    }

    for (int i = 0; i < N; i++) {
        if (*(vet + i) < 0)
            contador++;
    }
    return contador;
}

void somarArrays() {
    int numUm, numDois, *ponteiroUm, *ponteiroDois, *ponteiroTresComSoma, retorno, tamanhoResultado;

    printf("\n-> Caso os vetores tenham tamanhos diferentes, o resultado da soma"
           "\n   nas posições excedentes será o valor do vetor maior.\n");

    printf("\n- Qual o tamanho que quer o [ PRIMEIRO VETOR ]?: ");
    numUm = lerInt();

    printf("\n- Qual o tamanho que quer o [ SEGUNDO VETOR ]?: ");
    numDois = lerInt();

    ponteiroUm = (int*) malloc(sizeof(int) * numUm);
    ponteiroDois = (int*) malloc(sizeof(int) * numDois);
    ponteiroTresComSoma = (int*) malloc(sizeof(int) * ((numUm > numDois) ? numUm : numDois));

    retorno = somaDosDoisArray(numUm, numDois, ponteiroUm, ponteiroDois, ponteiroTresComSoma, &tamanhoResultado);

    if (retorno == 1) {
        printf("\n < < Concluido! > >");
        for (int i = 0; i < tamanhoResultado; i++) {
            printf("\n- Na posicao [%d] VetUm + VetDois = %d", i, ponteiroTresComSoma[i]);
        }
    }

    free(ponteiroUm);
    free(ponteiroDois);
    free(ponteiroTresComSoma);
}

int somaDosDoisArray(int numUm, int numDois, int *ponteiroUm, int *ponteiroDois, int *ponteiroTresComSoma, int *tamanhoResultado) {
    *tamanhoResultado = (numUm > numDois) ? numUm : numDois;

    for (int i = 0; i < numUm; i++) {
        printf("\n- [PRIMEIRO VETOR] Preencha a posicao [%d]: ", i);
        ponteiroUm[i] = lerInt();
    }

    for (int i = 0; i < numDois; i++) {
        printf("\n- [SEGUNDO VETOR] Preencha a posicao [%d]: ", i);
        ponteiroDois[i] = lerInt();
    }

    int menorTamanho = (numUm < numDois) ? numUm : numDois;
    for (int i = 0; i < menorTamanho; i++) {
        ponteiroTresComSoma[i] = ponteiroUm[i] + ponteiroDois[i];
    }

    if (numUm > numDois) {
        for (int i = menorTamanho; i < numUm; i++) {
            ponteiroTresComSoma[i] = ponteiroUm[i];
        }
    } else if (numDois > numUm) {
        for (int i = menorTamanho; i < numDois; i++) {
            ponteiroTresComSoma[i] = ponteiroDois[i];
        }
    }

    return 1;
}

void imprimirMaiorElemento() {
    int N, *ponteiro;

    printf("\n- Digite o [ TAMANHO ] quer alocar para seu vetor: ");
    N = lerInt();

    ponteiro = (int*) malloc(sizeof(int) * N);

    printandoArray(N, ponteiro);
}

void printandoArray(int N, int *ponteiro) {
    int valor, linha = 0, maiorElemento;

    for (int i = 0; i < N; i++) {
        printf("\n- Digite um valor para guardar em [%d]: ", i);
        ponteiro[i] = lerInt();
    }

    printf("\n- Agora digite quantos quer que apareca [POR LINHA]: ");
    valor = lerInt();

    printf("\n");
    for (int i = 0; i < N; i++, linha++) {
        if (linha < valor) {
            printf(" |%d| ", *(ponteiro + i));
        } else {
            linha = -1;
            i--;
            printf("\n");
        }
    }

    maiorElemento = ponteiro[0];

    for (int i = 1; i < N; i++) {
        if (maiorElemento < ponteiro[i])
            maiorElemento = ponteiro[i];
    }

    printf("\n> > E o maior elemento guardado foi: [ %d ] \n\n", maiorElemento);
}

void calcularMedias() {
    int notaUm, notaDois;
    float mediaSimples, mediaPonderada;

    leituraDasNotas(&notaUm, &notaDois);

    printf("\n< < A PRIMEIRA nota ficou guardada como [%d]\n"
           "      e a SEGUNDA nota ficou guardada como [%d] > >\n", notaUm, notaDois);

    calculoDasMedias(&notaUm, &notaDois, &mediaSimples, &mediaPonderada);

    printf("\nA media [aritmetica] das notas eh: %.2f\n", mediaSimples);
    printf("\nA media [ponderada] das notas eh: %.2f\n", mediaPonderada);
}

void leituraDasNotas(int *notaUm, int *notaDois) {
    printf("\n- Digite a PRIMEIRA nota (sendo de 0 a 10): ");
    *notaUm = lerInt();

    printf("\n- Digite a SEGUNDA nota (sendo de 0 a 10): ");
    *notaDois = lerInt();
}

void calculoDasMedias(int *notaUm, int *notaDois, float *mediaSimples, float *mediaPondera) {
    *mediaSimples = ((*notaUm) + (*notaDois) * 1.0) / 2;
    *mediaPondera = ((*notaUm) + ((*notaDois) * 2) * 1.0) / 3;
}

void calcularRaizes() {
    float a, b, c, x1, x2;
    int resultado;

    printf("\n- Digite os valores dos coeficientes A, B e C.\nEx: 1 2 4\n-> ");
    scanf("%f %f %f", &a, &b, &c);

    resultado = raiz(a, b, c, &x1, &x2);

    if (resultado == 0) {
        printf("\n- Nao existem raizes reais.\n");
    } else if (resultado == 1) {
        printf("\n- Existe uma raiz real: %.2f\n", x1);
    } else if (resultado == 2) {
        printf("\n- Existem duas raizes reais: %.2f e %.2f\n", x1, x2);
    }
}

int raiz(float a, float b, float c, float *xUm, float *xDois) {
    float Delta = (b * b) - 4 * a * c;

    if (Delta < 0)
        return 0;

    if (Delta == 0) {
        *xUm = ((-1) * b) / (2 * a);
        return 1;
    }

    if (Delta > 0) {
        *xUm = ((-1) * b + sqrt(Delta)) / (2 * a);
        *xDois = ((-1) * b - sqrt(Delta)) / (2 * a);
        return 2;
    }
}