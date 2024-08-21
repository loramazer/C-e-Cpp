#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#define TAM 1000

using namespace std;

int vetor[TAM];

void copiaVetor(int* novoVetor){
    for (int i = 0; i < TAM; i++){
        novoVetor[i] = vetor[i];
    }
}

void SHELLSORT (int* vetor){
    int aux;
    for (int distancia = TAM / 2; distancia > 0; distancia /= 2){
        for(int i = distancia; i < TAM; i++){
            aux = vetor [i];
            int comparar;
            for (comparar = i; comparar >= distancia && vetor [comparar - distancia] > aux;
            comparar -= distancia){
                vetor [comparar] = vetor [comparar - distancia];
            }
            vetor [comparar] = aux;
        }
    }
}

int PARTITION (int* vetor, int inicio, int final){
    int aux;
    int pivo = vetor [inicio]; //define o primeiro elemento como pivo
    int i = inicio - 1; 
    int j = final + 1;

    while (true){ //ocorre ate que i e j se encontrem
        do{ j--; } //se move pra esquerda
        while (vetor[j] > pivo); // ate encontrar elemento <= ao pivo
        do {i++;} //se move pra direita
        while (vetor[i] < pivo); //ate encontrar elemento >= ao pivo
        if (i < j){
            aux=vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;
        } else return j;
    }
}

void QUICKSORT (int* vetor, int inicio, int final){
    if (inicio < final){ //se inicio for maior ou igual a final ja esta ordenado
        int q = PARTITION (vetor , inicio, final); //particiona o subvetor e retorna o pivo no final
        QUICKSORT (vetor, inicio, q); //ordena o subvetor esquerdo (elementos menores que o pivo)
        QUICKSORT (vetor, q + 1, final);//ordena o subvetor direito(elementos maiores que o pixo)
    }
}

void merge (int vetor [], int inicio, int meio, int fim){
    int aux1 = inicio, aux2 = meio + 1, comAux = 0, vetAux[fim-inicio+1];
    while (aux1<= meio && aux2 <= fim) {
        if(vetor[aux1] <= vetor[aux2]){ //compara os elementos dos dois subvetores
            vetAux[comAux] = vetor [aux1]; //copia o menor elemento para o vet aux
            aux1++;
        } else {
            vetAux[comAux] = vetor[aux2];
            aux2++;
        }
        comAux++ ;
    }
    while(aux1 <= meio) { //garante que todos os restantes foram para vetaux
        vetAux[comAux] = vetor[aux1];
        comAux++;
        aux1++;
    }
    while (aux2<=fim){ //garante que todos os restantes foram para vetaux
        vetAux[comAux] = vetor [aux2];
        comAux ++;
        aux2++;
    }
    for (comAux = 0; comAux <= fim - inicio; comAux++){
        vetor[inicio + comAux] = vetAux[comAux]; //copia para o vet original
    }
}

void MERGESORT (int* vetor, int inicio, int fim){
    int mid;
    if (inicio < fim){ //garante que tem mais de um elemento no vetor
        mid = (fim + inicio)/2; //calcura o indice do meio
        MERGESORT(vetor, inicio, mid); //ordena a primeira metade
        MERGESORT(vetor, mid+1, fim); //ordena a segunda metade
        merge (vetor, inicio, mid, fim); //mescla elas 
        
    }
}

void INSERTION_SORT (int* insertionVetor){
    copiaVetor(insertionVetor);
    for (int k = 1; k < TAM - 1; k++){ //percorre vetor a partir de 1 pq analisa anteriores
        int valor = insertionVetor [k];
        int i = k - 1; //salva o indice do elemento anterior
        while (valor < insertionVetor [i] && i >= 0){ //vai comparando o atual com os anteriores
           insertionVetor [i + 1] =  insertionVetor [i]; // caso entre no while valor anterior é menor que o atual
           i--;
        }
        insertionVetor [i + 1] = valor;  //coloca o valor na posição certa
    }
    // for (int i = 0; i < TAM ; i++){
    //     cout << insertionVetor[i] << " ";
    // }
}

void BUBBLE_SORT(int* bubbleVetor){
     copiaVetor(bubbleVetor);
    for (int indice = 0; indice < TAM; ++indice) {
        for (int i = 0; i < TAM - indice - 1; ++i){
            if (bubbleVetor[i] > bubbleVetor[i + 1]){
                int aux = bubbleVetor[i];
                bubbleVetor[i] = bubbleVetor[i+1];
                bubbleVetor[i+1] = aux;
            }
        }
    }
    // for (int i = 0; i < TAM ; i++){
    //     cout <<bubbleVetor[i] << " ";
    // }

}

void SELECTION_SORT (int* selectionVetor){
   
    int aux;
    int current;
    copiaVetor(selectionVetor);
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

void implementarvVetor (){
    for (int i = 0; i < TAM; i++){
        vetor[i] = rand() % 100;
    }
}

int main () {
    int tempo1, tempo2;
    srand (time(NULL));
    implementarvVetor();
    
    int selectionVetor[TAM];
    copiaVetor(selectionVetor);
    tempo1 = clock();
    SELECTION_SORT(selectionVetor);
    tempo2 = clock() - tempo1;
    cout << "Tempo decorrido para Selection Sort: " << (float) tempo2 / CLOCKS_PER_SEC << " segundos" << endl;
    // for (int i = 0; i < TAM ; i++){
    //     cout << selectionVetor[i] << " ";
    // }
    cout << endl;
    
    int bubbleVetor[TAM];
    copiaVetor(bubbleVetor);
    tempo1 = clock();
    BUBBLE_SORT(bubbleVetor);
    tempo2 = clock() - tempo1;
    cout << "Tempo decorrido para Bubble Sort: " << (float) tempo2 / CLOCKS_PER_SEC << " segundos" << endl;
    // for (int i = 0; i < TAM ; i++){
    //     cout << bubbleVetor[i] << " ";
    // }
    cout << endl;
    
    int insertionVetor[TAM];
    copiaVetor(insertionVetor);
    tempo1 = clock();
    INSERTION_SORT(insertionVetor);
    tempo2 = clock() - tempo1;
    cout << "Tempo decorrido para Insertion Sort: " << (float) tempo2 / CLOCKS_PER_SEC << " segundos" << endl;
    // for (int i = 0; i < TAM ; i++){
    //     cout << insertionVetor[i] << " ";
    // }
    cout << endl;
    
    int mergeVetor[TAM];
    copiaVetor(mergeVetor);
    tempo1 = clock();
    MERGESORT(mergeVetor, 0, TAM-1);
    tempo2 = clock() - tempo1;
    cout << "Tempo decorrido para Merge Sort: " << (float) tempo2 / CLOCKS_PER_SEC << " segundos" << endl;
    // for (int i = 0; i < TAM ; i++){
    //     cout << mergeVetor[i] << " ";
    // }
    cout << endl;

    int quickVetor[TAM];
    copiaVetor(quickVetor);
    tempo1 = clock();
    QUICKSORT(quickVetor, 0, TAM-1);
    tempo2 = clock() - tempo1;
    cout << "Tempo decorrido para Quick Sort: " << (float) tempo2 / CLOCKS_PER_SEC << " segundos" << endl;
    // for (int i = 0; i < TAM ; i++){
    //     cout <<quickVetor[i] << " ";
    // }
    cout << endl;

    int shellVetor[TAM];
    copiaVetor(shellVetor);
    tempo1 = clock();
    QUICKSORT(shellVetor, 0, TAM-1);
    tempo2 = clock() - tempo1;
    cout << "Tempo decorrido para Shell Sort: " << (float) tempo2 / CLOCKS_PER_SEC << " segundos" << endl;
    // for (int i = 0; i < TAM ; i++){
    //     cout <<shellVetor[i] << " ";
    // }
    cout << endl;
    
    return 0;
}