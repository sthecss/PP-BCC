#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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

void maiorNumero() {
    int x1, x2;
    printf("\n-> Digite dois numeros reais, e sera mostrado o de maior valor: ");
    scanf("%d %d", &x1, &x2);
    (x1 > x2) ? printf("O maior eh: %d.\n", x1) : printf("O maior eh: %d.\n", x2);
}

void raizQuadrada() {
    float num;
    printf("\n-> Digite um valor: ");
    scanf("%f", &num);
    (num > 0) ? printf("A raiz quadrada desse numero eh: %.2f\n", sqrt(num)) : printf("ERRO. O numero que digitou eh negativo.\n");
}

void parOuImpar() {
    printf("\nDigite um numero inteiro: ");
    int num = lerInt();
    (num % 2 == 0) ? printf("O numero digitado eh par.\n") : printf("O numero eh impar.\n");
}

void menorMaiorSubtracao() {
    printf("\n-> Digite o primeiro numero:");
    float numUm = lerFloat();
    printf("\n-> Digite o primeiro numero:");
    float numDois = lerFloat();

    if (numUm == numDois) {
        printf("- Numeros iguais.\n");
    } else {
        (numUm > numDois) ?
            printf("- %.f eh maior.\n- E a diferenca entre ambos eh: %.f\n", numUm, numUm - numDois) :
            printf("- %.f eh maior.\n- E a diferenca entre ambos eh: %.f\n", numDois, numDois - numUm);
    }
}

void emprestimoConcedido() {
    printf("\n Digite o salario, num valor inteiro: ");
    int salario = lerInt();
    printf("\n Digite o salario e o valor da prestacao do emprestimo: ");
    int emprestimo = lerInt();

    (salario / 5 > emprestimo) ?
        printf("> > > Emprestimo concedido. < < <\n") :
        printf("> > > Emprestimo nao concedido. < < <\n");
}

void mediaNotas() {
    printf("\nDigite a sua nota no Trabalho de Laboratorio: ");
    float nlab = lerFloat();
    printf("\n-> Digite a sua nota na Avaliacao Semestral: ");
    float nsem = lerFloat();
    printf("\n-> Digite a sua nota no Exame Final: ");
    float nexf = lerFloat();

    float nmed = ((nlab * 2) + (nsem * 3) + (nexf * 5)) / 10;

    if (nmed <= 2.9) {
        printf("Sua media foi: %.2f, portanto foi > > REPROVADO < <.\n", nmed);
    } else if (nmed < 5) {
        printf("Sua media foi: %.2f, portanto esta de > > RECUPERACAO < <.\n", nmed);
    } else {
        printf("Sua media foi de: %.2f, portanto foi > > APROVADO < <.\n", nmed);
    }
}

void diaDaSemana() {
    printf("\n-> Digite um numero entre 1 e 7: ");
    int num = lerInt();

    switch (num) {
        case 1: printf("O dia da semana eh: Domingo.\n"); break;
        case 2: printf("O dia da semana eh: Segunda-Feira.\n"); break;
        case 3: printf("O dia da semana eh: Terca-Feira.\n"); break;
        case 4: printf("O dia da semana eh: Quarta-Feira.\n"); break;
        case 5: printf("O dia da semana eh: Quinta-Feira.\n"); break;
        case 6: printf("O dia da semana eh: Sexta-Feira.\n"); break;
        case 7: printf("O dia da semana eh: Sabado.\n"); break;
        default: printf("Numero invalido.\n");
    }
}

void tipoTriangulo() {
    int ladoD, ladoE, ladoB;
    printf("Digite tres valores\nEX: 2 3 5\n-> ");
    scanf("%d %d %d", &ladoD, &ladoE, &ladoB);

    if (ladoD + ladoE >= ladoB && ladoD + ladoB >= ladoE && ladoE + ladoB >= ladoD) {
        if (ladoD == ladoE && ladoD == ladoB) {
            printf("\n [ Equilatero ] \n");
        } else if (ladoD == ladoE || ladoD == ladoB || ladoE == ladoB) {
            printf("\n [ Isosceles ] \n");
        } else {
            printf("\n [ Escaleno ]\n");
        }
    } else {
        printf("> > ERRO < < Numeros invalidos. Tente novamente\n");
    }
}

void aposentadoria() {
    int idade, tempo;

    printf("\n-> Digite sua idade e tempo trabalhado: ");
    scanf("%d %d", &idade, &tempo);

    ((idade >= 65) || (tempo >= 30) || (idade >= 60 && tempo >= 25)) ?
        printf("\n[ Voce PODE se aposentar! ]\n") :
        printf("\n[ Voce NAO PODE se aposentar! ]\n");
}

void precoComImposto() {
    printf("\n-> Digite o valor do produto: ");
    float valorproduto = lerFloat();
    printf("\n- Dado os seguintes estados:\n1- MG.\n2- SP.\n3- RJ.\n4- MS."
           "\n-> Digite o numero do estado que o produto se destina: ");
    char estado = lerChar();

    switch (estado) {
        case '1': printf("O preco final do produto foi de: %.2f\n", (valorproduto * 0.07) + valorproduto); break;
        case '2': printf("O preco final do produto foi de: %.2f\n", (valorproduto * 0.12) + valorproduto); break;
        case '3': printf("O preco final do produto foi de: %.2f\n", (valorproduto * 0.15) + valorproduto); break;
        case '4': printf("O preco final do produto foi de: %.2f\n", (valorproduto * 0.08) + valorproduto); break;
        default: printf("Estado invalido.\n");
    }
}

void consumoCarro() {
    printf("\n-> Digite a distancia em km percorrida: ");
    float km = lerFloat();
    printf("\n-> Digite o valor consumido de gasolina durante o trajeto: ");
    float litros = lerFloat();

    float consumo = km / litros;

    printf("\n [ O consumo foi de: %.2f\n...Portanto...\n", consumo);
    if (consumo >= 14) {
        printf("Super economico! ]\n");
    } else if (consumo >= 8) {
        printf("Economico! ]\n");
    } else {
        printf("Venda o carro! ]\n");
    }
}

void calcularMedia() {
    float numx, numy, numz;

    printf("Digite tres numeros\nEx: 5 4 6\n-> ");
    scanf("%f %f %f", &numx, &numy, &numz);

    printf("Dentre as medias:\n(a) Geometrica;\n(b) Ponderada\n(c) Harmonica\n(d) Aritmetica.\nDigite a, b, c ou d para escolher: ");
    char media = lerFloat();

    switch (media) {
        case 'a': printf("A media geometrica eh: > > %.2f < <\n", pow((numx * numy * numz), (float)1 / 3)); break;
        case 'b': printf("A media ponderada eh: > > %.2f < <\n", ((1 * numx) + (2 * numy) + (3 * numz)) / 6); break;
        case 'c': printf("A media harmonica eh: > > %.2f < <\n", 1 / ((1 / (numx + 1)) + (1 / (numy + 1)) + (1 / (numz + 1)))); break;
        case 'd': printf("A media aritmetica eh: > > %.2f < <\n", (numx + numy + numz) / 3); break;
        default: printf("ERRO.\nOpcao invalida, tente novamente digitando algum dos caracteres validos.\n");
    }
}

void provaMatematica() {
    int numa, numb, s = 0, r;

    printf("\n ============ Teste de Matematica ============\n");
    printf("\n Tudo pronto?\n");
    srand(time(NULL));

    for (int i = 1; i <= 5; i++) {
        sleep(1);
        numa = rand() % 100;
        numb = rand() % 100;
        printf("\n%d- Dada a soma: %d + %d:\n", i, numa, numb);
        printf("Digite a resposta:\n");
        scanf("%d", &r);
        if (r == (numa + numb)) {
            printf("CERTO\n");
            s++;
        } else {
            printf("ERRADO\n");
        }
    }
    printf("\nNumero de acertos: %d\n", s);
}

void cardapioLanchonete() {
    float preco;

    printf("Dada a seguinte lista:\n- Cachorro Quente: 100\n- Bauru-Simples: 101\n- Bauru com Ovo: 102\n- Hamburguer: 103\n- Chesseburguer: 104\n- Suco: 105\n- Refrigerante: 106.\n\n> Com isso digite o codigo do que deseja: ");
    int codigo = lerInt();

    printf("Especifique a quantidade pedida do produto: ");
    float qtd = lerFloat();

    switch (codigo) {
        case 100: preco = 1.20 * qtd; break;
        case 101: preco = 1.30 * qtd; break;
        case 102: preco = 1.50 * qtd; break;
        case 103: preco = 1.20 * qtd; break;
        case 104: preco = 1.70 * qtd; break;
        case 105: preco = 2.20 * qtd; break;
        case 106: preco = 1 * qtd; break;
        default: printf("Invalido\n"); return;
    }
    printf("O valor ficou em: %.2f\n", preco);
}

void aumentoPreco() {
    float aumento;

    printf("De o valor antigo do produto: ");
    int precoA = lerInt();

    if (precoA < 51) {
        aumento = precoA * 1.05;
    } else if (precoA <= 100) {
        aumento = precoA * 1.10;
    } else {
        aumento = precoA * 1.15;
    }

    printf("O novo preco ficou em: %.2f\n", aumento);

    if (aumento < 81) {
        printf("Portanto o produto esta > > barato. < <\n");
    } else if (aumento <= 120) {
        printf("Portanto o produto esta > > normal. < <\n");
    } else if (aumento <= 200) {
        printf("Portanto o produto esta > > caro. < <\n");
    } else {
        printf("Portanto o produto esta > > muito caro. < <\n");
    }
}

void tarifaEstacionamento() {
    float eH, eM, sH, sM;
    float entrada, saida;
    float hP, total;
    int permanencia;

    printf("\n-> Digite a hora de entrada.\nEx: 2 30\n-> ");
    scanf("%f %f", &eH, &eM);
    printf("Digite a hora de saida.\nEx: 4 30\n-> ");
    scanf("%f %f", &sH, &sM);

    if (eH > sH) eH -= 24;

    entrada = eH * 60 + eM;
    saida = sH * 60 + sM;

    permanencia = saida - entrada;
    hP = (permanencia % 60 > 0) ? permanencia / 60 + 1 : permanencia / 60;

    if (hP <= 2) {
        total = hP * 1;
    } else if (hP <= 4) {
        total = hP * 1.4;
    } else {
        total = hP * 2;
    }
    printf("O total a pagar e de R$%.2f\n", total);
}

void reajusteSalarial() {
    float reajuste, bonus;

    printf("\nDigite seu salario atualmente: ");
    float salarioatual = lerFloat();
    printf("Digite quantos anos trabalho aqui: ");
    int temposerv = lerInt();

    if (salarioatual <= 500) reajuste = 0.25;
    else if (salarioatual <= 1000) reajuste = 0.20;
    else if (salarioatual <= 1500) reajuste = 0.15;
    else if (salarioatual <= 2000) reajuste = 0.10;
    else reajuste = 0.0;

    if (temposerv < 1) bonus = 0.0;
    else if (temposerv <= 3) bonus = 100.0;
    else if (temposerv <= 6) bonus = 200.0;
    else if (temposerv <= 10) bonus = 300.0;
    else bonus = 500.0;

    printf("O salario reajustado ficou em: %.2f\n", salarioatual + (salarioatual * reajuste) + bonus);
}

void custoConsumidor() {
    float custoFab, custoCons, com, imp;

    printf("\nDigite o custo de fabricacao da fabrica: R$");
    custoFab = lerFloat();

    if (custoFab <= 12000) {
        com = 0.05;
        imp = 0;
    } else if (custoFab <= 25000) {
        com = 0.10;
        imp = 0.15;
    } else {
        com = 0.15;
        imp = 0.20;
    }

    custoCons = custoFab * (1 + com + imp);
    printf("\nO custo ao consumidor eh de: R$%.2f\n", custoCons);
}