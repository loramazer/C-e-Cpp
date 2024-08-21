#include <iostream>
#define TAM 10
using namespace std;
int vetor[TAM];

void INSERTION_SORT (){
    for (int k = 1; k < TAM - 1; k++){ //percorre vetor a partir de 1 pq analisa anteriores
        int valor = vetor [k];
        int i = k - 1; //salva o indice do elemento anterior
        while (valor < vetor [i] && i >= 0){ //vai comparando o atual com os anteriores
           vetor [i + 1] =  vetor [i]; // caso entre no while valor anterior é menor que o atual
           i--;
        }
        vetor [i + 1] = valor;  //coloca o valor na posição certa
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
    INSERTION_SORT ();
    for (int i = 0; i  < TAM; i++) {
        cout << vetor[i] << " ";
    }
    return 0;
}