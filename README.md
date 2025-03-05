# Repositório de Estudos em C

Este repositório contém diversos códigos e exemplos sobre conceitos fundamentais da linguagem C. Abaixo está um índice com os tópicos abordados e uma descrição de cada um deles.

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
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/basico)  
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
    float pi = 3.14;
    char letra = 'A';
    printf("Inteiro: %d\n", num);
    printf("Float: %.2f\n", pi);
    printf("Caractere: %c\n", letra);
    return 0;
}
```

## Condicional
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/condicional)  
Estruturas de controle de fluxo:
- `if`, `else`, `else if`
- `switch-case`
- Operador ternário

Exemplo:
```c
#include <stdio.h>

int main() {
    int num = 10;

    if (num > 0) {
        printf("Número positivo\n");
    } else {
        printf("Número negativo ou zero\n");
    }

    return 0;
}
```

## Funções
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/funcoes)  
Definição e uso de funções:
- Declaração e chamada de função
- Passagem de parâmetros (por valor e por referência)
- Recursão

Exemplo:
```c
#include <stdio.h>

void saudacao() {
    printf("Olá, mundo!\n");
}

int main() {
    saudacao();
    return 0;
}
```

## Laços
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/lacos)  
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
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/memoriaDinamica)  
Alocação dinâmica de memória usando:
- `malloc`, `calloc`, `realloc`, `free`

Exemplo:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(sizeof(int) * 5);
    if (ptr == NULL) {
        printf("Falha na alocação de memória\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 10;
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}
```

## Ponteiros
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/ponteiro)  
Conceitos essenciais sobre ponteiros:
- Declaração e manipulação
- Ponteiros e arrays
- Ponteiros para funções

Exemplo:
```c
#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;

    printf("Valor de x: %d\n", *ptr);
    return 0;
}
```

## Strings
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/string)  
Manipulação de cadeias de caracteres:

Exemplo:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char nome[20];
    strcpy(nome, "Alice");
    printf("Nome: %s\n", nome);
    return 0;
}
```

## Vetores e Matrizes
[Pasta com exemplos](https://github.com/sthecss/PP-BCC/tree/main/vetorEmatriz)  
Trabalho com arrays unidimensionais e bidimensionais:

Exemplo:
```c
#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
```
```
