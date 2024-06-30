package figuras;

public class Retangulo extends Quadrado {
    private double altura;

    public Retangulo() {
        super();
        this.altura = 0.0;
    }

    public Retangulo(double lado, double altura) {
        super(lado);
        this.altura = altura;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return getLado() * altura;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * (getLado() + altura);
    }

    @Override
    public String desenhar() {
        return "Desenhando a Figura Retângulo";
    }
}