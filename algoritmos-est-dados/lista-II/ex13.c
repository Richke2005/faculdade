#include <stdio.h>

int maiorNumero(int, int);

int main(void){
    int n1, n2;
    printf("Digite 2 numeros para verificar qual e o maior:\n");
    scanf("%d %d", &n1, &n2);
    printf("O maior numero e %d", maiorNumero(n1, n2));
    return 0;
}

int maiorNumero(int n1, int n2){
    int maior = n1 > n2 ? n1 : n2;
    return maior;
}