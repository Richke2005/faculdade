package classes;

public abstract class Pessoa{
    protected String cpf;
    protected String rg;

    Pessoa(){
        this.cpf = null;
        this.rg = null;
    }

    public Pessoa(String cpf, String rg){
        this.cpf = cpf;
        this.rg = rg;
    }

    public String getCpf(){
        return this.cpf;
    }

    public void setCpf(String cpf){
        this.cpf = cpf;
    }

    public String getRg(){
        return this.rg;
    }

    public void setRg(String rg){
        this.rg = rg;
    }
    
    public abstract void imprimePessoa();
}

