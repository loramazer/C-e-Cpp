#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>

#define TAM 20000

using namespace std;

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
    char cor;
};

struct no* raiz=NULL, *raizAVL=NULL;

int vetor[TAM];
int contBS, contAVL, contAB, contBB, chave;

void copiaVetor(int* novoVetor){
    for (int i = 0; i < TAM; i++){
        novoVetor[i] = vetor[i];
    }
}

void implementarVetor (){
    for (int i = 0; i < TAM; i++){
        vetor[i] = rand() % 30000;
        if(vetor[i] == vetor[i-1]){
          i--;  
        }
    }
}

int gerarChave(){
    chave = rand();
}

// Rotação para a esquerda
void esquerda(struct no *p) {

    struct no *q, *hold;

    q = p->dir;
    hold = q->esq;
    q->esq = p;
    p->dir = hold;

}

//Rotação para a direita
void direita(struct no *p) {

    struct no *q, *hold;

    q = p->esq;
    hold = q->dir;
    q->dir = p;
    p->esq = hold;

}

// Cira um no e preenche os membros
struct no *cria_no(int valor) {
    struct no *aux = new (struct no);
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    aux->cor='v';
    return aux;
};

//Insere valor em uma árvore AVL
void insereArvoreAVL(int chave) {

    struct no *pp=NULL, *p=raizAVL, *pajovem=NULL, *ajovem=raizAVL, *q, *filho;
    int imbal;

    if (p==NULL) {             /* Arvore vazia */
        raizAVL = cria_no(chave);  /* Funcao para criacao de um novo no */
        return;
    }

    /* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p!=NULL) {
        if (chave < p->dado)
            q = p->esq;
        else
            q = p->dir;
        if (q!=NULL)
            if (q->bal != 0) {
                pajovem=p;
                ajovem=q;
            }
        pp = p;
        p = q;
    }

    q = cria_no(chave);

    if (chave<pp->dado)
        pp->esq=q;
    else
        pp->dir=q;

    /* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
    if (chave<ajovem->dado)
        filho = ajovem->esq;
    else
        filho = ajovem->dir;

    p = filho;

    while (p!=q) {
        if (chave < p->dado) {
            p->bal=1;
            p=p->esq;
        } else {
            p->bal = -1;
            p=p->dir;
        }
    }

    if (chave<ajovem->dado)
        imbal = 1;
    else
        imbal = -1;

    if (ajovem->bal==0) {      /*Não houve desbalanceamento */
        ajovem->bal=imbal;
        return;
    }


    if (ajovem->bal!=imbal) {   /*Não houve desbalanceamento */
        ajovem->bal=0;
        return;
    }

    /* Houve desbalanceamento */
    if (filho->bal == imbal) {
        p=filho;
        if (imbal==1)        /* Faz rotação simples */
            direita(ajovem);
        else
            esquerda(ajovem);
        ajovem->bal=0;
        filho->bal=0;
    } else {
        if (imbal==1) {	  /*Faz rotação dupla */
            p=filho->dir;
            esquerda(filho);
            ajovem->esq=p;
            direita(ajovem);
        } else {
            p=filho->esq;
            direita(filho);
            ajovem->dir=p;
            esquerda(ajovem);
        }
        if (p->bal==0) {
            ajovem->bal=0;
            filho->bal=0;
        } else {
            if (p->bal == imbal) {
                ajovem->bal = - imbal;
                filho->bal = 0;
            } else {
                ajovem->bal = 0;
                filho->bal = imbal;
            }
        }
        p->bal=0;
    }

    if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
        raizAVL = p;
    else if (ajovem==pajovem->dir)
        pajovem->dir = p;
    else
        pajovem->esq = p;

    return;
}

void insereArvore(int valor) {

    struct no *atual, *anterior, *aux;

    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    if (raiz==NULL) {
        raiz = aux;
        return;
    }

    atual=raiz;

    while (atual!=NULL) {
        anterior=atual;
        if (valor < atual->dado)
            atual=atual->esq;
        else atual=atual->dir;
    }
    if (valor < anterior->dado)
        anterior->esq=aux;
    else anterior->dir=aux;
}

void buscaSequencial (int chave, int* vetor){
    int i = 0;
    contBS++;
    while (i < TAM && vetor[i] != chave){
        i++;
        contBS++;
    }
    contBS++;
    if (i != TAM)
        cout << "Encontrei na posicao " << i << endl;
    else cout << "Nao encontrei " << chave << endl;
}

void buscaBinaria(int chave, int* vetor){
    int inicio = 0;
    int fim = TAM-1;
    int meio = 0;
    contBB++;
    while (meio<=fim && vetor[meio]!= chave){
        meio = (inicio+fim)/2;
        contBB++;
        if (vetor[meio] < chave){
            inicio = meio+1;
        } else if(vetor[meio]> chave){
            fim = meio - 1;
            contBB++;
        } else { cout <<"A chave esta na posicao " << meio << endl;
        return;
        } 
    }
    cout << "Nao foi possivel encontrar a chave"<< endl;
    return;
}

void apaga(struct no *atual) {
    if (atual!=NULL) {
        apaga(atual->esq);
        apaga(atual->dir);
        delete(atual);
    }
}

void buscaArvores(int chave,struct no* raiz){

}

int main (){
    float opBB = 0, opBS= 0, opAVL = 0, opAB = 0;
    for(int i = 0; i <= 1000; i++){
        int chave = gerarChave(), buscaS[TAM], buscaB[TAM];
        implementarVetor();
        copiaVetor(buscaS);
        buscaSequencial(chave, buscaS);
        copiaVetor(buscaB);
        buscaBinaria(chave, buscaB);
        for(int j = 0; j < TAM; j++){
            insereArvore(vetor[i]);
        }
        //buscaArvore(chave, no);
        apaga(raiz);
        for(int j = 0; j < TAM; j++){
            insereArvoreAVL(vetor[i]);
        }
        //buscaArvoreAVL(chave, noAVL);
        apaga(raizAVL);
    }
    opBB = contBB / 1000;
    opAB = contAB / 1000;
    opAVL = contAVL / 1000;
    opBS = contBS / 1000;
    cout << "Busca Sequencial: "<< &opBS << "Busca Binaria: " << &opBB << "Busca em Arvore Binaria: " << &opAB 
    << "Busca em Arvore AVL: "<< &opAVL<< endl;
}
