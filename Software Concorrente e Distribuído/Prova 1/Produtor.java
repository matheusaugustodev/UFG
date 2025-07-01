import java.util.Random;

public class Produtor extends Thread {
    private Deposito deposito;
    private Random random = new Random();

    public Produtor(Deposito d) {
        this.deposito = d;
    }

    @Override
    public void run() {
        while (true) {
            int resultado = deposito.colocar();
            if (resultado > 0) {
                try {
                    Thread.sleep(random.nextInt(1000));
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }
            } else if (resultado == -1) {
                 break;
            }
        }
        System.out.println("Produtor terminado.");
    }
}