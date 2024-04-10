#include <stdio.h>
int isTriangle(int l1, int l2, int l3);
void triangleType(int l1, int l2, int l3);

int main(void){
    int l1, l2, l3;
    printf("digite os 3 lados de um triangulo:\n");
    scanf("%d %d %d", &l1, &l2, &l3);

    if(isTriangle(l1, l2, l3)){
        printf("e um triangulo:\n");
        triangleType(l1, l2, l3);
    }else{
        printf("numeros invalidos\n");
        printf("não forma um triangulo");
    }
    return 0;
}

int isTriangle(int l1, int l2, int l3){
    if(l1 + l2 > l3 && l2 + l3 > l1 && l3 + l1 > l2){
        return 1;
    }else{
        return 0;
    }
}

void triangleType(int l1, int l2, int l3){
    if(l1 == l2 && l1 == l3){
        printf("triangulo equilatero");
    }else if(l1 == l2 || l1 == l3 || l2 == l3){
        printf("triangulo isosceles");
    }else{
        printf("triangulo escaleno");
    }
}