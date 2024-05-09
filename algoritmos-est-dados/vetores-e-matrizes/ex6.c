// Faça um programa para ler a nota da prova de 15 alunos e armazene num vetor,
// calcule e imprima a média geral.

int main(void){
    float notaAlunos[15], soma = 0.0;
    int i = 0;
    for(i = 0; i < 15; i++){
        printf("Digite a nota dos 15 alunos.\nNota %d\n", i + 1);
        scanf("%f", &notaAlunos[i]);
    }

    for(i = 0; i < 15; i++){
        soma += notaAlunos[i];
    }

    printf("A media da turma e: %.2f", soma / 15);
    return 0;
}