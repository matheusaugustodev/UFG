import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Publicacao {
    private Date data;
    private String texto;
    private List<Reacao> reacoes;

    public Publicacao(Date data, String texto) {
        this.data = data;
        this.texto = texto;
        this.reacoes = new ArrayList<>();
    }

    public Date getData() {
        return data;
    }

    public String getTexto() {
        return texto;
    }

    public List<Reacao> getReacoes() {
        return reacoes;
    }

    public void adicionarReacao(Reacao reacao) {
        this.reacoes.add(reacao);
    }
}