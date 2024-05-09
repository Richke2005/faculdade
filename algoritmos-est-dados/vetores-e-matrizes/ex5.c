#include <stdio.h>

int main(void){
    int vetor[6], i;
    
    for(i = 0; i < 6; i++){
        printf("Digite o %d valor do vetor:\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("valor do vetor de tras para frente:\n");
    for(i = 5; i >= 0; i--){
        printf("vetor[%d] - %d\n", i, vetor[i]);
    }

    return 0;
}