#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
    char cor;
};

struct no* raiz=NULL, *raizAVL=NULL, *raizRN=NULL;


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

void ajustaRN(struct no *novo) {

    struct no *p=raizRN, *pp=NULL, *ap=NULL, *bp=NULL, *tp;

    // Percorre árvore binária com quatro ponteiros:
    // p: nó atual
    // pp (pai do nó apontado por p)
    // ap (avô do nó apontado por p)
    // bp (bisavô do nó apontado por p)
    while (p!=novo) {
        if (ap!=NULL)
            bp=ap;
        if (pp!=NULL)
            ap=pp;
        pp=p;
        if (novo->dado < p->dado)
            p = p->esq;
        else p = p->dir;
    }

    if (p==raizRN) {
        raizRN->cor='n';
        return; 			/* Inserção na raiz */
    }

    if (pp->cor=='n')
        return;        /* Não houve desbalanceamento, pois pai é preto */

    if (pp==ap->esq)   /* Descobre tio do nó apontado por p */
        tp=ap->dir;
    else
        tp=ap->esq;

// Se tio for vermelho, troca cor do pai, do tio e do avô
    if (tp!=NULL && tp->cor=='v') {
        tp->cor='n';
        pp->cor='n';
        ap->cor='v';
        ajustaRN(ap);
// A mudança de cor do avô pode gerar um problema, então ajusta novamente
// a árvore usando o avô como referência
    } else {    // Caso onde o tio é preto e rotações são necessárias
        if (p==pp->dir && pp==ap->esq) { // Filho é direito e pai é esquerdo
            esquerda(pp);
            ap->esq=p;
            pp=p;
            p=p->esq;
        } else if (p==pp->esq && pp==ap->dir) { // Filho é esquerdo e pai é direito
            direita(pp);
            ap->dir=p;
            pp=p;
            p=p->dir;
        }

        pp->cor='n';
        ap->cor='v';
        //  Filho e pai são ambos esquerdos
        if (p == pp->esq && pp == ap->esq)
            direita(ap);
        else //  Filho e pai são ambos direitos
            esquerda(ap);

        // Ajusta o ponteiro do bisavô do nó apontado por p
        if (bp!=NULL)
            if (ap==bp->esq)
                bp->esq=pp;
            else
                bp->dir=pp;
        else
            raizRN=pp;
    }
}

//Insere valor em uma árvore RN
void insereRN(int chave) {

    struct no *pp;
    struct no *p=raizRN;

    while (p!=NULL) {
        pp=p;
        if (chave < p->dado)
            p = p->esq;
        else p = p->dir;
    }
    p=cria_no(chave);
    if (raizRN==NULL)
        raizRN = p;
    else if (chave<pp->dado)
        pp->esq=p;
    else
        pp->dir=p;
    ajustaRN(p);
}

void em_ordem(struct no *atual) {
    if (atual!=NULL) {
        em_ordem(atual->esq);
        cout << atual->dado << " ";
        em_ordem(atual->dir);
    }
}

void apaga(struct no *atual) {
    if (atual!=NULL) {
        apaga(atual->esq);
        apaga(atual->dir);
        delete(atual);
    }
}

