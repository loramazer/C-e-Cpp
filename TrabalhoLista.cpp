#include <iostream>

using namespace std;

const int TAM = 5;
int n_vertices = 0;

struct no {
    int destino;
    struct no *prox;
};

int vertices[TAM]; 
struct no *arestas[TAM]; 

void iniciaGrafo() {
    for(int i = 0; i < TAM; i++) {
        arestas[i] = NULL;
    }
}

void insereVertice(int valor) {
    if (n_vertices == TAM) {
        cout << "Espaco para vertices cheio" << endl;
        return;
    }
    for(int i = 0; i < n_vertices; i++) {
        if (vertices[i] == valor) {
            cout << "Vertice ja existe" << endl;
            return;
        }
    }
    vertices[n_vertices] = valor;
    n_vertices++;
    cout << "Vertice inserido" << endl;
}

void insereAresta(int origem, int destino) {
    int i = 0;
    while (i < n_vertices && vertices[i] != origem) {
        i++;
    }
    if (i == n_vertices) {
        cout << "Vertice de origem nao existe" << endl;
        return;
    }
    
    struct no *atual, *anterior = NULL, *novo;
    atual = arestas[i];
    while(atual != NULL) {
        if (atual->destino == destino) {
            cout << "Aresta ja existe" << endl;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    novo = new no;
    novo->destino = destino;
    novo->prox = NULL;
    if (arestas[i] == NULL) {
        arestas[i] = novo;
    } else {
        anterior->prox = novo;
    }
    
    cout << "Aresta inserida" << endl;
}

void removeAresta(int origem,int destino) {
    int i = 0;
    while (i < n_vertices && vertices[i] != origem) {
        i++;
    }
    if (i == n_vertices) {
        cout << "Vertice de origem nao encontrado" << endl;
        return;
    }
    
    struct no *atual = arestas[i];
    struct no *anterior = NULL;

    while (atual != NULL) {
        if (atual->destino == destino) {
            if (anterior == NULL) {
                arestas[i] = atual->prox;
            } else {
                anterior->prox= atual->prox;
            }
            delete atual;
            cout << "Aresta removida" << endl;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    cout << "Aresta nao encontrada" << endl;
}

void imprime() {
    for(int i = 0; i < n_vertices; i++) {
        cout << vertices[i] << " -> ";
        no* atual = arestas[i];
        while(atual != NULL) {
            cout << "<" << vertices[i] << "," << atual->destino << "> ";
            atual = atual->prox;
        }
        cout << endl;
    }
}

