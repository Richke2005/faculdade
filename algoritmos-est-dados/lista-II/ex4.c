#include <stdio.h>
int mediaTurma(int qtdAlunos, int []);
int mediaEscola(int, int);
int mediaEscola(int, int[]);

int main(void){
    
    return 0;
}

int mediaTurma(int qtdAlunos, int notas[]){
    int soma = 0, i;
    for(int i; i < qtdAlunos; i++){
        soma += notas[i];
    }
    return soma / qtdAlunos;
}

int mediaEscola(int qtdTurmas, int sumNotasTurmas){
    return sumNotasTurmas / qtdTurmas;
}

int mediaEscola(int qtdTurmas, int notasTurma[]){
    int soma = 0, i;
    for(i = 0; i < qtdTurmas; i++){
        soma += notasTurma[i];
    }
    return soma / qtdTurmas;
}