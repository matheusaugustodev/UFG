import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ExContaBancariaComExecutors {

    static class ContaBancaria {
        private int numero;
        private double saldo;
        private Lock lock = new ReentrantLock();

        public ContaBancaria(int numero, double saldoInicial) {
            this.numero = numero;
            this.saldo = saldoInicial;
        }

        public void sacar(double valor) {
            lock.lock();
            try {
                saldo -= valor;
            } finally {
                lock.unlock();
            }
        }

        public void depositar(double valor) {
            lock.lock();
            try {
                saldo += valor;
            } finally {
                lock.unlock();
            }
        }

        public double getSaldo() {
            return saldo;
        }
    }

    static class CaixaBancario implements Runnable {
        private ContaBancaria conta;

        public CaixaBancario(ContaBancaria conta) {
            this.conta = conta;
        }

        @Override
        public void run() {
            conta.sacar(500);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            conta.depositar(500);
        }
    }

    public static void main(String[] args) {
        ContaBancaria conta = new ContaBancaria(123, 0);
        ExecutorService executor = Executors.newFixedThreadPool(10);

        for (int i = 0; i < 20; i++) {
            executor.submit(new CaixaBancario(conta));
        }

        executor.shutdown();

        while (!executor.isTerminated()) {
        }

        System.out.println("Saldo final: R$" + conta.getSaldo());
    }
}