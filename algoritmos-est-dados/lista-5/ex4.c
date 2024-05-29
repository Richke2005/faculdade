// Faça um programa que imprime 10 asteriscos (*) em linha e 10 em coluna, formando um

// triângulo conforme imagem abaixo.
// *
// **
// ***
// ****
// *****
// ******

#include <stdio.h>

int main(void){
    int linha, coluna;
    linha = 1;
    while(linha <= 10){
        coluna = 0;
        while(coluna < linha){
            printf("*");
            coluna++;
        }
        printf("\n");
        linha ++;
    }
    return 0;
}
