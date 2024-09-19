#include <iostream>
#include <cstring>
#include <cctype>
#include <string.h>
#include <ctype.h>

using namespace std;

const int Filhos = 36;
struct no {
    bool fimDeChave;
    struct no * filho [Filhos];
};

struct no *raiz = NULL;

int converte (char caracter) {
    if (isdigit(caracter)){
        return caracter - 48;
    } else {
        caracter = toupper(caracter);
        return caracter - 55;
    }
}

struct no * criaNo(){
    struct no * novo;
    int i;
    novo = new (struct no);
    novo -> fimDeChave = false;
    for (i = 0; i < Filhos; i++){
        novo -> filho [i] = NULL;
    }
    return novo;
}

void insere(const char *chave){
    int tamanho, indice, i=0;
    struct no *atual = raiz;
    tamanho = strlen(chave);
    while (i < tamanho) {
        indice = converte(chave[i]);
        if (atual ->filho [indice] == NULL)
            atual -> filho [indice] = criaNo();
        atual = atual -> filho[indice];
        i++;
    }
    if (atual -> fimDeChave == false){
        atual -> fimDeChave = true;
        cout << "Sucesso" << endl;
    }else cout << "Repetida";
}

void busca(const char *chave){
    int tamanho, indice, i=0;
    struct no *atual = raiz;
    tamanho = strlen(chave);
    while (i < tamanho) {
        indice = converte(chave[i]);
        atual = atual -> filho[indice];
        if(atual == NULL)
            break;
        cout << "Chave não encontrada" << endl;
        i++;
    }
    if (atual != NULL && atual -> fimDeChave == 1){
        cout << "Chave encontrada" << endl;
    }else cout << "Chave não encontrada";
}

int main (){
    raiz = criaNo();
    insere("Marcio");
}