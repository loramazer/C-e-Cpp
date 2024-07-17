#include <iostream>
 using namespace std;

 const int TAM = 1;
 int heap[TAM];
 int tamanho = 0;

 void insereHeap(int valor){
    int i;
    if (tamanho == TAM){
        cout << "heap cheia" << endl;
        return;
    }

    heap[tamanho] = valor;
    i = tamanho;
    while ( i > 0 && valor > heap[(i-1)/2]){
        heap[i] = heap[(i-1)/2];
        i = (i-1)/2;
    }
    heap[i] = valor;
    tamanho++;
 }

 void heapfy(int pos){
    int esq, dir, maior, temp;

    esq = 2 * pos + 1;
    dir = 2 * pos + 2;

    if (esq < tamanho && heap[esq] > heap[0]){
        maior = esq;
    }else maior = pos;
    if(dir < tamanho && heap[dir] > heap[maior]){
        maior = dir;
    }
    if (maior != pos){
        temp = heap[maior];
        heap[maior] = heap[pos];
        heap[pos] = temp;
        heapfy(maior);
    }
 }

 void removeHeap(){
    if (tamanho == 0){
        cout << "Heap vazia"<< endl;
        return;
    }
    int remove = heap[0];
    heap[0] = heap[tamanho - 1];
    tamanho --;

    heapfy(0);

    return;
 }

 void imprime