#include <iostream>

using namespace std;
const int TAM = 5;
int vetor [TAM];

int main() {
    int menor;
    cout << "Insira os valores do vetor: \n";
    for (int i=0;i<TAM;i++) 
        cin >> vetor[i];
    for (int i=0; i<TAM; i++){
        if (i==0) menor = vetor [i];
        else  if (menor>vetor[i]) menor = vetor[i];
        }
    cout << "O menor valor eh: " << menor << endl;
    
}