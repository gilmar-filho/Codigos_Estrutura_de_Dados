#include <iostream>
using namespace std;

class noh {
    private:
        int dado;
        noh* mProximo;
    public:
        noh(int valor);
        int getValor(){return dado;}
        noh* getProximo(){return mProximo;}
        void setProximo(noh* proximo){mProximo = proximo;}
};

noh::noh(int valor){
    dado = valor;
    mProximo = NULL;
}

class fila {
    private:
        noh* inicio;
        noh* fim;
        int tamanho;
    public:
        fila();
        ~fila(){limparFila();}
        void enfileira(int valor);
        int desenfileira();
        void limparFila();
        bool vazia(){return (tamanho == 0);}
};

fila::fila(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

void fila::enfileira(int valor){
    noh* novo = new noh(valor);
    cout << "Novo noh: " << novo << endl;
    if (inicio == NULL) inicio = novo;
    else fim->setProximo(novo);
    fim = novo;
    cout << "Início: " << inicio << 
        "\nFim: " << fim <<
        "\nPróximo: " << inicio->getProximo() << endl;
    tamanho++;
}

int fila::desenfileira(){
    int auxValor = inicio->getValor();
    cout << "Início: " << inicio << 
        "\nFim: " << fim <<
        "\nPróximo: " << inicio->getProximo() << endl;
    noh* temp = inicio;
    inicio = inicio->getProximo();
    delete temp;
    tamanho--;
    if (tamanho == 0) fim = NULL;
    return auxValor;
}

void fila::limparFila(){
    while (not vazia()){
        desenfileira();
    }
}

int main(){
    fila f1;
    int dado;
    cin >> dado;

    while (dado != -1){
        f1.enfileira(dado);
        cin >> dado;
    }

    cout << endl;
    while (not f1.vazia()){ 
        cout << f1.desenfileira() << endl << endl;
    }
    cout << endl << endl;
    return 0;
}