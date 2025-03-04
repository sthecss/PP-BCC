//
// Created by sthecss on 03/03/2025.
//

#ifndef FUNCOES_H
#define FUNCOES_H

int lerInt();
float lerFloat();
char lerChar();

void dobrarNumero();

void dataPorExtenso();
void data(int dia, int mes, int ano);

void positivoOunegativo();
int verificarPosOuNeg(int num);

void seEhQuadradoPerfeito();
int verificaQuadradoPerfeito(int num);

void conversaoSegundos();
int conversaoHMS(int hora, int minuto, int segundo);

void mediaAritOuPond();
float calcularMedia(int notaUm, int notaDois, int notaTres, char tipo);

void somarDigitos();
int somaDosDigitos(int num);

void nomearTriangulo();
int verificaExistenciaTriangulo(int ladoA, int ladoB, int ladoC);
void determinaTipoTriangulo(int ladoA, int ladoB, int ladoC);

void somarNumerosEntreXeZ();
int somaEntreNumeros(int numUm, int numDois);

void primosAbaixoDeN();
int contarPrimosAbaixoDeN(int n);
int ehPrimo(int num);

void piramideSimples(int tamanho, char simbolo);
void trianguloLateral(int tamanho, char simbolo);
void trianguloCentralizado(int tamanho, char simbolo);
void construtorDePiramides();

#endif //FUNCOES_H
