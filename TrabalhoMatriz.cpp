#include <iostream>
using namespace std;

const int TAM = 5;
int n_vertices = 0;
int matrizAdjacente[TAM][TAM]; 
int vertices[TAM];        


void iniciaGrafo() {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            matrizAdjacente[i][j] = 0; 
        }
    }
}


void insereVertice(int valor) {
    if (n_vertices == TAM) {
        cout << "Numero maximo de vertices atingido" << endl;
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


int indiceVertice(int valor) {
    for (int i = 0; i < n_vertices; i++) {
        if (vertices[i] == valor) {
            return i;
        }
    }
    
    return -1;
}


void insereAresta(int origem, int destino) {
    int iOrigem = indiceVertice(origem);
    int iDestino = indiceVertice(destino);
    
    if (iOrigem == -1) {
        cout << "Vertice de origem nao existe" << endl;
        return;
    }
    if (iDestino == -1) {
        cout << "Vertice de destino nao existe" << endl;
        return;
    }
    if (matrizAdjacente[iOrigem][iDestino] == 1) {
        cout << "Aresta ja existe" << endl;
        return;
    }
    
    matrizAdjacente[iOrigem][iDestino] = 1;
    cout << "Aresta inserida com sucesso." << endl;
}


void removeAresta(int origem, int destino) {
    int iOrigem = indiceVertice(origem);
    int iDestino = indiceVertice(destino);
    if (iOrigem == -1) {
        cout << "Vertice de origem nao existe" << endl;
        return;
    }
    if (iDestino == -1) {
        cout << "Vertice de destino nao existe" << endl;
        return;
    }
    if (matrizAdjacente[iOrigem][iDestino] == 0) {
        cout << "Aresta nao existe" << endl;
        return;
    }
    
    matrizAdjacente[iOrigem][iDestino] = 0;
    cout << "Aresta removida" << endl;
}

void imprime() {
    for(int i = 0; i < n_vertices; i++) {
        cout << vertices[i]<< " -> ";
        for(int j = 0; j < n_vertices; j++) {
            if (matrizAdjacente[i][j] == 1) {
                cout << "<" << vertices[i] << "," << vertices[j] << "> ";
            }
        }
        cout << endl;
    }
}
