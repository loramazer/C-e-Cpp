#include <iostream>
#define TAM 10
using namespace std;
int vetor[TAM];

void BUBBLE_SORT(){
    for (int indice = 0; indice < TAM; ++indice) {
        for (int i = 0; i < TAM - indice - 1; ++i){
            if (vetor[i] > vetor[i + 1]){
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
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
    vetor [9] = 12;
    BUBBLE_SORT ();
    for (int i = 0; i  < TAM; i++) {
        cout << vetor[i] << " ";
    }
    return 0;
}