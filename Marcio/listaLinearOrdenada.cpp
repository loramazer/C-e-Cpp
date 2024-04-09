#include <iostream>

using namespace std;

struct no{
    int dado;
    struct no *prox;
};

struct no *lista = NULL; //Inicializa a lista como vazia.

void inserirLista(int valor){
    struct no *novo, *atual, *anterior;
    novo = new (struct no);
    novo -> dado = valor;
    atual = lista;

    while (atual != NULL && valor > atual -> dado){
        anterior = atual;
        atual = atual -> prox;
    }

    if (atual == lista){
        lista = novo;
        novo -> prox = atual;
    } else  {
        anterior -> prox = novo;
        novo -> prox = atual;
    }
}

void imprime (int valor){
    struct no *atual;

    if (lista == NULL){
        cout << "Lista vazia" << endl;
        return;
    } 

    atual = lista;
    while (atual != NULL) {
        cout << atual -> dado << " ";
        atual = atual -> prox;
    }
}

void removeValor(int valor){
    struct no *atual, *anterior;
    atual = lista;

    while (atual != NULL && valor >= atual -> dado){
        if (atual -> dado == valor){
            
        }
    }
}