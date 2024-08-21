#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
};

struct no* raiz, *raiz_avl;


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
    return aux;
};


void insere_bal(int chave) {

    struct no *pp=NULL, *p=raiz_avl, *pajovem=NULL, *ajovem=raiz_avl, *q, *filho;
    int imbal;

    if (p==NULL) {             /* Arvore vazia */
        raiz_avl = cria_no(chave);  /* Funcao para criacao de um novo no */
        return;
    }

    /* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p!=NULL) {
        if (chave < p->dado)
            q = p->esq;
        else q = p->dir;
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
    else pp->dir=q;

    /* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
    if (chave<ajovem->dado)
        filho = ajovem->esq;
    else filho = ajovem->dir;

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
    else imbal = -1;

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
        else esquerda(ajovem);
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
        raiz_avl = p;
    else if (ajovem==pajovem->dir)
        pajovem->dir = p;
    else pajovem->esq = p;

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


void em_ordem(struct no *atual) {
    if (atual!=NULL) {
        em_ordem(atual->esq);
        printf("%d ",atual->dado);
        em_ordem(atual->dir);
    }
}

// Apaga todos os elementos de uma árvore binária.
// Recebe como parâmetro a raiz da árvore a ser apagada
void apaga(struct no *atual) {
    if (atual!=NULL) {
        apaga(atual->esq);
        apaga(atual->dir);
        delete(atual);
    }
}

int main() {

}


