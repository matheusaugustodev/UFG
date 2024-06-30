public class ContaCorrente extends Conta {
    ContaCorrente(int numero, Cliente dono) {
        super(numero, dono);
    }

    @Override
    public void sacar(double valor) {
        super.sacar(valor + 0.05);
    }

    @Override
    public void depositar(double valor) {
        super.depositar(valor - 0.05);
    }

    @Override
    public void transferir(double valor, Conta destino) {
        this.sacar(valor);
        destino.depositar(valor - 0.05);
    }
}