// Faça um programa que preencha um vetor com 10 números reais, calcule e mostre
// a quantidade de números negativos e a soma dos números positivos desse vetor.
#include <stdio.h>

int main(void){
    float vetor[10], soma = 0.0;
    int qtdNegativos = 0, i;

    for(i = 0; i < 10; i++){
        printf("Digite valores reais n > 0 ou n < 0 para o vetor [%d]\n", i + 1);
        scanf("%f", &vetor[i]);
    }

    for(i = 0; i < 10; i++){
        if(vetor[i] > 0){
            soma += vetor[i];
        }else{
            qtdNegativos++;
        }
    }

    printf("A quantidade de numeros negativos e %d\nA soma dos numeros no vetor e %.2f", qtdNegativos, soma);
    return 0;
}