#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no* esq;
    struct no* dir;
};
struct no* raiz = NULL;

void insereArvore(int valor){
    struct no* atual, *anterior, *novo;
    novo = new (struct no);
    novo -> dado = valor;
    novo -> esq = NULL;
    novo -> dir = NULL;

    if (raiz == NULL){
        raiz = novo;
        return;
    }
    atual = raiz;

    while (atual != NULL){
        anterior = atual;
    }

    if (valor < atual -> dado){
        atual = atual -> esq;
        } else {
            atual = atual -> dir;
        }

    if (valor < anterior -> dado)
        anterior -> esq = novo;
    else anterior -> dir = novo;
    }

void emOrdem(struct no *atual){
    if (atual != NULL){
        emOrdem(atual -> esq);
        cout << atual -> dado << " ";
        emOrdem(atual -> dir);
    }
}

void buscaArvore (int valor){
    struct no* atual = raiz;
    while (atual != NULL){
        if (valor == atual -> dado){
            cout << "Valor encontrado" << endl;
            return;
        }
        if (valor < atual -> dado){
            atual = atual -> esq;
        } else atual = atual -> dir;
    }
    cout << "Nao encontrei" << endl;
}

int main (){
    int valor;
    cout<< "Insira o valor"<< endl;
    cin>> valor;
    insereArvore(valor);
    return 0;
}
