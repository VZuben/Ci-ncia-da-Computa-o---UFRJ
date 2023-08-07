import java.util.ArrayList;
import java.util.List;

public class Pacotinho {
    Repositorio repo;
    int[] posicoesDesejadas = null;
    int quantColecionavel = 3;

    public Pacotinho(Repositorio repo, int[] posicoesDesejadas) {
        this.repo = repo;
        this.posicoesDesejadas = posicoesDesejadas;
    }

    /**
     * Produz um pacotinho com quantColecionavel sorteadas aleatoriamente
     * dentre aqueles presentes no repositório informado.
     *
     * @param repo o repositório desejado
     * @param quantColecionavel a quantidade de Colecionavel a constar no pacotinho
     */
    public Pacotinho(Repositorio repo, int quantColecionavel) {
        this.repo = repo;
        this.quantColecionavel = quantColecionavel;
    }

    public Colecionavel[] getColecionavel() {
        List <Colecionavel> todaAsColecionavel = repo.getTodasAsColecionavel();
        List <Colecionavel> colecionavelDoPacotinho = new ArrayList<Colecionavel>();
        if(posicoesDesejadas == null) {
            for (int i = 0; i < quantColecionavel; i++) {
                int colecionavelAleatoria = (int) (Math.random() * 200);
                colecionavelDoPacotinho.add(todaAsColecionavel.get(colecionavelAleatoria));
            }
        } else {
            if(posicoesDesejadas.length != 3){
                return new Colecionavel[0];
            }
            for (int i = 0; i < quantColecionavel; i++) {
                int colecionavelAleatoria = posicoesDesejadas[i]-1;
                colecionavelDoPacotinho.add(todaAsColecionavel.get(colecionavelAleatoria));
            }
        }
        return (Colecionavel[]) colecionavelDoPacotinho.toArray(new Colecionavel[quantColecionavel]);
    }

}