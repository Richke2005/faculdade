package classes;

public class Produto{
    public static int qtdTotalProdutos;
    private static int LIMITE_ESTOQUE = 10;
    private String codProduto;
    private String descricao;
    private int quantidade;

    public Produto(String codProduto, String descricao, int quantidade){
        this.codProduto = codProduto;
        this.descricao = descricao;
        this.quantidade = quantidade;
        qtdTotalProdutos++;
    }

    Produto(){
        this.codProduto = null;
        this.descricao = null;
        this.quantidade = 0;
        qtdTotalProdutos++;
    }

    public String getCodProduto(){
        return codProduto;
    }
    
    public void setCodProduto(String codProduto){
        this.codProduto = codProduto;
    }

    public String getDescricao(){
        return descricao;
    }

    public void setDescricao(String descricao){
        this.descricao = descricao;
    }

    public int getQuantidade(){
        return quantidade;
    }

    public void setQuantidade(int quantidade){
        this.quantidade = quantidade;
    }

    public void retirarEstoque(int qtdRetirada){
        if(quantidade >= qtdRetirada){
            quantidade -= qtdRetirada;
        }else{
            System.out.println("Não é possivel retirar, estoque menor que o solicitado: " + quantidade);
        }
        System.out.println("Retirado " + qtdRetirada + " quantidade total de " + descricao + " no estoque é de: " + quantidade);
    }

    public void adicionarEstoque(int qtdAdicionada){
        quantidade += qtdAdicionada;
        System.out.println("Adicionado " + qtdAdicionada +" quantidade total de " + descricao + " no estoque é de: " + quantidade);
    }

    public void statusEstoque(){
        if(quantidade > LIMITE_ESTOQUE){
            System.out.println("Estoque " + descricao + ", regular " + quantidade);
        }
        if(quantidade == 0){
            System.out.println("Estoque " + descricao + ", nulo " + quantidade);
        }else if(quantidade <= LIMITE_ESTOQUE){
            System.out.println("Estoque " + descricao + ", restrito " + quantidade);
        }
    }

    public void alterarLimiteEstoque(int novoLimite){
        LIMITE_ESTOQUE = novoLimite;
        System.out.println("Novo limite de: " + LIMITE_ESTOQUE + " adicionado");
    }

    public void imprmirProduto(){
        System.out.println("codigo: " + codProduto);
        System.out.println("descricao: " + descricao);
        System.out.println("quantidade: " + quantidade);
    }
}