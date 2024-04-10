#include <stdio.h>
int fibonacci(int n);

int main(void){
    return 0;
}

int fibonacci(int n){
    int current = 1, ant = 0, next, i;

    for(i = 0; i < n; i++){
        next = ant + current;
        ant = current;
        current = next;
    }
    return current;
}