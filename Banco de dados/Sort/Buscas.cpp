#include <iostream>
#include <string.h>
using namespace std;

const int TAM = 5;
int vetor[TAM+1] = {5, 2, 6, 20, 30};

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

int main(){
    int chave = 20;
    buscaSequencial(chave);
    buscaSequencialComSentinela(chave);
    buscaTransposicao(chave);
    buscaMoverPraFrente(chave);
    buscaSequencial(chave);
    return 0;
}

