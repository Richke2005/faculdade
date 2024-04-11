#include <stdio.h>
int fibonacci(int n);

int main(void){
    int n;
    printf("Digite o n termo da sequencia de fibonacci\n");
    scanf("%d", &n);
    printf("Numero = %d", fibonacci(n));
    return 0;
}

int fibonacci(int n){
    int  ant = 0, current = 1, next, i;

    for(i = 0; i < n; i++){
        next = ant + current;
        ant = current;
        current = next;
    }
    return current;
}