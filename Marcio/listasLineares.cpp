#include <iostream>

using namespace std;

const int TAM = 5;
int lista [TAM];
int tamanho = 0;

void insereLista (int valor) {
    int i;

    if (tamanho == TAM) {
        cout << "Lista cheia" << endl;
        return;
    }

    for (i = tamanho; i > 0 && valor < lista [i-1]; i--) {
        lista[i] = lista[i-1];
        
    }

    lista [i] = valor;
    tamanho++;
    return;
}

void recuperalista (int valor) {
    if  (tamanho == 0){
        cout << "A lista esta vazia!"<<endl;
        return;
    }

    if (valor > tamanho) {
        cout <<  "O elemento nao existe na lista." << endl;
        return;
    } else {
        cout << lista [valor];
        return;
    }
    }
    
void removeValor (int valor) {
    int i;

    if  (tamanho == 0) {
        cout << "A lista esta vazia" << endl;
        return;
    }

    for (i = 0; i < tamanho && valor < lista[i]; i++){
        if (lista[i] == valor) break;
    }
    while (i < tamanho - 1) {
        lista[i] = lista[i + 1];
        i++;
    }
    tamanho--;
    return;
}

void buscaLista (int valor) {

    if  (tamanho == 0) {
        cout << "A lista esta vazia" << endl;
        return;
    }

    for (int i=0; i<tamanho; i++){
        if (lista[i]==valor){
            cout << i <<endl;
            return;
        }
    }
}

void imprime () {
    if  (tamanho == 0) {
        cout << "A lista esta vazia" << endl;
        return;
    }
    
    for (int i = 0; i < tamanho; i++){
        cout << lista[i] << endl;
    }
    return;
}

int main () {
    insereLista(1);
    insereLista(26);
    removeValor (1);
    imprime();
    return 0;
}