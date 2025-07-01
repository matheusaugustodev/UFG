public class Deposito {
    private int items = 0;
    private final int capacidade = 10;

    public synchronized int retirar() {
        while (items == 0) {
            try {
                System.out.println("Depósito vazio. Consumidor aguardando...");
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return -1;
            }
        }
        items--;
        System.out.println("Caixa retirada: Sobram " + items + " caixas");
        notifyAll();
        return 1;
    }

    public synchronized int colocar() {
        while (items == capacidade) {
            try {
                System.out.println("Depósito cheio. Produtor aguardando...");
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return -1;
            }
        }
        items++;
        System.out.println("Caixa armazenada: Passaram a ser " + items + " caixas");
        notifyAll();
        return 1;
    }

    public static void main(String[] args) {
        Deposito dep = new Deposito();
    
        Produtor p = new Produtor(dep);
        Consumidor c = new Consumidor(dep);
    
        p.start();
        c.start();
    
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    
        p.interrupt();
        c.interrupt();
    
        try {
            p.join();
            c.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    
        System.out.println("Execução encerrada após 10 segundos.");
    }    
}