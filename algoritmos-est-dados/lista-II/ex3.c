#include <stdio.h>
int primo(int);
int somaPrimos(int);

int main(void){
    int n; 
    printf("Digite um numero inteiro para soma dos primos:\n");
    scanf("%d", &n);
    printf("A soma dos numeros dos primeiros numero primos ate %d e:\n%d", n, somaPrimos(n));
    return 0;
}

int primo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int somaPrimos(int n){
int soma = 0, num = 2;
    for(int i = 0; i < n; i++){
        if(primo(num)){
            soma+=num;
        }
        num++;
    }
return soma;
}