#include <stdio.h>
#include "../models/user.h"

struct user* initPlayers(){
    int nPlayers;
    printf(" Quantos jogadores irão participar:\n 1 or 2 ?\n");
    scanf("%d", &nPlayers);
    struct user players[nPlayers];

    for(int i = 0; i < nPlayers; i++){
        printf("Digite o nome do jogador %d:\n", i+1);
        scanf("%s", players[i].name);
    }

    return players;
}