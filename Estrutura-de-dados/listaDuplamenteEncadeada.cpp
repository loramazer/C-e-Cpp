#include <iostream>

using namespace std;

struct no{
    int dado;
    struct no *prox;
    struct no * ant;
};

struct no *lista = NULL; //Inicializa a lista como vazia.

void inserirLista(int valor){
    struct no *novo, *atual, *anterior;
    novo = new (struct no);
    novo -> dado = valor;
    atual = lista;
    anterior = NULL;

    while (atual != NULL && valor > atual -> dado){
        anterior = atual;
        atual = atual -> prox;
    }
    novo -> prox = atual;
    novo -> ant = anterior;
    
    if (anterior == NULL) {
        anterior -> prox = atual;
    } else lista = novo;
    if (atual != NULL) {
        atual -> ant = novo;
    }
    
}