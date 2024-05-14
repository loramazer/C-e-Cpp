#include <iostream>
#define TAM 10
using namespace std;
int vetor[TAM];

void SELECTION_SORT (){
    int aux;
    int current;
    for (int i = 0; i < (TAM - 1); i++){
        current = i;
        for (int j = (i+1); j < (TAM) ;j ++ ){
            if (vetor[current] > vetor[j]){
                current = j;
            }
            
    }
    if (vetor[i] !=  vetor[current]){
        aux = vetor[i];
        vetor[i] = vetor[current];
        vetor[current] = aux;
    }
    }
}

int main () {
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
    SELECTION_SORT();
    for (int i = 0; i  < TAM; i++) {
        cout << vetor[i];
    }
}