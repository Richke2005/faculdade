#include <stdio.h>

void exibirDivisores(int n);

int main(void){
    int n;

    printf("Digite um numero natural: ");
    scanf("%d", &n);

    if(n > 0){
        prinf("Divisores de %d: \n");
        exibirDivisores(n);
    }else{
        printf("Por favor, digite um numero maior que zero.\n")
    }
    return 0;
}

void exibirDivisores(int n){
    int i;
    for(i = 1; i <= n; i++){
        if(n % i == 0){
            printf("%d", i);
        }
    }
    printf("\n");
}