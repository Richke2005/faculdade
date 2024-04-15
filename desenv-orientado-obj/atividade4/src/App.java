import classes.Teclado;

public class App{
    public static void main(String[] args){
        Teclado t1 = new Teclado(21, "lenovo", "preto");
        t1.setCor("dourado");
        t1.imprimeTeclado();
    }
}