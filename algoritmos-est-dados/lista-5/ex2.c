// Faça um programa que solicite ao usuário para digitar dois valores inteiros e os armazene em duas

// variáveis N1 e N2. Logo após, o programa deve verificar se esses dois números são diferentes, em caso

// Verdadeiro, o programa deve trocar os valores contidos nas variáveis entre si e os exibe ao usuário

// enfatizando a troca. Caso contrário, ou seja, Falso, o programa deve imprimir um texto “Os valores são

// iguais”.
#include <stdio.h>

int main(void){
    int n1, n2, temp;
    printf("Digite o primeiro numero\n");
    scanf("%d", &n1);
    printf("Digite o segundo numero\n");
    scanf("%d", &n2);

    if(n1 != n2){
        temp = n1;
        printf("Valores antes da troca %d e %d\n", n1, n2);
        n1 = n2;
        n2 = temp;
        printf("Os valores trocados sao %d e %d\n", n1, n2);
    }else{
        printf("Os valores são iguais\n");
    }
    return 0;
}