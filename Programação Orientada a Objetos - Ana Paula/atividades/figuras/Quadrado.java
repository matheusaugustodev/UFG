package figuras;

public class Quadrado extends Figura implements Desenho {
    private double lado;

    public Quadrado() {
        this.lado = 0.0;
    }

    public Quadrado(double lado) {
        this.lado = lado;
    }

    public double getLado() {
        return lado;
    }

    public void setLado(double lado) {
        this.lado = lado;
    }

    @Override
    public double calcularArea() {
        return lado * lado;
    }

    @Override
    public double calcularPerimetro() {
        return 4 * lado;
    }

    @Override
    public String desenhar() {
        return "Desenhando a Figura Quadrado";
    }
}