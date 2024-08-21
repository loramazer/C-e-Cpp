#include <iostream>
#include <string.h>
using namespace std;

struct no {
    char dado [50];
    int contador;
    struct no* esq;
    struct no* dir;
};
    struct no* raiz = NULL;
    char palavra_maior[50];
    int maior;

    void insere(char valor[]){
        struct no * atual, *novo, *anterior;

        novo = new(struct no);
        strcpy(novo -> dado, valor);
        novo -> esq = NULL;
        novo -> dir = NULL;
        novo -> contador = 1;

        atual = raiz;

        if(atual == NULL){
            raiz = novo;
            return;
        }
        while(atual != NULL){
            anterior = atual;
            if(strcmp(valor, atual -> dado) == 0){
                delete(novo);
                atual -> contador++;
                return;
            }
            if(strcmp(valor, anterior -> dado) <0){
                anterior -> esq = novo;
            } else anterior -> dir = novo;
        }
    }

//calcula palavra q aparece mais vezes
    void emOrdem (struct no *atual){
        if (atual != NULL){
            emOrdem (atual->esq);
            cout << atual->dado << endl;
            cout << atual -> contador << " vezes" << endl;
            if(atual -> contador > maior){
                maior = atual -> contador;
                strcpy(palavra_maior, atual -> dado);
            }
            emOrdem(atual->dir);
        }
    }

    int main (){
        char palavra[50];
        FILE*fp;
        fp = fopen("palavras.txt", "r");

        if(fp == NULL){
            cout << "Erro" << endl;
            return;
        }

        while (!feof(fp)){
            fscanf (fp, "%s", palavra);
            insere(palavra);
        }
    }

