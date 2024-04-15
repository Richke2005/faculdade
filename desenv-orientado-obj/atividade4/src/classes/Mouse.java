package classes;

public class Mouse{
    private int numSerie;
    private String fabricante;
    private String cor;
    
    public Mouse(int numSerie, String fabricante, String cor){
        this.numSerie = numSerie;
        this.fabricante = fabricante;
        this.cor = cor;
    }
    
    Mouse(){
        this.numSerie = 0;
        this.fabricante = null;
        this.cor = null;
    }
    
    public int getNumSerie(){
        return numSerie;
    }
    
    public void setNumSerie(int numSerie){
        this.numSerie = numSerie;
    }

    public String getFabricante(){
        return fabricante;
    }
    
    public void setFabricante(String fabricante){
        this.fabricante = fabricante;
    }

    public String getCor(){
        return cor;
    }

    public void setCor(String cor){
        this.cor = cor;
    }

    public void imprimeMouse(){
        System.out.println(numSerie);
        System.out.println(fabricante);
        System.out.println(cor);
    }
}
