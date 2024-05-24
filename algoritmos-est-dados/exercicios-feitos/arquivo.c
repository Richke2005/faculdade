#include <stdio.h>

int main(void){
    FILE *arq = fopen("./arquivo.txt", "r");

    if (arq == NULL){
    printf("Problemas na CRIACAO do arquivo\n");
    return 0;
    }
}