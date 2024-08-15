#include <iostream>
#include <string.h>
using namespace std;

const int TAM = 5;
int vetor[TAM+1] = {2, 5, 6, 20, 30};

void buscaSequencial (int chave){
    int i = 0;

    while (i < TAM && vetor[i] != chave){
        i++;
    }
    if (i != TAM)
        cout << "Encontrei na posicao " << i << endl;
    else cout << "Nao encontrei " << chave << endl;
}

void buscaSequencialComSentinela (int chave){
    int i = 0;
    vetor[TAM] = chave;
    while(vetor[i]!=chave){
        i++;
    }
    if(i!=TAM)
        cout << "Encontrei na posicao " << i << endl;
    else cout << "Nao encontrei " << chave << endl;
}

void buscaTransposicao (int chave){
    int i = 0;
    int aux = 0;
    while (i < TAM && vetor[i] != chave){
        i++;
    }
    if (i!=TAM){
        cout << "Encontrei na posicao " << i << endl;
        if(i!=0){
            aux = vetor[i];
            vetor[i] = vetor[i-1];
            vetor[i-1] = aux;
        }
    } else cout << "Nao encontrei " << chave<< endl;
}

void buscaMoverPraFrente(int chave){
    int i = 0;
    while (i < TAM && vetor[i] != chave){
        i++;
    }
    if (i!= TAM){
        cout << "Encontrei na posicao " << i << endl;
        for (int j = i; j < 0; j--){
            vetor[j+1] = vetor[j];
        }
        vetor[0] = chave;
    }else cout << "Nao encontrei "<< chave << endl;
}

void buscaBinaria(int chave){
    int inicio = 0;
    int fim = TAM-1;
    int meio = 0;
    while (meio<=fim && vetor[meio]!= chave){
        meio = (inicio+fim)/2;
        if (vetor[meio] < chave){
            inicio = meio+1;
        } else if(vetor[meio]> chave){
            fim = meio - 1;
        } else { cout <<"A chave esta na posicao " << meio << endl;
        return;
        } 
    }
    cout << "Nao foi possivel encontrar a chave"<< endl;
    return;
}

int main(){
    int chave = 20;
    buscaBinaria(chave);
    return 0;
}

