#include <stdio.h>
#define SIZE 5

int main(void){
    for (int i = 0; i < SIZE; i++){
        for(int j = 5; j > i; j--){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}