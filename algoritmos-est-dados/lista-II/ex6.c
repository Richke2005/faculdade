#include <stdio.h>
#include <math.h>
int somatorio(int n);

int main(void){
    int n;
    printf("Digite um valor para n:\n");
    scanf("%d", &n);
    printf("O valor do somatorio e %d", somatorio(n));
}


int somatorio(int n){
    int i = 1;
    return 5 * pow(i, 2) + 2 * i + 8;
}
