// Leia um vetor de 10 posições e atribua valor 0 para todos os elementos que
// possuírem valores negativos.
#include <stdio.h>

int main(void){
    int vetor[10], i;
    for(i = 0; i < 10; i++){
        printf("Digite o valor real para o vetor.\nVetor[%d]\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 10; i++){
        if(vetor[i] < 0){
            vetor[i] = 0;
        }
    }

    for(i = 0; i < 10; i++){
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
  
