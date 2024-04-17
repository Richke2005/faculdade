#include <stdio.h>
int somaVetores(int[]);
int main(void){
    int vetor[3], i;
    for(i=0; i<3; i++){
        printf("Digite um numero inteiro para posicao [%d] do vetor:\n", i);
        scanf("%d", &vetor[i]);
    }
    printf("A soma dos valores dentro do vetor e: %d", somaVetores(vetor));
}

int somaVetores(int vetor[]){
    int soma = 0;
    for(int i = 0; i < 3; i++){
        soma += vetor[i];
    }
    return soma;
}