void bubble_sort(int vetor[], int tamanho){
    int trocou, i, temp;
    do {
        trocou = 0;
        for (i = 0; i < tamanho - 1; i++){
            if (vetor[i] > vetor[i + 1]){
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                trocou = 1;
            }
        }
        tamanho--;
    } while (trocou == 1);
}