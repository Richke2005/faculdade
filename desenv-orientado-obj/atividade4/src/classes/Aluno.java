package classes;

public class Aluno extends Pessoa {
    private static int limiteFaltas = 10;
    private int codMatricula;
    private int p1;
    private int p2;
    private int faltas;
    private float media;

    Aluno(){
        super();
        this.codMatricula = 0;
        this.p1 = 0;
        this.p2 = 0;
        this.faltas = 0;
    }

    public Aluno(String cpf, String rg, int codMatricula, int p1, int p2, int faltas) {
        super(cpf, rg);
        this.codMatricula = codMatricula;
        this.p1 = p1;
        this.p2 = p2;
        this.faltas = faltas;
        this.media = (p1 + p2) / 2;
    }

    public int getCodMatricula() {
        return codMatricula;
    }

    public int getP1() {
        return p1;
    }

    public void setP1(int p1) {
        this.p1 = p1;
    }

    public int getP2() {
        return p2;
    }

    public void setP2(int p2) {
        this.p2 = p2;
    }

    public static int getLimiteFaltas() {
        return limiteFaltas;
    }

    public void setCodMatricula(int codMatricula) {
        this.codMatricula = codMatricula;
    }

    public boolean isAproved(){
        boolean status = false;
        if(media >= 7.0 && faltas <= limiteFaltas){
            status = true;
        }
        return status;
    }

    public void imprimeFaltas(){
        System.out.println("Faltas: " + faltas);
    }

    public void resultado(){
        if(!isAproved()){
            if(media > 3.0)
                System.out.println("Reprovado");
            else
                System.out.println("Realizar Exame " + media);
        }else{
            System.out.println("Aprovado");
        }
    }

    @Override
    public void imprimePessoa() {
        System.out.println("-------------ALUNO-------------");
        System.out.println("Cpf: " + cpf);
        System.out.println("Rg: " + rg);
        System.out.println("Código de matriculas: " + codMatricula);
        System.out.println("Nota da P1: " + p1);
        System.out.println("Nota da P2: " + p2);
        System.out.println("Média: (" + p1 + " + " + p2 + ") / 2 = " + media);
    }

}
