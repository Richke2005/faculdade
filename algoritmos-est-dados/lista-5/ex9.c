// Escreva um algoritmo em C que imprima todos os números ímpares do intervalo fechado de 1 a

// 100.
#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int tamanho = 100;
    int i = 0, impar = 0;
    for(i = 1; i <= tamanho; i++){
        impar = i % 2;
        if(impar != 0){
            printf("%d\n", i);
        }
    }
    return 0;
}