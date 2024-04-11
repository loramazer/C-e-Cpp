#include <iostream>

using namespace std;

struct no{
    int dado;
    struct no *prox;
};

struct no *lista = NULL; //Inicializa a lista como vazia.

void inserirLista(int valor){
    struct no *novo, *atual, *anterior;
    novo = new (struct no);
    novo -> dado = valor;
    atual = lista;

    while (atual != NULL && valor > atual -> dado){
        anterior = atual;
        atual = atual -> prox;
    }

    if (atual == lista){
        lista = novo;
        novo -> prox = atual;
    } else  {
        anterior -> prox = novo;
        novo -> prox = atual;
    }
    cout << "O valor " << valor << " foi inserido com sucesso!" << endl;
}

void imprime (){
    struct no *atual;

    if (lista == NULL){
        cout << "Lista vazia" << endl;
        return;
    } 

    atual = lista;
    while (atual != NULL) {
        cout << atual -> dado << " ";
        atual = atual -> prox;
    }
    cout << endl;
}

void removeValor(int valor){
    struct no *atual, *anterior = NULL, *apaga = NULL;
    atual = lista;

    if (lista == NULL){
        cout << "A lista está vazia" << endl;
        return;
    }

    while (atual != NULL && valor >= atual -> dado){
        if (atual -> dado == valor){
           apaga = atual;
           atual = atual -> prox;
           if  (apaga == lista) {
            lista = lista -> prox;
           } else{
           anterior -> prox = atual;
           }
           cout << "O valor " << valor << " foi removido com sucesso!" << endl;
           delete (apaga);
        } else {
        anterior = atual;
        atual = atual -> prox;
        }
    }
        
        if (apaga == NULL){
            cout << "O elemento nao existe na lista." << endl;
            return;
        }
    }

void buscaLista (int valor){
    struct no * atual = lista, *achou = NULL;
    int posicao = 1;
    if (lista == NULL){
       cout << "A lista esta vazia" << endl;
       return;
    }

    while (atual != NULL && valor>= atual -> dado) {
        if (valor == atual->dado) {
            achou = atual;
            cout << "Elemento encontrado na posicao: " << posicao << endl;
            break;
        }
        atual = atual->prox;
        posicao ++;
    }
    if  (!achou) {
        cout << "O elemento nao foi encontrado na lista" << endl;
    }

}

void recuperaLista (int posicao){
    struct no *atual;
    int c = 0;
    atual = lista;
    
    if (lista == NULL ){
        cout << "Lista vazia" << endl;
        return;
    }

    while (atual != NULL && c < posicao){
        c++;
        if (c == posicao) {
            cout << "Valor necontrado na posicao " << c << " foi " << atual -> dado << endl;
            return;
        }
        atual = atual -> prox;
    }
    cout << "Posicao inexistente" << endl;
}

int main (){
    inserirLista(5);
    inserirLista(9);
    inserirLista(7);
    recuperaLista(2);
    recuperaLista(5);
    return 0;
}