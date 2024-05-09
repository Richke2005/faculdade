#include <stdio.h>
int Func(int a, int b, int c);

int main(void){
    int vetor[5], w = 0, i = 0, j = 0, x = 0;

    for(i = 0; i < 5; i++)
        vetor[i] = 5;

    for(j = 0; j < 5; j++)
        w = w + vetor[j];

    x = Func(w, vetor[0], vetor[4]);

    printf("%d", x);

    return 0;
}

int Func(int a, int b, int c){
    return (a + b + 2 * c);
}