#include <stdio.h>
void maximo(int, int, int);

int main(void){
    int n1, n2, n3;

    printf("Digite 3 numeros para determinar o maior:\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    maximo(n1, n2, n3);
    return 0;
}

void maximo(int n1, int n2, int n3){
    int maior = n1 > n2 ? n1 : n2;
    maior = maior > n3 ? maior : n3;
    printf("O maior numero e %d\n", maior);
    int menor = n1 < n2 ? n1 : n2;
    menor = menor < n3 ? menor : n3;
    printf("O menor numero e %d\n", menor);
}
