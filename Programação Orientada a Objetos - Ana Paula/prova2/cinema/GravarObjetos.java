package funcionarios;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class GravarObjetos {
    public static void main(String[] args) {
        List<Funcionario> funcionarios = new ArrayList<>();
        
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

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("funcionarios.ser"))) {
            oos.writeObject(funcionarios);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}