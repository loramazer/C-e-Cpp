#include <iostream>
#define TAM 10
using namespace std;
int vetor[TAM];

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
        int q = PARTITION (vetor, inicio, final); //particiona o subvetor e retorna o pivo no final
        QUICKSORT (vetor, inicio, q); //ordena o subvetor esquerdo (elementos menores que o pivo)
        QUICKSORT (vetor, q + 1, final);//ordena o subvetor direito(elementos maiores que o pixo)
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
    QUICKSORT (vetor, 0, TAM-1);
    for (int i = 0; i  < TAM; i++) {
        cout << vetor[i] << " ";
    }
    return 0;
}