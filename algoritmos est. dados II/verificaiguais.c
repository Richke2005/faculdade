#include <stdio.h>
#include <locale.h>
//faça um programa que solicite ao usuario para digitar 3 numeros.
//exibir o maior e o menor valor. informar caso os 3 sejam inguais
int main(void){
    setlocale(LC_ALL, "Portuguese");
    int n1, n2,n3;
    printf("Digite 3 valores consecutivos:\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    if(n1 == n2 && n2 == n3){
        printf("Os valores %d, %d, %d sao iguais\n", n1, n2, n3);
    }else{
        int maior = n1 > n2 ? n1 : n2;
        maior = maior > n3 ? maior : n3;
        int menor = n1 < n2 ? n1 : n2;
        menor = menor < n3 ? menor : n3;

        printf("O menor valor e %d\nO maior valor e %d", menor, maior);
    }

    return 0;
}

