#include <iostream>

using namespace std;

const int TAM = 7;
int fila[TAM];
int inicioF = 0;
int fimF = 0;
int contador = 0;

void enqueue(int valor){
    if(contador==TAM){
        cout << "Fila cheia!" << endl;
        return;
    }
    contador++;
    fila[fimF] = valor;
    if(fimF==TAM-1){
        fimF = 0;
    } else {
        fimF++;
    }
}

void dequeue(int valor){
    if(contador==0){
        cout << "Fila vazia!" << endl;
        return;
    }
    contador--;
    fila[fimF] = valor;
    if(fimF==TAM-1){
        fimF = 0;
    } else {
        fimF++;
    }
}

void imprime(){
    int i, j;
    if(contador==0){
        cout << "Fila vazia!" << endl;
        return;
    }
    i = inicioF;
    for(j=0;j<contador;j++){
        cout << fila[i] << " ";
        if(i==TAM-1){
            i=0;
        } else {
            i++;
        }
    }
}
int main(){
    
}