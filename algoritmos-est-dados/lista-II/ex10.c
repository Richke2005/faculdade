#include <stdio.h>

int main(void){
    int n1, n2, n3;

    printf("Digite 3 numeros para determinar o maior:\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    int maior = n1 > n2 ? n1 : n2;
    maior = maior > n3 ? maior : n3;
    printf("O maior numero e: %d\n", maior);

    return 0;
}