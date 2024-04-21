#include <stdio.h>

typedef struct{
    float peso, altura;
    int idade;
}Pessoa;

void imprimePessoa(Pessoa p){
    printf("%.2f", p.peso);
}

int main(void){
    Pessoa pessoas[20], p1;
    pessoas[5].peso = 50;
    pessoas[5].idade = 15;
    pessoas[5].altura = 1.65;
    p1 = pessoas[5];
	p1.idade++;
	
	if(p1.idade > 18){
		p1.peso = p1.peso + 5;
	}
	
	imprimePessoa(p1);
	return 0;
}