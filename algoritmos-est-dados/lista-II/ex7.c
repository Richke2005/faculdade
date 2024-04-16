#include <stdio.h>
void rotacao(int* n1, int* n2, int* n3);

int main(void){
    int n1 = 5, n2 = 8, n3 = 9;
    printf("valores antes da rotacao: %d, %d, %d.\n", n1, n2, n3);
    rotacao(&n1, &n2, &n3);
    printf("Valores apos a rotacao: %d, %d, %d.", n1, n2, n3);
}

void rotacao(int* n1, int* n2, int* n3){
    int aux = *n1;
    *n1 = *n2;
    *n2 = *n3;
    *n3 = aux;
}