# include <stdio.h>

typedef struct{
    double peso;
    int idade;
    double altura;
} pessoa;

void imprimePessoa(pessoa a){
    printf("%.2f\n\n", p.peso);
}

int main(void){
    pessoa pessoas[20], p1;
    pessoas[5].peso = 79.6;
    pessoas[5].idade = 45;
    pessoas[5].altura = 1.87;

    p1 = pessoas[5];
    p1.idade++;
    if(p1.idade > 40)
        p1.peso = p1.peso += 5.0;

    imprimePessoa(p1);
}