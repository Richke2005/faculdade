import classes.Produto;

public class App{
    public static void main(String[] args){
        Produto p1 = new Produto("234", "Sabonete liquido", 300);
        Produto p2 = new Produto("256", "Bolacha recheada", 10);
        Produto p3 = new Produto("787", "Shampoo", 400);

        p1.adicionarEstoque(100);
        p2.retirarEstoque(10);
        p3.retirarEstoque(100);

        p1.statusEstoque();
        p2.statusEstoque();
        p3.statusEstoque();
        
        p1.imprmirProduto();
        p2.imprmirProduto();
        p3.imprmirProduto();
    }
}