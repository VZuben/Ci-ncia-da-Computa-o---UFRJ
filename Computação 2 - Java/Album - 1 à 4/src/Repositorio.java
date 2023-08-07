import java.util.ArrayList;
import java.util.List;

public class Repositorio {

    private static final String PREFIXO_URL_IMAGENS = "http://www.nossoalbum.com.br/imagens/";

    private List<Colecionavel> todasAsFigurinhas;

    @SuppressWarnings("unchecked")
    public Repositorio(String sufixoUrlImagens, int quantFigurinhas) {
        todasAsFigurinhas = new ArrayList<>(quantFigurinhas);
        for (int i = 1; i <= quantFigurinhas; i++) {
            Figurinha fig = (Figurinha) new Figurinha(i, PREFIXO_URL_IMAGENS + sufixoUrlImagens);
            todasAsFigurinhas.add(fig);
        }
    }

    public int getTotalFigurinhas() {
        return this.todasAsFigurinhas.size();
    }

    public List<Colecionavel> getTodasAsFigurinhas() {
        return todasAsFigurinhas;
    }

}