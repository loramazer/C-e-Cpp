#include <iostream>
#include <string.h>
using namespace std;

struct no (
    char dado [50];
    int contador;
    struct no* esq;
    struct no* dir;
    );
    struct no* raiz = NULL;

    void insere(char valor){}

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

