#include <iostream>
using namespace std;

class pilhaVetor {
    private:
        int topo;
        int* dado;
        unsigned capacidade;
        unsigned tamanho;
    public:
        pilhaVetor(int cap = 10);
        ~pilhaVetor(){delete[] dado;}
        void empilha(int valor);
        int desempilha();
};

pilhaVetor::pilhaVetor(int cap){
    topo = -1;
    capacidade = cap;
    tamanho = 0;
    dado = new int[capacidade];
}

void pilhaVetor::empilha(int valor){
    if (tamanho < capacidade){
        topo++;
        dado[topo] = valor;
        tamanho++;
    } else {
        cerr << "Pilha vazia" << endl;
    }
}

int pilhaVetor::desempilha(){
    if (tamanho > 0){
        int valor = dado[topo];
        topo--;
        tamanho--;
        return valor;
    } else {
        cerr << "Pilha vazia" << endl;
        return -1;
    }
}

int main (){
    pilhaVetor p1(12);
    int valor;

    for (int i = 0; i < 8; i++){
        cin >> valor;
        p1.empilha(valor);
    }

    cout << "4 elementos: ";
    for (int i = 0; i < 4; i++){
        cout << p1.desempilha() << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++){
        cin >> valor;
        p1.empilha(valor);
    }

    cout << "vetor de elementos: ";
    for (int i = 0; valor != -1; i++){
        valor = p1.desempilha();
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}