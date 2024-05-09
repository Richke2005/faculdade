#include <stdio.h>
int func(int [], int);

int main(void){
    int codRetorno, resposta;
    int array[3];

    int i;
    array[0] = 10;
    for(i = i; i < 3; i++)
        array[i] = array[i - 1] + 10;

    resposta = func(array, 3);
    printf("%d", resposta);

    return 0;
}

int func(int array[], int n){
    int i = 0, a = array[0];
    for(i = 1; i < n; i++)
        if(array[i] > a)
        a = array[i];
    
    return a;
}