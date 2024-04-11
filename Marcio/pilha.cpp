#include <iostream>


using namespace std;

const int TAM = 7;
int topoP = -1 ;
int pilha [TAM];


void push (int valor) {
    if (topoP == (TAM-1)) {
        cout << "Erro: Pilha cheia!" << endl;
        return;
    }
    topoP ++; 
    pilha [topoP] = valor;
    cout << "Valor inserido!" << endl;
}

void pop () {
    if (topoP == -1) {
        cout << "Erro: Pilha vazia!" << endl;
        return;
    }
    cout << "Valor removido: " << endl;
    topoP --;
}


void topo () {
    if (topoP == -1) {
        cout << "Pilha vazia " << endl;
        return;
    }
    cout << "Topo da pilha: " << pilha[topoP] << endl;
}


bool isEmpty() {
    if(topoP == -1) {
        return true;
    } else{
        return false;
    }
}


void verifica () {
    string expr = "(a+b)";
    int tam = expr.size();
    for  (int i=0 ; i < tam ; i++) {
        if (expr[i] == '(')  push('(');
        if (expr[i] == ')') {
            if (isEmpty()) {
            cout << "Expressao correta" << endl;
            return ;
            }else pop();
        }
    }
    if ( !isEmpty() ) {
        cout << "Expressao invalida" << endl;
    }else {
        cout << "Expressao valida" << endl;
    }
}


int main () {
    push(10);
    push(20);
    pop();
    verifica();
    return 0;
}



