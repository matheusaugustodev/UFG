package figuras;

public class Circulo extends Figura implements Desenho {
    private double raio;

    public Circulo() {
        this.raio = 0.0;
    }

    public Circulo(double raio) {
        this.raio = raio;
    }

    public double getRaio() {
        return raio;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * raio * raio;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * Math.PI * raio;
    }

    @Override
    public String desenhar() {
        return "Desenhando a Figura Círculo";
    }
}