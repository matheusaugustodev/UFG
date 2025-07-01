class ImprimeImpar extends Thread {
    public void run() {
        for (int i = 1; i <= 2000; i += 2) {
            System.out.println("Ímpar: " + i);
        }
    }
}

class ImprimePar extends Thread {
    public void run() {
        for (int i = 2; i <= 2000; i += 2) {
            System.out.println("Par: " + i);
        }
    }
}

public class Programa {
    public static void main(String[] args) {
        Thread t1 = new ImprimeImpar();
        Thread t2 = new ImprimePar();
        t1.start();
        t2.start();
    }
}
