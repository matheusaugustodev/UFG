import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Comentario extends Reacao {
    private String texto;
    private List<Comentario> respostas;

    public Comentario(Date data, Usuario usuario, String texto) {
        super(data, usuario);
        this.texto = texto;
        this.respostas = new ArrayList<>();
    }

    public String getTexto() {
        return texto;
    }

    public List<Comentario> getRespostas() {
        return respostas;
    }

    public void adicionarResposta(Comentario comentario) {
        this.respostas.add(comentario);
    }
}