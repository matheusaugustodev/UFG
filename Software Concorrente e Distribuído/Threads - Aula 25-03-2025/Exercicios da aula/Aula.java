import java.util.List;

class Aula extends Thread {

    private List<Integer> listaCompartilhada;
    private int numeroInicial;
    private int quantidade;

    public Aula(List<Integer> lista, int numeroInicial, int quantidade) {
        this.listaCompartilhada = lista;
        this.numeroInicial = numeroInicial;
        this.quantidade = quantidade;
    }

    @Override
    public void run() {
        // synchronized (listaCompartilhada) {
            for (int i = numeroInicial; i < (numeroInicial + quantidade); i++) {
                listaCompartilhada.add(i);
            }
        // }
    }
}