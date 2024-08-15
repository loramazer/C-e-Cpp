#include <iostream>

using namespace std;
const int TAM = 5;
int vetor[TAM];
int main (){
    cout<<"Digite os valores: \n";
    for(int i=0 ;i<TAM; i++){
        cin>>vetor[i]; 
    }
    for (int i=0; i< TAM; i++)   
        cout<<vetor[i] ;
    return 0;
}