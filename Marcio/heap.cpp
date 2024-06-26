#include <iostream>
 using namespace std;

 const int TAM = 10000;
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

 int removeHeap(){
    if (tamanho == 0) {
        cout << "heap vazia" << endl;
        return -1;
    }

    int remover = heap [0];
    heap[0] = heap[tamanho-1];
    tamanho--;

    heapfy(0);
    cout << "Valor removido: " << remover << endl;
    return remover;
 }

 int main() {
    int numero;
    FILE* f;
    f = fopen("numeros.txt", "r");
    if (f==0){
        cout << "Erro ao abrir arquivo" << endl;
    }
    while (fscanf(f, "%d", &numero) != EOF){
        insereHeap(numero);
    }
    fclose(f);
    heapfy(0);
    for(int i = 0; i < 3; ++i){
        int maior = removeHeap();
        if (maior != -1){
            cout << maior << endl;
        } else {
            cout << "Nao ha numeros suficientes" << endl;
            break;
        }
    }
    return 0;
}