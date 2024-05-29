// Escreva um algoritmo em C que imprima todos os números inteiros de 200 a 100 (em ordem

// decrescente).

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int tamanho = 100;
    int i = 0, n = 0;

    for(i = 200; i >= 100; i--){
        printf("%d \n", i);
    }

    return 0;
}