import java.util.ArrayList;
import java.util.List;

public class Pacotinho {
    Repositorio repo;
    int[] posicoesDesejadas = null;
    int quantFigurinhas = 3;

    public Pacotinho(Repositorio repo, int[] posicoesDesejadas) {
        this.repo = repo;
        this.posicoesDesejadas = posicoesDesejadas;
    }

    /**
     * Produz um pacotinho com quantFigurinhas sorteadas aleatoriamente
     * dentre aqueles presentes no repositório informado.
     *
     * @param repo o repositório desejado
     * @param quantFigurinhas a quantidade de figurinhas a constar no pacotinho
     */
    public Pacotinho(Repositorio repo, int quantFigurinhas) {
        this.repo = repo;
        this.quantFigurinhas = quantFigurinhas;
    }

    public Figurinha[] getFigurinhas() {
        List <Figurinha> todaAsFigurinhas = repo.getTodasAsFigurinhas();
        List <Figurinha> figurinhasDoPacotinho = new ArrayList<Figurinha>();
        if(posicoesDesejadas == null) {
            for (int i = 0; i < quantFigurinhas; i++) {
                int figurinhaAleatoria = (int) (Math.random() * 200);
                figurinhasDoPacotinho.add(todaAsFigurinhas.get(figurinhaAleatoria));
            }
        } else {
            if(posicoesDesejadas.length != 3){
                return new Figurinha[0];
            }
            for (int i = 0; i < quantFigurinhas; i++) {
                int figurinhaAleatoria = posicoesDesejadas[i]-1;
                figurinhasDoPacotinho.add(todaAsFigurinhas.get(figurinhaAleatoria));
            }
        }
        return (Figurinha[]) figurinhasDoPacotinho.toArray(new Figurinha[quantFigurinhas]);
    }

}