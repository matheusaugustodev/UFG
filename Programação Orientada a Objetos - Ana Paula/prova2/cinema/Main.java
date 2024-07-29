package funcionarios;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Funcionario> funcionarios = new ArrayList<>();
        double totalImpostoMasculino = 0;
        double totalImpostoFeminino = 0;

        try (BufferedReader br = new BufferedReader(new FileReader("funcionarios.txt"))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                String[] campos = linha.split("#");
                Funcionario func = new Funcionario(campos[0], campos[1].charAt(0), Double.parseDouble(campos[2]), Integer.parseInt(campos[3]));
                funcionarios.add(func);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (Funcionario func : funcionarios) {
            System.out.println(func.mostraFuncionario());
            if (func.sexo == 'M') {
                totalImpostoMasculino += func.impostoRenda();
            } else {
                totalImpostoFeminino += func.impostoRenda();
            }
        }

        double totalImposto = totalImpostoMasculino + totalImpostoFeminino;

        System.out.println("Total de imposto de renda (Masculino): " + totalImpostoMasculino);
        System.out.println("Total de imposto de renda (Feminino): " + totalImpostoFeminino);
        System.out.println("Total de imposto de renda (Todos): " + totalImposto);
    }
}