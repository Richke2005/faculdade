// Faça um programa em "C" que lê dois valores e imprime:

// - se o primeiro valor for menor que o segundo, a lista de valores do primeiro até o segundo;

// - se o primeiro valor for maior que o segundo, a lista de valores do segundo até o primeiro;

// - se ambos forem iguais a mensagem "valores iguais".

#include <stdio.h>
#include <locale.h>

int main(void){
    int i = 0, n1 = 0, n2 = 0;

    printf("Digite o 1 valor\n");
    scanf("%d", &n1);
    printf("Digite o 2 valor\n");
    scanf("%d", &n2);
    printf("\n");
    if(n1 == n2){
        printf("Valores iguais");
    }else if(n1 < n2){
        for(i = n1; i <= n2; i++){
            printf("%d\n", i);
        }
    }else{
        for(i = n1; i >= n2; i--){
            printf("%d\n", i);
        }
    }
}