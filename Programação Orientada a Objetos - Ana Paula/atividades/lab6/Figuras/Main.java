import java.util.ArrayList;

abstract class Figura {
    public abstract double calcularArea();
    public abstract double calcularPerimetro();
}

interface Desenho {
    String desenhar();
}

class Quadrado extends Figura implements Desenho {
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

class Triangulo extends Figura implements Desenho {
    private double base;
    private double lado1;
    private double lado2;
    private double altura;

    public Triangulo() {
        this.base = 0.0;
        this.lado1 = 0.0;
        this.lado2 = 0.0;
        this.altura = 0.0;
    }

    public Triangulo(double base, double lado1, double lado2, double altura) {
        this.base = base;
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.altura = altura;
    }

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public double getLado1() {
        return lado1;
    }

    public void setLado1(double lado1) {
        this.lado1 = lado1;
    }

    public double getLado2() {
        return lado2;
    }

    public void setLado2(double lado2) {
        this.lado2 = lado2;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return (base * altura) / 2;
    }

    @Override
    public double calcularPerimetro() {
        return base + lado1 + lado2;
    }

    @Override
    public String desenhar() {
        return "Desenhando a Figura Triângulo";
    }
}

class Circulo extends Figura implements Desenho {
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

class Retangulo extends Quadrado {
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

public class Main {
    public static void main(String[] args) {
        Quadrado quadrado = new Quadrado(4.0);
        Triangulo triangulo = new Triangulo(3.0, 4.0, 5.0, 2.5);
        Circulo circulo = new Circulo(2.5);
        Retangulo retangulo = new Retangulo(4.0, 6.0);

        ArrayList<Figura> figuras = new ArrayList<>();
        figuras.add(quadrado);
        figuras.add(triangulo);
        figuras.add(circulo);
        figuras.add(retangulo);

        for (Figura figura : figuras) {
            System.out.println("Área: " + figura.calcularArea());
            System.out.println("Perímetro: " + figura.calcularPerimetro());
            if (figura instanceof Desenho) {
                System.out.println(((Desenho) figura).desenhar());
            }
            System.out.println();
        }
    }
}