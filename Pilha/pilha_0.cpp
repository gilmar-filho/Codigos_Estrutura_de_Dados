#include <iostream>
using namespace std;

class noh {
    private:
        int mValor;
        noh* mProximo;
    public:
        noh(int valor);
        void setProximo(noh *novoValor);
        int getValor();
        noh* getProximo();
};

noh::noh(int valor){
    mValor = valor;
    mProximo = NULL;
}

void noh::setProximo(noh *novoValor){
    mProximo = novoValor;
}

int noh::getValor(){
    return mValor;
}

noh* noh::getProximo(){
    return mProximo;
}

class Pilha {
    private:
        noh* mTopo;
        unsigned tam;
    public:
        Pilha();
        ~Pilha();
        void limparPilha();
        void empilha(int valor);
        int desempilha();
        unsigned getTamanho();
        bool vazia();
};

Pilha::Pilha(){
    mTopo = NULL;
    tam = 0;
}

Pilha::~Pilha(){
    limparPilha();
}

void Pilha::limparPilha(){
    while (not vazia()){
        desempilha();
    }
}

void Pilha::empilha(int valor){
    noh* novo = new noh(valor);
    cout << "novo noh: " << novo << endl;
    cout << "topo : " << mTopo << endl;
    novo->setProximo(mTopo);
    mTopo = novo;
    tam++;
}

int Pilha::desempilha(){
    int auxValor = mTopo->getValor();
    cout << "valor do topo: " << auxValor << endl;
    noh* temp = mTopo;
    cout << "temp: " << temp << endl;
    mTopo = mTopo->getProximo();
    cout << "topo: " << mTopo << endl;
    delete temp;
    tam--;
    return auxValor;
}

unsigned Pilha::getTamanho(){
    return tam;
}

bool Pilha::vazia(){
    return (tam == 0);
}

int main(){
    Pilha p1;
    int num;
    cin >> num;

    while (num >= 0){
        p1.empilha(num);
        cin >> num;
    }

    cout << "tamanho: " << p1.getTamanho() << endl;
    //cout << "valores: ";

    while (not p1.vazia()){
        cout << p1.desempilha() << " ";
    }

    return 0;
}