#include <stdio.h>

int main(void){
    int n1, n2, n3;

    printf("Digite 3 numeros para determinar o menor:\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    int menor = n1 < n2 ? n1 : n2;
    menor = menor < n3 ? menor : n3;
    printf("O menor numero e: %d\n", menor);

    return 0;
}