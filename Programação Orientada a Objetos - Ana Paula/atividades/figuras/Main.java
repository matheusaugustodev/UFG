package figuras;

import java.util.ArrayList;

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