import java.util.ArrayList;
import java.util.List;

public class Programa {
    public static void main(String[] args) throws InterruptedException {
        List<Integer> lista = new ArrayList<>();
        
        // Criando e iniciando três threads
        Thread t1 = new Aula(lista, 1, 100);
        Thread t2 = new Aula(lista, 101, 100);
        Thread t3 = new Aula(lista, 201, 100);

        t1.start();
        t2.start();
        t3.start();

        // t1.join();
        // t2.join();
        // t3.join();

        // Thread.sleep(2000);

        System.out.println("Quantidade de elementos na lista: " + lista.size());
        for (int i = 0; i < lista.size(); i++) {
            System.out.println(lista.get(i));
        }
    }
}