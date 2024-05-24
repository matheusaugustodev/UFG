import java.util.Scanner;

public class ExercLab1_3 {
    
    static class Curso {
        String nome;
        String area;
        String turno;
        String instituicao;
    }

	public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Digite a quantidade de cursos: ");
        int qtdCursos = sc.nextInt();
        sc.nextLine();

        Curso[] cursos = new Curso[qtdCursos];

        for (int i = 0; i < qtdCursos; i++) {
            cursos[i] = new Curso();
            System.out.println("Digite o nome do curso " + (i + 1) + ": ");
            cursos[i].nome = sc.nextLine();
            System.out.println("Digite a área do curso " + (i + 1) + ": ");
            cursos[i].area = sc.nextLine();
            System.out.println("Digite o turno do curso " + (i + 1) + ": ");
            cursos[i].turno = sc.nextLine();
            System.out.println("Digite a instituição do curso " + (i + 1) + ": ");
            cursos[i].instituicao = sc.nextLine();
            System.out.println();
        }

        for (int i = 0; i < qtdCursos; i++) {
            System.out.println("Curso " + (i + 1) + ": ");
            System.out.println("Nome: " + cursos[i].nome);
            System.out.println("Área: " + cursos[i].area);
            System.out.println("Turno: " + cursos[i].turno);
            System.out.println("Instituição: " + cursos[i].instituicao);
            System.out.println();
        }

        sc.close();
	}
}