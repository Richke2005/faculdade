#include <stdio.h>

int main(void){
    int n1, n2, n3, soma;

    printf("Digite 3 valores seguidos: \n");
    scanf("%d %d %d", &n1, &n2, &n3);
    soma = n1 + n2 + n3;
    printf("a + b + c = %d\n", n1, n2, n3, soma);
    printf("a - b - c + (a - b - c + a + b + c) = %d\n",  n1 - n2 - n3 + (n1 - n2 - n3 + soma));
    printf("a * b * c = %d\n", n1 * n2 * n3);
    printf("(a + b) / c = %d\n", (n1 + n2) / n3);
    return 0;
}

