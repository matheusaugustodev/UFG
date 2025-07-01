import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ExContaBancaria {

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
        List<Thread> threads = new ArrayList<>();

        for (int i = 0; i < 20; i++) {
            Thread t = new Thread(new CaixaBancario(conta));
            threads.add(t);
            t.start();
        }

        for (Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Saldo final: R$" + conta.getSaldo());
    }
}