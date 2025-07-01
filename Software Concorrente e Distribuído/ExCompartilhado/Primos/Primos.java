import java.util.ArrayList;
import java.util.List;

public class Primos {

    public static void main(String[] args) throws InterruptedException {
        long inicioGeral = System.currentTimeMillis();

        int numThreads = 8;

        List<Integer> primos1 = processarIntervalo(1000000, 7000000, numThreads);
        List<Integer> primos2 = processarIntervalo(25000000, 45000000, numThreads);        

        long fimGeral = System.currentTimeMillis();

        double tempoGeral = (fimGeral - inicioGeral) / 1000.0;

        System.out.println("Primos encontrados entre 1.000.000 e 7.000.000: " + primos1);
        System.out.println("Primos encontrados entre 25.000.000 e 45.000.000: " + primos2);   
        System.out.println("Quantidade de primos encontrados entre 1.000.000 e 7.000.000: " + primos1.size());
        System.out.println("Quantidade de primos encontrados entre 25.000.000 e 45.000.000: " + primos2.size());
        System.out.printf("Tempo total de execução: %.2f segundos%n", tempoGeral);
    }

    public static List<Integer> processarIntervalo(int inicio, int fim, int numThreads) throws InterruptedException {
        List<Integer> primos = new ArrayList<>();
        List<Thread> threads = new ArrayList<>();
        int intervalo = (fim - inicio + 1) / numThreads;

        for (int i = 0; i < numThreads; i++) {
            int parteInicio = inicio + i * intervalo;
            int parteFim = (i == numThreads - 1) ? fim : parteInicio + intervalo - 1;

            Thread t = new Thread(new VerificadorDePrimos(parteInicio, parteFim, primos));
            t.start();
            threads.add(t);
        }

        for (Thread t : threads) {
            t.join();
        }

        return primos;
    }

    static class VerificadorDePrimos implements Runnable {
        private int inicio, fim;
        private List<Integer> primosCompartilhados;

        public VerificadorDePrimos(int inicio, int fim, List<Integer> primosCompartilhados) {
            this.inicio = inicio;
            this.fim = fim;
            this.primosCompartilhados = primosCompartilhados;
        }

        @Override
        public void run() {
            List<Integer> locais = new ArrayList<>();
            for (int i = inicio; i <= fim; i++) {
                if (ehPrimo(i)) {
                    locais.add(i);
                }
            }
            synchronized (primosCompartilhados) {
                primosCompartilhados.addAll(locais);
            }
        }

        private boolean ehPrimo(int n) {
            if (n < 2) return false;
            if (n == 2 || n == 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            int raiz = (int) Math.sqrt(n);
            for (int i = 5; i <= raiz; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0) return false;
            }
            return true;
        }
    }
}
