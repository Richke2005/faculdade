// Programa que recebe diversos valores digitados pelo usuário até preencher um vetor com 5

// elementos. Solicite ao usuário para digitar valores entre 0 e 100.

// Depois imprime o maior valor dentro do vetor.
#include <stdio.h>
void maiorVal(int []);

int main(void){
    int vet[5];
    for(int i = 0; i < 5; i++){
        printf("Digite um valor entre 0 e 100: ");
        scanf("%d", &vet[i]);
    }
    maiorVal(vet);
    return 0;
}

void maiorVal(int vet[5]){
    int maior = vet[0];
    for(int i = 1; i < 5; i++){
        maior = (maior > vet[i]) ? maior : vet[i];
    }
    printf("O maior valor e %d\n", maior);
}