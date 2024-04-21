#include <stdio.h>

int main(void){
    int matriz[3][3], l, c;
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            printf("insira o %d valor na matriz\n", (l+1)*(c+1));
            scanf("%d", &matriz[l][c]);
        }
    }
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            printf("matriz[%d][%d] = %d\n", l, c, matriz[l][c]);
        }
    }
    return 0;
}