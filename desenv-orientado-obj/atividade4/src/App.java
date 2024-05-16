import classes.Aluno;


public class App{
    public static void main(String[] args){
        Aluno p1 = new Aluno(
        "47708523800",
        "303635478-34",
        1,
        5,
        5,
        1
        );

        p1.imprimePessoa();
        p1.imprimeFaltas();
        p1.resultado();
    }
}