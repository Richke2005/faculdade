// Escreva um programa que leia 10 números inteiros e os armazene em um vetor.
// Imprima o vetor, o maior elemento e a posição que ele se encontra.
#include <stdio.h>

int main(void){
    int vetor[10], position, maior = 0;

    for(int i = 0; i < 10; i++){
        printf("digite o %d valor do vetor: \n", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 10; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    
    for(int i = 0; i < 10; i++){
        if(maior < vetor[i]){
            maior = vetor[i];
            position = i;
        }
    }

    printf("Maior numero do vetor = %d\nposicao: vetor[%d]", maior, position);
    return 0;
}