//
// Created by sthecss on 03/03/2025.
//

#ifndef FUNCOES_H
#define FUNCOES_H

int lerInt();
float lerFloat();
char lerChar();

void dobrarValores();
void encontrarSubstring();
void acharPalavra(char *strUm, char *strDois, int tamanhoUm, int tamanhoDois, int *verificacao);
void imprimirArray();
void separarPartesFloat();
void frac(float num, int *inteiro, float *fracionado) ;
void encontrarMaiorElemento();
void funcaoDeOcorrencia(int N, int *ponteiro);
void contarNegativos();
int  negativos(float *vet, int N) ;
void somarArrays();
int  somaDosDoisArray(int numUm, int numDois, int *ponteiroUm, int *ponteiroDois, int *ponteiroTresComSoma, int *tamanhoResultado);
void imprimirMaiorElemento();
void printandoArray(int N, int *ponteiro) ;
void calcularMedias();
void calculoDasMedias(int *notaUm, int *notaDois, float *mediaSimples, float *mediaPondera);
void leituraDasNotas(int *notaUm, int *notaDois);
void calcularRaizes();
int  raiz(float a, float b, float c, float *xUm, float *xDois);

#endif //FUNCOES_H
