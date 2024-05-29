// Faça um programa que solicite ao usuário para digitar um número. Logo após, calcular o dobro
// deste número, depois elevar o valor calculado ao quadrado e exibir:
#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int n = 0, dobro = 0, quadrado = 0;

    printf("digite um numero\n");
    scanf("%d", &n);
    dobro = n + n;
    printf("Dobro = %d\n", dobro);
    quadrado = dobro * dobro;
    printf("Quadrado = %d\n", quadrado);
    return 0;
}