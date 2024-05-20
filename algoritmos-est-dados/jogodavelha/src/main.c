#include <stdio.h>
#include "./functions/functions.h"
#include "./models/user.h"


int main(void){
    char matriz[3][3];
    int counter, nPlayers;
    

    fillMatriz(matriz);
    printf("|-------------------------------------------|\n");
    printf("| Olá bem vindo ao jogo da velha jogador!!! |\n");
    printf("|-------------------------------------------|\n\n");  
    printf(" Quantos jogadores irão participar:\n 1 or 2 ?\n");
    scanf("%d", &nPlayers);
    struct user players[nPlayers];

    for(int i = 0; i < nPlayers; i++){
        printf("Digite o nome do jogador %d:\n", i+1);
        scanf("%s", players[i].name);
    }

    do{
        printf("hello");
    }while(!gameOver(matriz) || !end('s'));

    return 0;
}