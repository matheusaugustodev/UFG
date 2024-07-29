package funcionarios;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.List;
public class LerObjetos {
    public static void main(String[] args) {
        List<Funcionario> funcionarios = new ArrayList<>();

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("funcionarios.ser"))) {
            funcionarios = (List<Funcionario>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        double totalImpostoMasculino = 0;
        double totalImpostoFeminino = 0;

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