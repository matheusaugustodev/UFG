import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class CorridaDeLebres {

    private static final int DISTANCIA_TOTAL = 20;
    private static final int NUM_LEBRES = 5;
    private static final List<String> colocacoes = Collections.synchronizedList(new ArrayList<>());
    private static final Random rand = new Random();

    static class Lebre extends Thread {
        private String nome;
        private int distanciaPercorrida = 0;
        private int pulos = 0;

        public Lebre(String nome) {
            this.nome = nome;
        }

        @Override
        public void run() {
            while (distanciaPercorrida < DISTANCIA_TOTAL) {
                int salto = rand.nextInt(3) + 1;
                distanciaPercorrida += salto;
                pulos++;

                if (distanciaPercorrida > DISTANCIA_TOTAL)
                    distanciaPercorrida = DISTANCIA_TOTAL;

                if (salto == 1) {
                    System.out.println(nome + " pulou " + salto + " metro (Total: " + distanciaPercorrida + ")");
                } else {
                    System.out.println(nome + " pulou " + salto + " metros (Total: " + distanciaPercorrida + ")");
                }

                Thread.yield();
            }

            colocacoes.add(nome + " (" + pulos + " pulos)");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Lebre[] lebres = new Lebre[NUM_LEBRES];

        for (int i = 0; i < NUM_LEBRES; i++) {
            lebres[i] = new Lebre("Lebre " + (i + 1));
            lebres[i].start();
        }

        for (Lebre lebre : lebres) {
            lebre.join();
        }

        System.out.println("\n Corrida finalizada!");
        System.out.println("Vencedora: " + colocacoes.get(0));

        System.out.println("\n Colocações:");
        for (int i = 0; i < colocacoes.size(); i++) {
            System.out.println((i + 1) + "º lugar - " + colocacoes.get(i));
        }
    }
}