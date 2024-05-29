// Faça um programa que solicite ao usuário para digitar um número x. Logo após, calcula e exibe

// na tela a tabuada do número digitado pelo usuário.

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int x, i = 0, tabuada = 0;
    printf("Digite um número: ");
    scanf("%d", &x);
    while(i <= 10){
        tabuada = x * i;
        printf("%d X %d = %d\n", x, i, tabuada);
        i++;
    }
    return 0;
}