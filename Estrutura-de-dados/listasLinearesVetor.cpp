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
    cout << "Valor inserido com sucesso" << endl;
    return;
}

void recuperaLista (int valor) {
    if  (tamanho == 0){
        cout << "A lista esta vazia!"<<endl;
        return;
    }

    if (valor > tamanho) {
        cout <<  "A posicao nao existe na lista." << endl;
        return;
    } else {
        cout << "Valor na posicao " << valor << " : " << lista [valor] << endl;
        return;
    }
    }
    
void removeValor(int valor) {
    int i = 0;
    bool achou = false;

    if (tamanho == 0) {
        cout << "A lista esta vazia" << endl;
        return;
    }

    // Procurar o valor na lista
    while (i < tamanho) {
        if (lista[i] == valor) {
            achou = true;
            break;
        }
        i++;
    }

    if (achou) {
        // Deslocar os elementos à esquerda para preencher o espaço do valor removido
        for (int j = i; j < tamanho - 1; j++) {
            lista[j] = lista[j + 1];
        }
        tamanho--;
        cout << "Valor removido com sucesso " << endl;
    } else {
        cout << "Valor nao encontrado na lista" << endl;
    }
}


void buscaLista (int valor) {
    int i = 0;
    if  (tamanho == 0) {
        cout << "A lista esta vazia" << endl;
        return;
    }

    while (i < tamanho && lista [i] <= valor) {
        if (lista[i]==valor){
            cout << "O valor se encontra na posicao: " << i <<endl;
            return;
        }
        i++ ;
    }
    cout << "O valor nao foi encontrado na lista."<<endl;
    return;
}

void imprime () {
    if  (tamanho == 0) {
        cout << "A lista esta vazia" << endl;
        return;
    }
    
    for (int i = 0; i < tamanho; i++){
        cout << " " << lista[i];
    }
    cout << endl;
    return;
}

int main (){
    insereLista(3);
    insereLista(1);
    insereLista(5);
    insereLista(2);
    insereLista(4);
    imprime(); // Deve imprimir 1 2 3 4 5
    recuperaLista(2); // Deve imprimir o valor na posição 2
    removeValor(3);
    imprime(); // Deve imprimir 1 2 4 5
    buscaLista(4); // Deve imprimir que o valor se encontra na posição 2
    return 0;
}
