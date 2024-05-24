import java.util.ArrayList;

class Lab_ProgramaTV {

    static class Pessoa {
        String nome;
        String nacionalidade;
        
        public String toString() {
            return nome + " (" + nacionalidade + ")";
        }
        
        Pessoa (String nome, String nacionalidade) {
            this.nome = nome;
            this.nacionalidade = nacionalidade;
        }
    
    }

    static class ProgramaTV { 
        static int proximoCodigo = 1;
        int codigo;
        String nome;
        ArrayList <Pessoa> artistas = new ArrayList <Pessoa>();
        Pessoa diretor;
        String categoria;
        
        ProgramaTV(String nome, String categoria) {
            this.codigo = proximoCodigo++;
            this.nome = nome;
            this.categoria = categoria;
        }
        
        void setDiretor(Pessoa diretor){
            this.diretor = diretor;
        }
        
        void setArtistas(Pessoa artista) {
            artistas.add(artista);
        }
        
        
        public String toString() {
            String programa = codigo + "-" + nome + " (" + categoria + ")\n";
            programa = programa + "Diretor : " + diretor +"\n";
            programa = programa + "Artistas : \n";
            for (int i=0;i<artistas.size();i++) {
                programa = programa + artistas.get(i) + "\n";
            }
            return programa;
        }
    
    }

    static class Serie extends ProgramaTV {
        int temporadas;
        int episodios;
        
        Serie(String nome, String categoria, int temporadas, int episodios) {
            super(nome, categoria);
            this.temporadas = temporadas;
            this.episodios = episodios;
        }

        public String toString() {
            String programa = codigo + "-" + nome + " (" + categoria + ")\n";
            programa = programa + "Diretor : " + diretor +"\n";
            programa = programa + "Artistas : \n";
            for (int i=0;i<artistas.size();i++) {
                programa = programa + artistas.get(i) + "\n";
            }
            programa = programa + "Temporadas : " + temporadas + "\n";
            programa = programa + "Episódios : " + episodios + "\n";
            return programa;
        }
    }

    public static void main(String[] args) {
        ArrayList <ProgramaTV> programas = new ArrayList <ProgramaTV>();

        ProgramaTV p = new ProgramaTV("O outro lado do paraíso","Novela");
        p.diretor = new Pessoa("Diretor 1", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 1", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 2", "Brasileiro"));
        programas.add(p);
        
        p = new ProgramaTV("Orgulho e Paixão","Novela");
        p.diretor = new Pessoa("Diretor 2", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 3", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 4", "Brasileiro"));
        programas.add(p);
        
        p = new ProgramaTV("Marley e eu","Filme");
        p.diretor = new Pessoa("Diretor 3", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 5", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 6", "Brasileiro"));
        programas.add(p);
        
        p = new ProgramaTV("Show Ivete Sangalo","Show");
        p.diretor = new Pessoa("Diretor 4", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 7", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 8", "Brasileiro"));
        programas.add(p);
        
        // Criação de séries
        Serie s = new Serie("Friends", "Série", 10, 236);
        s.diretor = new Pessoa("Diretor 5", "Brasileiro");
        s.setArtistas(new Pessoa("Artista 9", "Brasileiro"));
        s.setArtistas(new Pessoa("Artista 10", "Brasileiro"));
        programas.add(s);
        
        s = new Serie("Breaking Bad", "Série", 5, 62);
        s.diretor = new Pessoa("Diretor 6", "Brasileiro");
        s.setArtistas(new Pessoa("Artista 11", "Brasileiro"));
        s.setArtistas(new Pessoa("Artista 12", "Brasileiro"));
        programas.add(s);

        for (int i=0;i<programas.size();i++) {
            System.out.println(programas.get(i));
        }
    }
}