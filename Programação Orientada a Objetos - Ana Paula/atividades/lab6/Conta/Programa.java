import javax.swing.JOptionPane;

public class Programa {
    public static void main(String[] args) {
        Conta[] contas = new Conta[10];
        int contaIndex = 0;

        while (true) {
            String numeroContaStr = JOptionPane.showInputDialog("Digite o número da conta (0 para sair):");
            int numeroConta = Integer.parseInt(numeroContaStr);
            if (numeroConta == 0) break;

            String nomeCliente = JOptionPane.showInputDialog("Digite o nome do cliente:");
            String telefoneCliente = JOptionPane.showInputDialog("Digite o telefone do cliente:");
            Cliente novoCliente = new Cliente(nomeCliente, telefoneCliente);

            String tipoContaStr = JOptionPane.showInputDialog("Digite o tipo de conta (1-Corrente, 2-Conta Salário, 3-Poupança):");
            int tipoConta = Integer.parseInt(tipoContaStr);

            Conta novaConta = null;
            switch (tipoConta) {
                case 1:
                    novaConta = new ContaCorrente(numeroConta, novoCliente);
                    break;
                case 2:
                    novaConta = new ContaSalario(numeroConta, novoCliente);
                    break;
                case 3:
                    novaConta = new ContaPoupanca(numeroConta, novoCliente);
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Tipo de conta inválido.");
                    continue;
            }

            contas[contaIndex++] = novaConta;
        }

		System.out.println("Contas cadastradas:");
		System.out.println(contaIndex);

        for (int i = 0; i < contaIndex; i++) {
            System.out.println(contas[i]);
        }
    }
}