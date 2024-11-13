#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    stack<int> pilha;
    queue<int> fila;
    priority_queue<int> filaPrioridade;
    vector<int> lista;
    vector<int> :: iterator it;

    pilha.push(10);
    pilha.push(100);
    cout << pilha.top() << endl;
    cout << pilha.size() << endl;
    lista.push_back(40);
    it=lista.begin();
    it++;
    it++;
    lista.insert(it, 15);

    sort(lista.begin(), lista.end());
    
    if (pilha.empty()) cout << "pilha vazia" << endl;
    else cout << "pilha nao vazia" << endl;

    for (it = lista.begin(); it != lista.end(); it++){
        cout << *it << endl;
    } for (int i=0; i< lista.size(); i++){
        cout << lista[i] << endl;
    }
    for (int j=0; j<lista.end(); j++){
        cout << lista.at(j) << endl;
    }
}