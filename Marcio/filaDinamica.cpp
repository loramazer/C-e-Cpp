#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no *prox;
};

struct no * inicio = NULL;
struct no * fim = NULL;

void enqueue (int valor) {
    struct no *novo;
    novo = new (struct no);
    novo -> dado = valor;
    novo -> prox = NULL;

    if (fim == NULL) {
        inicio = fim = novo;
    } else fim -> prox = novo;
    return;
}