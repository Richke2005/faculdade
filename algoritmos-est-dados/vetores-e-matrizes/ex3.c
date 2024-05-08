#include <stdio.h>
#include <stdlib.h>

int main(void){
    int vetor[10], somaPares = 0, counter = 0;

    for(int i = 0; i < 10; i++){
        vetor[i] = rand() % (50 + 1);
    }
    // verifica se o numero é par e soma 1 ao contador se for TRUE
    for(int i = 0; i < 10; i++){
        if(vetor[i] % 2 == 0){
            printf("vetor[%d] = %d\n", i, vetor[i]);
            somaPares += vetor[i];
            counter ++;
        }
    }

    printf("A %d valores pares no vetor,\na soma deles e igual a %d ", counter, somaPares);
    return 0;
}