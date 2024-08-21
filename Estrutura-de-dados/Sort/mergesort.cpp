#include <iostream>
#define TAM 10
using namespace std;
int vetor[TAM];


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

int main (){
    vetor[1] = 5;
    vetor[2] = 3;
    vetor[3] =  7;
    vetor[4] =  9;
    vetor[0] =  1;
     vetor[5] =  6;
    vetor[6] =    8;
    vetor[7] =   4;
    vetor [8] = 2;
    vetor [9] = 12;
    MERGESORT (vetor, 0, TAM - 1);
    for (int i = 0; i  < TAM; i++) {
        cout << vetor[i] << " ";
    }
    return 0;
}