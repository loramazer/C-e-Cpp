void SELECTION_SORT (int* selectionVetor){
    int aux;
    int current;
        for (int i = 0; i < (TAM - 1); i++){
        current = i;
        for (int j = (i+1); j < (TAM) ;j ++ ){
            if (selectionVetor[current] > selectionVetor[j]){
                current = j;
            }
            
    }
    //if (vetor[i] !=  vetor[current]){
        aux = selectionVetor[i];
        selectionVetor[i] = selectionVetor[current];
        selectionVetor[current] = aux;
    //}
    }
    // for (int i = 0; i < TAM ; i++){
    //     cout << selectionVetor[i] << " ";
    // }
}