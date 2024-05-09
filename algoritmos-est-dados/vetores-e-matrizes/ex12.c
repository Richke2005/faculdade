// Leia uma matriz 4 x 4, imprima a matriz e retorne a localização (linha e a coluna) do
// maior valor.
#include <stdio.h>
#include <stdlib.h>

struct Bigger{
    int i, j;
    int maior;
};

int main(void){
    int matriz[4][4], i, j;
    struct Bigger b;
    b.maior = 0;
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            matriz[i][j] = rand() % (10 + 1);
        }
    } 

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(matriz[i][j] > b.maior){
                b.maior = matriz[i][j];
                b.i = i;
                b.j = j;
            }
        }
    }

    printf("Localizacao do maior valor na matriz[%d][%d] = %d", b.i, b.j, b.maior);
    return 0;
}