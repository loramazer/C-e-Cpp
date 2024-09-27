#include <iostream>

using namespace std;

const int TAM = 10;
struct no {
    int dado;
    struct no*prox;
};

struct no *tabela[TAM];

void inicia(){
    for(int i = 0; i < TAM; i++){
        tabela[i] = NULL;
    }
}

int espalha (int chave){
    return chave % TAM;
}

void insere (int chave){
    int pos;
    struct no * atual, *anterior, *novo;
    pos = espalha (chave);
    atual = tabela[pos];
    while(atual != NULL ){
        if(atual -> dado == chave){
            cout << "Chave repetida" << endl;
            return;
        }
        anterior = atual;
        atual = atual -> prox;
    }
    novo = new (struct no);
    novo ->dado = chave;
    novo -> prox = NULL;
    
    if(tabela[pos]==NULL){
        tabela[pos] = novo;
    }else{
        anterior -> prox = novo;
    }
}
