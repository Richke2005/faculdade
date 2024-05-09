#include <stdio.h>
int somatorio(int n);

int main(void){
    int n;

    printf("Digite o valor de n para o somatorio: ");
    scanf("%d", &n);

    int resultado = somatorio(n);
    printf("O resultado do somatorio e: %d\n", resultado);
    return 0;
}

int somatorio(int n){
    int i, soma = 0;
    for(i = 1; i <= n; i++){
        soma += 2 * i * i + 2 * i + 1;
    }
    return soma;
}