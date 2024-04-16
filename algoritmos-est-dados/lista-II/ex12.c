#include <stdio.h>
int soma(int, int);

int main(void){
    int n1, n2;
    printf("Digite dois numeros para serem calculados:\n");
    scanf("%d %d", &n1, &n2);
    printf("a soma e igual a: %d", soma(n1, n2));

    return 0;
}

int soma(int n1, int n2){
    return n1 + n2;
}