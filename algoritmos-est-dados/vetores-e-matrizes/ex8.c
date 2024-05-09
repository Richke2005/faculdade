// Faça um programa que leia um vetor de 10 posições e verifique se existem valores
// iguais e os escreva na tela.
#include <stdio.h>

int main(void){
    int vetor[10], i;
    for(i = 0; i < 10; i++){
        printf("Digite o valor do vetor.\nVetor[%d]\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = 1; i < 10; i++){
        if(vetor[i - 1] == vetor[i]){
            printf("Valor igual encontrado %d na posicao vetor[%d]\n", vetor[i], i);
        }
    }
    return 0;
}