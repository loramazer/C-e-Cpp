#include <iostream>
#define TAM 10
using namespace std;
int vetor[TAM];

void SHELLSORT (){
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
    vetor [9] = 10;
    SHELLSORT ();
    for (int i = 0; i  < TAM; i++) {
        cout << vetor[i] << " ";
    }
    return 0;
}