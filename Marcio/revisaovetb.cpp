#include <iostream>

using namespace std;
const int TAM = 5;
int vetor[TAM];

int main (){
    cout << "Insira os valores do vetor: \n";
    for(int i=0;i<TAM;i++)
        cin >> vetor[i];
    for (int i = TAM-1; i>=0; i--)
        cout << vetor[i] ;
    return 0;
}