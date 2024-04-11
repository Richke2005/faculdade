#include <stdio.h>
#include <locale.h>
//faça um programa que solicite ao usuario para digitar 3 numeros.
//exibir o maior e o menor valor. informar caso os 3 sejam inguais
int main(void){
    setlocale(LC_ALL, "Portuguese");
    char jogoVelha[3][3];
    int l, c, searchedValue, qtd = 0;
    printf("Digite um valor para achar:\n");
    scanf("%d", &searchedValue);
    for(l=0; l < 3; l++){
        for(c=0; c < 3; c++){
        jogoVelha[l][c] = c + l;
        printf("jogoVelha[%d][%d] = %d\n", l, c, jogoVelha[l][c]);
        if(jogoVelha[l][c] == searchedValue){
            qtd++;
            printf("Valor %d encontrado %d vezes na posicao jogovelha[%d][%d] ", jogoVelha[l][c], qtd, l, c);
        }
        }
    }
    return 0;
}

