#include <iostream>

using namespace std;
const int TAM = 5;
int vetor[TAM];

int main () {
    int maior;
    cout << "Insira os valores do vetor: \n";
    for (int i=0;i<TAM;i++) 
        cin >> vetor[i];
    for (int i=0; i<TAM; i++) {
        if (i==0) maior = vetor[i];
        else if(vetor[i] > maior) maior = vetor[i];
    }
    cout << "O maior valor do vetor eh: " << maior << endl;
}