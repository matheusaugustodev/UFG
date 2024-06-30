public class TestaConta {
    public static void main(String[] args) {
        Cliente c1 = new Cliente("João", "1234-5678");
        Cliente c2 = new Cliente("Maria", "8765-4321");
        Cliente c3 = new Cliente("José", "4321-8765");

        ContaCorrente cc1 = new ContaCorrente(1, c1);
        ContaPoupanca cp1 = new ContaPoupanca(2, c2);
        ContaSalario cs1 = new ContaSalario(3, c3);

        cc1.depositar(100);
        cp1.depositar(200);
        cs1.depositar(300);

        cc1.sacar(50);
        cp1.sacar(100);
        cs1.sacar(150);

        cp1.atualizaSaldo(10);

        cc1.transferir(10, cp1);
        cp1.transferir(20, cs1);
        cs1.transferir(30, cc1);

        System.out.println(cc1);
        System.out.println(cp1);
        System.out.println(cs1);
    }
}