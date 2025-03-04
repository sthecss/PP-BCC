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

void exibirTextos() {
    printf("\n=== Menu de Exercicios ===\n");
    printf("01. Dado um N, soma so triplo do sucessor com o dobro do antecessor\n");
    printf("02. Calculo da hipotenusa de um triangulo\n");
    printf("03. Calculo do volume de um cilindro\n");
    printf("04. Aumento de salario de 25%%\n");
    printf("05. Divisao de premio entre tres ganhadores\n");
    printf("06. Calculo de salario com descontos e bonus\n");
    printf("07. Programa de ajuda para vendedores\n");
    printf("08. Calculo de degraus para alcancar uma altura\n");
    printf("09. Conversao de letra maiuscula para minuscula\n");
    printf("10. Inversao de numero de tres digitos\n");
    printf("11. Impressao de numero de quatro digitos, um por linha\n");
    printf("12. Conversao de segundos para horas, minutos e segundos\n");
    printf("13. Calculo do termino de um experimento biologico\n");
    printf("14. Calculo do ano de nascimento\n");
    printf("15. Calculo da distancia de um ponto ate a origem\n");
    printf("16. Divisao de premio entre tres amigos\n");
    printf("0. Sair\n");
}

void somaSucessorAntecessor() {

    printf("Digite um numero inteiro: ");
    int num = lerInt();

    int antecessor = (num * 2) - 1;
    int sucessor = (num * 3) + 1;
    int soma = antecessor + sucessor;
    printf("Soma do sucessor do triplo e antecessor do dobro: %d\n", soma);
}

void calculaHipotenusa() {
    float a, b;
    printf("Digite os valores dos dois catetos: ");
    scanf("%f %f", &a, &b);
    float hipotenusa = sqrt(a * a + b * b);
    printf("Hipotenusa: %.2f\n", hipotenusa);
}

void calculaVolumeCilindro() {
    float altura, raio;
    printf("Digite a altura e o raio do cilindro: ");
    scanf("%f %f", &altura, &raio);
    float volume = 3.141592 * raio * raio * altura;
    printf("Volume do cilindro: %.6f\n", volume);
}

void aumentoSalario() {
    printf("Digite o salario: ");
    float salario = lerFloat();
    float novoSalario = salario * 1.25;
    printf("Novo salario com aumento de 25%%: %.2f\n", novoSalario);
}

void divisaoPremio() {
    float premio = 780000;
    float ganhador1 = premio * 0.46;
    float ganhador2 = premio * 0.32;
    float ganhador3 = premio * 0.22;
    printf("Premio para o primeiro ganhador: %.2f\n", ganhador1);
    printf("Premio para o segundo ganhador: %.2f\n", ganhador2);
    printf("Premio para o terceiro ganhador: %.2f\n", ganhador3);
}

void calculaSalario() {
    printf("Escolha o tipo de calculo:\n");
    printf("1. Salario com desconto de 8%%\n");
    printf("2. Salario com bonus de 10%%\n");
    printf("3. Salario com gratificacao de 5%% e desconto de 7%%\n");
    int opcao = lerInt();

    if (opcao == 1) {
        float salario = 30.00;
        printf("Digite o numero de dias trabalhados: ");
        float dias = lerFloat();
        float salarioFinal = (salario - salario * 0.08) * dias;
        printf("Salario final: R$%.2f\n", salarioFinal);
    } else if (opcao == 2) {
        float valorHora = 6.00;
        printf("Digite o numero de horas trabalhadas: ");
        float horas = lerFloat();
        float salarioFinal = (valorHora * horas) * 1.10;
        printf("Salario final com bonus: R$%.2f\n", salarioFinal);
    } else if (opcao == 3) {
        printf("Digite o salario base: ");
        float salarioBase = lerFloat();
        float salarioFinal = (salarioBase * 1.05) - (salarioBase * 0.07);
        printf("Salario final: R$%.2f\n", salarioFinal);
    }
}

void ajudaVendedor() {
    printf("Digite o valor do produto: ");
    float valorProduto = lerFloat();
    float valorDesconto = valorProduto * 0.90;
    float valorParcela = valorProduto / 3;
    float comissaoAVista = valorDesconto * 0.05;
    float comissaoParcelada = valorProduto * 0.05;
    printf("Valor com desconto de 10%%: R$%.2f\n", valorDesconto);
    printf("Valor da parcela (3x sem juros): R$%.2f\n", valorParcela);
    printf("Comissao a vista: R$%.2f\n", comissaoAVista);
    printf("Comissao parcelada: R$%.2f\n", comissaoParcelada);
}

void calculaDegraus() {
    printf("Digite a altura do degrau (em cm): ");
    float alturaDegrau = lerFloat();
    printf("Digite a altura que deseja alcancar (em metros): ");
    float alturaDesejada = lerFloat();
    scanf("%f", &alturaDesejada);
    int degraus = (alturaDesejada * 100) / alturaDegrau;
    printf("Numero de degraus a subir: %d\n", degraus);
}

void converteLetra() {
    char letra;
    printf("Digite uma letra minuscula: ");
    scanf(" %c", &letra);
    printf("Letra maiuscula: %c\n", toupper(letra));
}

void inverteNumero() {
    printf("Digite um numero de tres digitos: ");
    int numero = lerInt();
    int invertido = (numero % 10) * 100 + ((numero / 10) % 10) * 10 + numero / 100;
    printf("Numero invertido: %d\n", invertido);
}

void imprimeDigitos() {
    printf("Digite um numero de quatro digitos: ");
    int numero = lerInt();
    printf("%d\n%d\n%d\n%d\n", numero / 1000, (numero / 100) % 10, (numero / 10) % 10, numero % 10);
}

void converteTempo() {
    printf("Digite o tempo em segundos: ");
    int segundos = lerInt();
    int horas = segundos / 3600;
    int minutos = (segundos % 3600) / 60;
    int segundosRestantes = segundos % 60;
    printf("%02d:%02d:%02d\n", horas, minutos, segundosRestantes);
}

void calculaTerminoExperimento() {
    int horaInicio, minutoInicio, segundoInicio;
    printf("Digite o horario de inicio (hh mm ss): ");
    scanf("%d %d %d", &horaInicio, &minutoInicio, &segundoInicio);
    printf("Digite a duracao em segundos: ");
    int duracao = lerInt();
    int horas = duracao / 3600;
    int minutos = (duracao % 3600) / 60;
    int segundos = duracao % 60;
    int horaFinal = horaInicio + horas;
    int minutoFinal = minutoInicio + minutos;
    int segundoFinal = segundoInicio + segundos;
    if (segundoFinal >= 60) {
        segundoFinal -= 60;
        minutoFinal++;
    }
    if (minutoFinal >= 60) {
        minutoFinal -= 60;
        horaFinal++;
    }
    if (horaFinal >= 24) {
        horaFinal -= 24;
    }
    printf("Horario de termino: %02d:%02d:%02d\n", horaFinal, minutoFinal, segundoFinal);
}

void calculaAnoNascimento() {
    int idade, anoAtual;
    printf("Digite sua idade e o ano atual: ");
    scanf("%d %d", &idade, &anoAtual);
    int anoNascimento = anoAtual - idade;
    printf("Ano de nascimento: %d\n", anoNascimento);
}

void calculaDistanciaOrigem() {
    float x, y;
    printf("Digite as coordenadas x e y: ");
    scanf("%f %f", &x, &y);
    float distancia = sqrt(x * x + y * y);
    printf("Distancia da origem: %.2f\n", distancia);
}

void divisaoPremioAmigos() {
    float investimento1, investimento2, investimento3;
    printf("Digite o investimento de cada amigo: ");
    scanf("%f %f %f", &investimento1, &investimento2, &investimento3);
    printf("Digite o valor do premio: ");
    float premio = lerFloat();
    float totalInvestido = investimento1 + investimento2 + investimento3;
    float premio1 = (investimento1 / totalInvestido) * premio;
    float premio2 = (investimento2 / totalInvestido) * premio;
    float premio3 = (investimento3 / totalInvestido) * premio;
    printf("Premio para o primeiro amigo: %.2f\n", premio1);
    printf("Premio para o segundo amigo: %.2f\n", premio2);
    printf("Premio para o terceiro amigo: %.2f\n", premio3);
}