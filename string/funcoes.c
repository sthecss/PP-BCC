#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int lerInt() {
    int numero;
    printf("-> ");
    scanf("%d", &numero);
    while (getchar() != '\n');
    return numero;
}

float lerFloat() {
    float numero;
    printf("-> ");
    scanf("%f", &numero);
    while (getchar() != '\n');
    return numero;
}

char lerChar() {
    char caractere;
    fflush(stdin);
    printf("-> ");
    scanf("%c", &caractere);
    return caractere;
}

void inverterString() {
    char str[30];
    int i, tamanho;

    printf("\n-> Apresente uma palavra: ");
    fgets(str, 30, stdin);

    tamanho = strlen(str);

    printf("\n- Essa palavra de tras pra frente eh: \n");
    for(i = tamanho - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

void contarESubstituirVogais() {
    char str[50], caractere;
    int i, vogal = 0;

    printf("\n- Digite uma palavra qualquer: ");
    fgets(str, 50, stdin);

    for(i = 0; i < strlen(str); i++) {
        if((str[i] == 'a') || (str[i] == 'i') || (str[i] == 'e') || (str[i] == 'o') || (str[i] == 'u')) {
            vogal++;
        } else if ((str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U')) {
            vogal++;
        }
    }

    printf("\n- A palavra tem [ %d ] vogais.\n", vogal);

    printf("\n- Quer trocar as vogais por qual character? ");
    scanf("%c", &caractere);

    for(i = 0; i < strlen(str); i++) {
        if((str[i] == 'a') || (str[i] == 'i') || (str[i] == 'e') || (str[i] == 'o') || (str[i] == 'u')) {
            str[i] = caractere;
        } else if ((str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U')) {
            str[i] = caractere;
        }
    }

    printf("\n- Todas as vogais da palavra apresentada foram\n"
           "substituidas pelo caractere '%c', e o resultado ficou: \n ", caractere);
    printf("\n> %s ", str);
}

void converterMaiusculasMinusculas() {
    char str[250];
    int i, tam;
    char opcao;

    while (1){
        printf("\n0. Para sair"
               "\n(   Escolha a conversao   )");
        printf("\n1. Maiusculas -> Minusculas"
               "\n2. Minusculas -> Maiusculas\n\n");
        opcao = lerChar();

        if (opcao == '0')
            break;

        printf("\n- Digite a frase: ");
        fflush(stdin);
        fgets(str, 250, stdin);
        str[strcspn(str, "\n")] = '\0';

        tam = strlen(str);
        for (i = 0; i < tam; i++) {
            if (opcao == '1') {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] += 32;
            } else if (opcao == '2') {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] -= 32;
            }
        }

        printf("\n- A frase convertida ficou da seguinte forma: %s\n", str);
    }
}

void removerEspacos() {
    char str[500];
    int i, j = 0;

    printf("\n- Digite uma frase qualquer: ");
    fgets(str, 500, stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("\n- A frase com os espaços apagados: %s", str);
}

void substituirCaracteres() {
    char stg[100], l1, l2;
    int i, tam;

    printf("\n- Digite uma frase: ");
    fgets(stg, sizeof(stg), stdin);

    tam = strlen(stg);
    if (stg[tam - 1] == '\n') {
        stg[tam - 1] = '\0';
    }

    printf("\n- Agora escolha uma letra da frase acima: ");
    l1 = lerChar();

    printf("\nE por último, uma troca equivalente."
           "\n\n- Digite uma letra para fazer a substituicao: ");
    l2 = lerChar();

    for (i = 0; stg[i] != '\0'; i++) {
        if (stg[i] == l1)
            stg[i] = l2;
    }

    printf("\n-> O resultado da substituicao ficou da seguinte forma: \n%s\n", stg);
}

void calcularDesconto() {
    int qtd, i, forma_pagamento, total=0;
    char mercadoria[100][250];
    float valores[100], pagamento;

    printf("\n-> Quantidade de itens que quer cadastrar: ");
    qtd = lerInt();

    for (i = 0; i < qtd; i++) {
        printf("\n- Digite o nome da mercadoria: ");
        fgets(mercadoria[i], sizeof(mercadoria[i]), stdin);

        size_t tam = strlen(mercadoria[i]);
        if (mercadoria[i][tam - 1] == '\n') {
            mercadoria[i][tam - 1] = '\0';
        }
    }

    for (i = 0; i < qtd; i++) {
        printf("\n- Qual o valor do(a) %s? R$ ", mercadoria[i]);
        valores[i] = lerFloat();

        total += valores[i];
    }

    printf("\n(1) Pagamento a vista\n(2) Pagamento parcelado\n- Digite o numero referente a operacao: ");
    forma_pagamento = lerInt();

    if (forma_pagamento == 1) {
        pagamento = total * 0.9;
        printf("\n!! Tera desconto de 10%% sobre o valor total !!");
        printf("\n> Descontando os 10%%, o valor a ser pago sera de: R$%.2f;\n", pagamento);
    } else if (forma_pagamento == 2) {
        printf("\n!! O produto nao tem desconto !!");
        printf("\n> O valor a ser pago parcelado e de: R$%.2f;\n", total);
    }
}

void criptografarCesar() {
    char stg[300];
    int i, tam;

    printf("\n- Vamos criptografar!\n\n- Digite a frase:\n| ");
    fgets(stg, 300, stdin);

    tam = strlen(stg);

    for (i = 0; i < tam; i++) {
        stg[i] = stg[i] + 3;
        if(stg[i] == '#') {
            stg[i] = ' ';
        }
    }

    printf("\n- Usando o codigo de Cesar, a criptrografia ficou da seguinte forma:\n|%s", stg);
}

void verificarPalindromo() {
    char str[250];
    int i, tam, j = 0, pos = 0;

    printf("\n!! Palindromos !!\n- Digite uma frase qualquer para verificar se e palindromo: ");
    fflush(stdin);
    fgets(str, 250, stdin);

    tam = strlen(str);

    for (i = 0; i < tam; i++) {
        while(str[i] == 32) {
            for (j = i; j < tam - 1; j++) {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }

    tam = strlen(str) - 1;

    for (i = 0; i < tam; i++) {
        if (str[i] != str[tam - i - 1]) {
            pos = 1;
        }
    }

    if (pos == 0) {
        printf("\n< < < < Eh um palindromo! > > > >");
    } else {
        printf("\n< < < < Nao eh um palindromo > > > >");
    }
}

void concatenarStrings() {
    char str1[100], str2[100];
    int num = 0;

    printf("\n- Digite a primeira string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("\n- Digite a segunda string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    do {
        printf("\n- Agora o numero de caracteres que voce quer concatenar: ");
        num = lerInt();
    } while (strlen(str2) < num);

    str2[num] = '\0';

    printf("\n- Resultado da concatenação: %s\n", strcat(str1, str2));
}

void encontrarMaiorProduto() {
    char str[1002];
    int i;

    srand(time(NULL));

    for (i = 0; i < 1001; i++) {
        str[i] = '0' + (rand() % 10);
    }
    str[1001] = '\0';

    printf("String gerada:\n%.1000s\n", str);

    int produto, maior_produto = 0, voltas, m1, m2, m3, m4, m5;

    for (voltas = 0; voltas < 1001 - 4; voltas++) {
        int n1 = str[voltas] - '0';
        int n2 = str[voltas + 1] - '0';
        int n3 = str[voltas + 2] - '0';
        int n4 = str[voltas + 3] - '0';
        int n5 = str[voltas + 4] - '0';

        produto = n1 * n2 * n3 * n4 * n5;

        if (produto > maior_produto) {
            maior_produto = produto;
            m1 = n1;
            m2 = n2;
            m3 = n3;
            m4 = n4;
            m5 = n5;
        }
    }

    printf("\nO maior produto de 5 digitos consecutivos e: %d\n", maior_produto);
    printf("Os dagitos sao: %d%d%d%d%d\n", m1, m2, m3, m4, m5);
}