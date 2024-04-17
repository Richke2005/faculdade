#include <stdio.h>
int maiorNumeroT(int []);
int maiorNumeroIf(int []);
int main(void){
    int vetor[3], i;
    for(i=0; i<3; i++){
        printf("Digite um numero inteiro para posicao [%d] do vetor:\n", i);
        scanf("%d", &vetor[i]);
    }
    printf("O maior numero e %d", maiorNumeroT(vetor));
}

int maiorNumeroT(int vetor[]){
    int maior = vetor[0], i;
    for(i = 0; i < 3; i++ ){
        maior = maior > vetor[i] ? maior : vetor[i];
    }
    return maior;
}

int maiorNumeroIf(int vetor[]){
    int maior = vetor[0], i;
    for(i=0; i < 3; i++){
        if(maior > vetor[i]){
            maior = maior;
        }else{
            maior = vetor[i];
        }
    }
    return maior;
}