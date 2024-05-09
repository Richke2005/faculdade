// Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.
#include <stdio.h>

int main(void){
    int matriz[4][4],soma = 0, i, j;
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("Digite um valor para matriz[%d][%d]\n", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    } 

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(matriz[i][j] > 10){
                printf("Matriz[%d][%d] = %d  Maior que 10\n",i + 1, j + 1,matriz[i][j]);
                soma++;
            }
        }
    }

    printf("Ha %d valores maiores que 10", soma);

    return 0;
}