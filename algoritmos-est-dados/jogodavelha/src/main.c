#include <stdio.h>
#include "./functions/functions.h"
#include "./models/user.h"


int main(void){
    char matriz[3][3];
    int counter, nPlayers, timeFromP = 0;
    

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
        int l, j;
        //printf("%d\n", timeFromP);
        showGame(matriz);
        printf("%s Digite um numero de 1 a 3 referente a linha e coluna que deseja preencher:\n", 
        players[timeFromP].name);
        scanf("%d %d", &l, &j);
        play(l, j, matriz, &timeFromP);
    }while(1);

    
    //!gameOver(matriz) || !end('s')

    return 0;
}