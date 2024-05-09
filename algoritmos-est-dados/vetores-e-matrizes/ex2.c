#include <stdio.h>
#include <stdlib.h>

int main(void){
    int vetor[8], num1, num2;

    printf("forneca 2 valores para busca no vetor:\n");
    scanf("%d %d", &num1, &num2);

    for(int i = 0; i < 8; i++){
        vetor[i] = rand() % (10 + 1);
    }
    
    for (int i = 0; i < 8; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("A soma dos valores presentes em vetor[%d] e vetor[%d] e %d", num1, num2, (vetor[num1] + vetor[num2]));
    return 0;
}