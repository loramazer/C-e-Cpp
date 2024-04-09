#include <iostream>

using namespace std;

const int TAM = 5;
int lista [TAM];
int tamanho = 0;

void inserirlista (int valor, int posicao) {
    int i;
    if (tamanho == TAM) {
        cout << "Lista cheia" << endl;
        return;
    }
    if (posicao < 0 || posicao > tamanho) {
        cout <<  "Posicao invalida" << endl;
        return;
    }
    for (i=tamanho; i>posicao; i--) {
        lista [i] = lista[i - 1];
        }
    lista [i] = valor;
    tamanho++;
}

void removelista (int posicao){
    int i;
    if(tamanho==0){
        cout<<"A lista esta vazia!"<<endl;
        return;
        }
    if (posicao < 0 || posicao >= tamanho) {
        cout <<   "Posicao invalida" << endl;
        return;
    }
    for (i = posicao ; i < tamanho - 1; i++) {
        lista[i]=lista[i+1];
    }
    tamanho--;
}

void imprime () {
    int i;
    if  (tamanho == 0) {
        cout << "A lista está vazia." << endl;
        return;
    }
    for  (i = 0; i < tamanho; i++) {
        cout << lista[i] << endl;
    }
}

void recuperalista (int posicao) {
    int i;
    if (tamanho == 0) {
        cout << "Lista Vazia!" << endl;
        return;
    }
    if (posicao < 0 || posicao >= tamanho) {
        cout << "Posicao invalida" << endl;
        return;
    }
    cout << "Elemento na posicao " << posicao << ": " <<  lista[posicao] << endl;
}

void buscaLista (int valor) {
    int i;
    if (tamanho == 0) {
        cout << "Lista vazia" << endl;
        return;
    }
    for (i=0; i < tamanho; i++){
        if (valor == lista[i]){
        cout << "Elemento encontrado na posicao: "<< i << endl;
        return;
    }
    }
    cout << "Elemento não encontrado na lista" << endl;
}

int main (){
    inserirlista (5,0);
    inserirlista (0,1);
    inserirlista (1,2);
    inserirlista (3,3);
    removelista (2);
    recuperalista (0);
    buscaLista(0);
    imprime();
    return 0;
}