import java.util.ArrayList;
import java.util.List;

public class Repositorio {

    private static final String PREFIXO_URL_IMAGENS = "http://www.nossoalbum.com.br/imagens/";

    private List<Colecionavel> todasAsColecionavel;

    public Repositorio(String sufixoUrlImagens, int quantColecionavel) {
        todasAsColecionavel = new ArrayList<>(quantColecionavel);
        for (int i = 1; i <= quantColecionavel; i++) {
            Colecionavel fig = new Figurinha(i, PREFIXO_URL_IMAGENS + sufixoUrlImagens);
            todasAsColecionavel.add(fig);
        }
    }

    public int getTotalColecionavel() {
        return this.todasAsColecionavel.size();
    }

    public List<Colecionavel> getTodasAsColecionavel() {
        return todasAsColecionavel;
    }
}