#include <stdio.h>
#define SIZE 5
void diagonalPrincipal();

int main(void){
    diagonalPrincipal();
    return 0;
}

void diagonalPrincipal(){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(i == j){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
