#include <iostream>
#include <fstream>
using namespace std;

const int TAM = 10000;
int heap[TAM];
int tamanho = 0;

void insereHeap(int valor) {
    if (tamanho == TAM) {
        cout << "Heap esta cheia." << endl;
        return;
    }

    int i = tamanho;
    heap[tamanho] = valor;
    tamanho++;

    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapfy(int pos) {
    int esq = 2 * pos + 1;
    int dir = 2 * pos + 2;
    int maior = pos;

    if (esq < tamanho && heap[esq] > heap[maior]) {
        maior = esq;
    }
    if (dir < tamanho && heap[dir] > heap[maior]) {
        maior = dir;
    }
    if (maior != pos) {
        swap(heap[pos], heap[maior]);
        heapfy(maior);
    }
}

int removeHeap() {
    if (tamanho == 0) {
        cout << "Heap esta vazia." << endl;
        return -1;
    }

    int remover = heap[0];
    heap[0] = heap[tamanho - 1];
    tamanho--;
    heapfy(0);
    return remover;
}

void maiorHeap() {
    if (tamanho == 0) {
        cout << "Heap esta vazia." << endl;
        return;
    } else {
        cout << "Maior valor: " << heap[0] << endl;
    }
}

int main() {
    int numero;
    ifstream f("numeros.txt");
    if (!f.is_open()) {
        cout << "ERRO! Falha ao abrir arquivo" << endl;
        return 1;
    }

    while (f >> numero) {
        insereHeap(numero);
    }
    f.close();

    cout << "Os 3 maiores valores sao: " << endl;
    for (int i = 0; i < 3; ++i) {
        int maior = removeHeap();
        if (maior != -1) {
            cout << maior << endl;
        } else {
            cout << "Nao ha numeros suficientes." << endl;
            break;
        }
    }

    return 0;
}
