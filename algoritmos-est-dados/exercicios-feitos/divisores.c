#include <stdio.h>

int main(void){
    int n, soma; 
    printf("Digite um numero");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            printf("Valores divisiveis %d", i);
            soma+=i;
        }
    }
    printf("%d", soma);
}