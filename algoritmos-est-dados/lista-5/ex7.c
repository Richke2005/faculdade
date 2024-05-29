// Programa que preenche uma matriz 2x4 e depois imprime os valores da matriz.
#include <stdio.h>

int main(void){
    int matriz[2][4];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            printf("Digite valores de 0 a 100\n");
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            printf("matriz[%d][%d] = %d\n",i, j, matriz[i][j]);
        }
    }
    return 0;
}