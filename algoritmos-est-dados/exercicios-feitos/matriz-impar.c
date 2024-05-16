#include <stdio.h>

int main(void){
    int vetor[100];

    for(int i = 0; i < 100; i++){
        if(i % 2 != 0)
            vetor[i] = i;
    }

    for(int i = 0; i < 100; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}