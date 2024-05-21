#include <stdio.h>
void showGame(char matriz[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(j == 1)
                 printf("| %c |",matriz[i][j]);
            else
            printf(" %c ",matriz[i][j]);
        }
        printf("\n");
        if (i == 2)
            break;
        printf("---|---|---\n");
    }
}

void fillMatriz(char matriz[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matriz[i][j] = '?';
        }
    }
}

int gameOver(char matriz[3][3]){
    return 0;
}

int end(char word){
    return 0;
}

void play(int l, int j, char matriz[3][3], int player){
    if(player == 0){
        matriz[l - 1][j - 1] = 'X';
        player++;
    }else if(player == 1){
        matriz[l - 1][j - 1] = 'O';
        player--;
    }
}