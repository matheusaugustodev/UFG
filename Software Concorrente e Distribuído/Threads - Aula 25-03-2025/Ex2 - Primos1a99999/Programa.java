import java.util.Scanner;

class EncontrarPrimos extends Thread {
    private int inicio, fim;

    public EncontrarPrimos(int inicio, int fim) {
        this.inicio = inicio;
        this.fim = fim;
    }

    private boolean ehPrimo(int num) {
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public void run() {
        for (int i = inicio; i <= fim; i++) {
            if (ehPrimo(i)) {
                System.out.println("Primo: " + i);
            }
        }
    }
}

public class Programa {
    public static void main(String[] args) throws InterruptedException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite o número de threads: ");
        int numeroThreads = scanner.nextInt();
        scanner.close();

        int recorte = 100000 / numeroThreads; 
        Thread[] threads = new Thread[numeroThreads];

        for (int i = 0; i < numeroThreads; i++) {
            int inicio = i * recorte;
            int fim = inicio + recorte - 1;
            threads[i] = new EncontrarPrimos(inicio, fim);
            threads[i].start();
        }

        // for (int i = 0; i < numeroThreads; i++) {
        //     threads[i].join();
        // }

        System.out.println("Finalizado!");
    }
}
