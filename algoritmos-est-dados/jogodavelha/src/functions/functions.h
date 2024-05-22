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

void play(int l, int j, char matriz[3][3], int *player){
    if(*player == 0){
        *player = 1;
        matriz[l - 1][j - 1] = 'X';
    }else if(*player == 1){
        *player = 0;
        matriz[l - 1][j - 1] = 'O';
    }
}

void fillWithX(int l, int j, char matriz[3][3]){
    matriz[l - 1][j - 1] = 'X';
}

void fillWithO(int l, int j, char matriz[3][3]){
    matriz[l - 1][j - 1] = 'O';
}

void verifyWinner(char matriz[3][3]){
    //verificar transversais
    //verifica verticais
    //verificar diagonais
}

int diagons(char matriz[3][3]){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(matriz[i][j] == matriz[i+1][j+1] && matriz[i+1][j+1] == matriz[i+2][j+2] && matriz[i][j]!= '?'){
                return 1;
            }
        }
    }
    return 0;
}