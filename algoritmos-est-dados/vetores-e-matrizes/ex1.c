#include <stdio.h>
#include <math.h>

int main(void){
    float vetor[10];
    float powers[10];
    int i;

    for(i=0; i<10; i++){
        printf("Insira o %d numero há ser armazenado no vetor:\n", i);
        scanf("%f", &vetor[i]);
        powers[i] = pow(vetor[i], 2.0);
    }
    for(i=0; i<10; i++){
        printf("vetor[%d] = %2.f (valores digitados)\n", i, vetor[i]);
        printf("powers[%d] = %2.f (quadrado do valor)\n", i, powers[i]);
    }
    return 0;
}