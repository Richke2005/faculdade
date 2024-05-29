// Faça um programa que solicite ao usuário para digitar dois valores, neste caso o primeiro valor é o
// lado X de um retângulo e o segundo valor o lado Y. Logo após, calcular a área deste retângulo e exibir:

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int x = 0, y = 0, area = 0;
    printf("Escreva o lado x do terreno em metros\n");
    scanf("%d", &x);
    printf("Escreva o lado y do terreno em metros\n");
    scanf("%d", &y);

    area = x * y;
    printf("Area do terreno = %dm²\n", area);
    return 0;
}