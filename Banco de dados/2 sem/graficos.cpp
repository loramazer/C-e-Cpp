#include <iostream>

using namespace std;

const int TAM = 5;

int vertice [TAM];
int adj [TAM] [TAM];
int n_vertices = 0;

void inicia_grafo(){
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            adj [i][j] = 0;
        }
    }
}

void insere (int valor){
    if(n_vertices < TAM){
        for(int i = 0; i< n_vertices; i++){
            if(vertice[i] == valor){
                cout << "valor repetido" << endl;
                return;
            }
        }
    }
}
