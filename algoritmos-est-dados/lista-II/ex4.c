#include <stdio.h>

float mediaTurma(int numAlunos);
float mediaEscola(int qtdTurmas);
int main(void){
    int qtdTurmas;
    printf("Digite a quantidades de turmas presentes na escola\n");
    scanf("%d", &qtdTurmas);
    printf("A media geral da escola e igual a %.2f", mediaEscola(qtdTurmas));
    return 0;
}

float mediaTurma(int numAlunos){
    int soma = 0, nota;

    for(int i=0; i< numAlunos; i++){
        printf("Digite a nota do aluno %d:\n", i + 1);
        scanf("%d", &nota);
        soma += nota;
    }
    printf("A media desta turma e igual a\n%.2f\n", (float) soma / numAlunos);
    return soma / numAlunos;
}

float mediaEscola(int qtdTurmas){
    float somaMediaTurmas;
    int numAlunos;

    for(int i=0; i<qtdTurmas; i++){
        printf("Qual a quantidade de alunos da turma %d:\n", i + 1);
        scanf("%d", &numAlunos);
        somaMediaTurmas += mediaTurma(numAlunos);
    }

    return somaMediaTurmas / qtdTurmas;
}
