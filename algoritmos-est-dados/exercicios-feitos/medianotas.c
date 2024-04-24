#include <stdio.h>

int main(void){
    float somaNotas = 0, notas, media;
    int i=0;
    printf("Digite as notas dos alunos\n");
    while(i < 10){
        scanf("%f", &notas);
        somaNotas+=notas;
        i++;
    }
    media = (somaNotas / 10.0);
    printf("A media das notas e %.2f", media);
    return 0;
}