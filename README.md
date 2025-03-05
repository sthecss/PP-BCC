# Repositório de Estudos em C

Este repositório contém diversos códigos e exemplos sobre conceitos fundamentais da linguagem C.

## Índice

- [Básico](#básico)  
- [Condicional](#condicional)  
- [Funções](#funcoes)  
- [Laços](#lacos)  
- [Memória Dinâmica](#memoria-dinamica)  
- [Ponteiros](#ponteiros)  
- [Strings](#strings)  
- [Vetores e Matrizes](#vetores-e-matrizes)  

## Básico
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/blob/main/basico/aprendendoFuncionalidades/funcoes.c)  
Conceitos fundamentais da linguagem C, incluindo:
- Entrada e saída de dados (`printf`, `scanf`)
- Tipos de dados e variáveis
- Operadores aritméticos e lógicos

### Máscaras de Formatação em C

As máscaras de formatação são utilizadas para definir como os dados devem ser exibidos ou lidos. Algumas das principais são:

- `%d` → Inteiro decimal (`int`)
- `%f` → Número de ponto flutuante (`float`)
- `%lf` → Número de ponto flutuante (`double`)
- `%c` → Caractere (`char`)
- `%s` → String (`char[]`)
- `%x` → Número hexadecimal
- `%o` → Número octal
- `%p` → Endereço de ponteiro
- `%%` → Imprime o caractere `%`

Exemplo:
```c
#include <stdio.h>

int main() {
    int num = 10;
    float pi = 3.14159;
    char letra = 'A';
    char nome[] = "Alice";

    // Exibindo valores com formatação
    printf("Inteiro: %d\n", num);          // Inteiro decimal
    printf("Float: %.2f\n", pi);           // Float com 2 casas decimais
    printf("Caractere: %c\n", letra);      // Caractere
    printf("String: %s\n", nome);          // String
    printf("Endereço de num: %p\n", &num); // Endereço de memória

    return 0;
}
```

## Condicional
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/blob/main/condicional/funcoes.c)  
Estruturas de controle de fluxo:
- `if`, `else`, `else if`
- `switch-case`
- Operador ternário

Exemplo:
```c
#include <stdio.h>

int main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("Número positivo.\n");
    } else if (num < 0) {
        printf("Número negativo.\n");
    } else {
        printf("Número zero.\n");
    }

    return 0;
}
```

## Funções
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/funcoes/funcoes.c)  
Definição e uso de funções:
- Declaração e chamada de função
- Passagem de parâmetros (por valor e por referência)
- Recursão

Exemplo:
```c
#include <stdio.h>

int quadrado(int x) {
    return x * x;
}

int main() {
    int num = 5;
    printf("O quadrado de %d é %d\n", num, quadrado(num));
    return 0;
}
```

## Laços
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/lacos/funcoes.c)  
Estruturas de repetição:
- `for`
- `while`
- `do-while`
- Uso de `break` e `continue`

Exemplo:
```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("Contagem: %d\n", i);
    }
    return 0;
}
```

## Memória Dinâmica
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/memoriaDinamica/funcoes.c)  
Alocação dinâmica de memória usando:
- `malloc`, `calloc`, `realloc`, `free`

Exemplo:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*) malloc(2 * sizeof(int));
    arr[0] = 10;
    arr[1] = 20;

    arr = (int*) realloc(arr, 4 * sizeof(int));
    arr[2] = 30;
    arr[3] = 40;

    for (int i = 0; i < 4; i++) printf("%d ", arr[i]);
    
    free(arr);
    return 0;
}

```

## Ponteiros
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/ponteiro/funcoes.c)  
Conceitos essenciais sobre ponteiros:
- Declaração e manipulação
- Ponteiros e arrays
- Ponteiros para funções

Exemplo:
```c
#include <stdio.h>

int dobrar(int x) { return x * 2; }
int triplicar(int x) { return x * 3; }

void aplicar(int (*func)(int), int valor) {
    printf("Resultado: %d\n", func(valor));
}

int main() {
    aplicar(dobrar, 5);
    aplicar(triplicar, 5);
    return 0;
}

```

## Strings
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/string/funcoes.c)  
Manipulação de cadeias de caracteres:

Exemplo:
```c
#include <stdio.h>
#include <string.h>

void inverteString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char palavra[] = "C é top!";
    inverteString(palavra);
    printf("Invertida: %s\n", palavra);
    return 0;
}

```

## Vetores e Matrizes
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/vetorEmatriz/funcoes.c)  
Trabalho com arrays unidimensionais e bidimensionais:

Exemplo:
```c
#include <stdio.h>

#define N 3

void transpor(int matriz[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
}

int main() {
    int matriz[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    transpor(matriz);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}

```
