#include <stdio.h>
#define SIZE 5
void diagonalPrincipal(int[SIZE][SIZE]);

int main(void){
    int matriz[SIZE][SIZE];
    diagonalPrincipal(matriz);

    return 0;
}

void diagonalPrincipal(int matriz[SIZE][SIZE]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(i == j){
                printf("X");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
