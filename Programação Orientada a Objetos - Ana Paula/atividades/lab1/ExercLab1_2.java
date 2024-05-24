import java.util.Scanner;

public class ExercLab1_2 {

    static class Curso {
        String nome;
        String area;
        String turno;
        String instituicao;
    }

	public static void main(String args[]) {
        
        Scanner sc = new Scanner(System.in);

        Curso curso1 = new Curso();
        Curso curso2 = new Curso();
        Curso curso3 = new Curso();
        Curso curso4 = new Curso();

        System.out.println("Digite o nome do curso 1: ");
        curso1.nome = sc.nextLine();
        System.out.println("Digite a área do curso 1: ");
        curso1.area = sc.nextLine();
        System.out.println("Digite o turno do curso 1: ");
        curso1.turno = sc.nextLine();
        System.out.println("Digite a instituição do curso 1: ");
        curso1.instituicao = sc.nextLine();
        System.out.println();

        System.out.println("Digite o nome do curso 2: ");
        curso2.nome = sc.nextLine();
        System.out.println("Digite a área do curso 2: ");
        curso2.area = sc.nextLine();
        System.out.println("Digite o turno do curso 2: ");
        curso2.turno = sc.nextLine();
        System.out.println("Digite a instituição do curso 2: ");
        curso2.instituicao = sc.nextLine();
        System.out.println();

        System.out.println("Digite o nome do curso 3: ");
        curso3.nome = sc.nextLine();
        System.out.println("Digite a área do curso 3: ");
        curso3.area = sc.nextLine();
        System.out.println("Digite o turno do curso 3: ");
        curso3.turno = sc.nextLine();
        System.out.println("Digite a instituição do curso 3: ");
        curso3.instituicao = sc.nextLine();
        System.out.println();

        System.out.println("Digite o nome do curso 4: ");   
        curso4.nome = sc.nextLine();
        System.out.println("Digite a área do curso 4: ");
        curso4.area = sc.nextLine();
        System.out.println("Digite o turno do curso 4: ");
        curso4.turno = sc.nextLine();
        System.out.println("Digite a instituição do curso 4: ");
        curso4.instituicao = sc.nextLine();
        System.out.println();

        System.out.println("Curso 1: ");
        System.out.println("Nome: " + curso1.nome);
        System.out.println("Área: " + curso1.area);
        System.out.println("Turno: " + curso1.turno);
        System.out.println("Instituição: " + curso1.instituicao + "\n");

        System.out.println("Curso 2: ");
        System.out.println("Nome: " + curso2.nome);
        System.out.println("Área: " + curso2.area);
        System.out.println("Turno: " + curso2.turno);
        System.out.println("Instituição: " + curso2.instituicao + "\n");

        System.out.println("Curso 3: ");
        System.out.println("Nome: " + curso3.nome);
        System.out.println("Área: " + curso3.area);
        System.out.println("Turno: " + curso3.turno);
        System.out.println("Instituição: " + curso3.instituicao + "\n");

        System.out.println("Curso 4: ");
        System.out.println("Nome: " + curso4.nome);
        System.out.println("Área: " + curso4.area);
        System.out.println("Turno: " + curso4.turno);
        System.out.println("Instituição: " + curso4.instituicao + "\n");

        sc.close();

	}
}