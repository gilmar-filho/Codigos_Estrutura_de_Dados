#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Noh {
    friend class Lista;
    private:
        int mValor;
        Noh *mProximo;
    public:
        Noh(int v){
            mValor = v;
            mProximo = NULL;
        }
};

class Lista{
    private:
        Noh* inicio;
        Noh* fim;
        int capacidade;
        int tamanho;
        void inserirEmVazia(int v);
    public:
        Lista();
        ~Lista(){ removeTodos(); }
        bool vazia(){ return (inicio == NULL); }
        void inserirInicio(int v);
        void inserirFim(int v);
        void inserirEmPosicao(int v, int posicao);
        void percorrerLista();
        void busca(int busc);
        void acessarPosicao(int posicao);
        void removeTodos();
        void removeInicio();
        void removeFim();
        void removeNoEspecifico(int posicao);
};

Lista::Lista(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

void Lista::inserirEmVazia(int v){
    Noh* novo = new Noh(v);
    inicio = novo;
    fim = novo;
    tamanho = 1;
}

void Lista::inserirInicio(int v){
    if (vazia()) inserirEmVazia(v);
    else {
        Noh* novo = new Noh(v);
        novo->mProximo = inicio;
        inicio = novo;
        tamanho++;
    }
}

void Lista::inserirFim(int v){
    if (vazia()) inserirEmVazia(v);
    else {
        Noh* novo = new Noh(v);
        fim->mProximo = novo;
        fim = novo;
        tamanho++;
    }
}

void Lista::inserirEmPosicao(int v, int posicao){
    if (vazia()) inserirEmVazia(v);
    else if (posicao == 0) inserirInicio(v);
    else if (posicao == tamanho) inserirFim(v);
    else {
        Noh* novo = new Noh(v);
        Noh* aux = inicio;
        int posAux = 0;
        while (posAux < (posicao - 1)){
            aux = aux->mProximo;
            posAux++;
        }
        novo->mProximo = aux->mProximo;
        aux->mProximo = novo;
        tamanho++;
    }
}

void Lista::percorrerLista(){
    Noh* aux = inicio;
    while (aux != NULL){
        cout << aux->mValor << " ";
        aux = aux->mProximo;
    }
    cout << endl;
}

void Lista::busca(int busc){
    Noh* aux = inicio;

    while (aux != NULL){
        if (aux->mValor == busc){
            cout << aux->mValor << endl;
            aux = NULL;
        } else {
            aux = aux->mProximo;
        }
    }
}

void Lista::acessarPosicao(int posicao){
    if ((posicao < 0) or (posicao >= tamanho)) throw runtime_error("Posição Inválida!");
    else {
        Noh* aux = inicio;
        int localizacao = 0;
        while (posicao > localizacao){
            aux = aux->mProximo;
            localizacao++;
        }

        cout << aux->mValor << endl;
    }
}

void Lista::removeTodos(){
    Noh* aux = inicio;
    while (aux != NULL){
        Noh* temp = aux;
        aux = aux->mProximo;
        delete temp;
    }

    inicio = NULL;
    fim = NULL;
    tamanho = 0;    
}

void Lista::removeInicio(){
    if (vazia()) throw runtime_error("Lista vazia!");
    else {
        Noh* aux = inicio;
        int valor = aux->mValor;
        inicio = aux->mProximo;
        aux->mProximo = NULL;
        delete aux;
        tamanho--;
        if (vazia()) fim = NULL;
        cout << valor << endl;
    }
}

void Lista::removeFim(){
    if (vazia()) throw runtime_error("Lista vazia!");
    else {  
        Noh* aux = inicio;
        Noh* anterior = NULL;

        while (aux->mProximo != NULL){
            anterior = aux;
            aux = aux->mProximo;
        }

        int valor = aux->mValor;
        
        if (anterior == NULL) inicio = NULL;
        else anterior->mProximo = NULL;

        delete fim;
        fim = anterior;
        tamanho --;

        cout << valor << endl;
    }
}

void Lista::removeNoEspecifico(int v){
    if (vazia()) throw runtime_error("Lista vazia!");
    else {
        Noh* aux = inicio;
        Noh* anterior = NULL;
        while ((aux != NULL) and (aux->mValor != v)){
            anterior = aux;
            aux = aux->mProximo;
        }

        if (aux != NULL) {
            if (aux == inicio) removeInicio();
            else if (aux == fim) removeFim();
            else {
                anterior->mProximo = aux->mProximo;
                tamanho--;
                delete aux;
            }
        } else throw runtime_error("Valor não está na lista!");
    }
}

int main(){
    Lista teste;
    char comando;
    int valor;

    do {
        try {
            cin >> comando;
            switch (comando){
                case 'i':
                    cin >> valor;
                    teste.inserirInicio(valor);
                    break;
                case 'p':
                    cin >> valor;
                    teste.inserirFim(valor);
                    break;
                case 'l':
                    int pos;
                    cin >> valor >> pos;
                    teste.inserirEmPosicao(valor, pos);
                    break;
                case 'q':
                    cin >> valor;
                    teste.busca(valor);
                    break;
                case 'w':
                    teste.percorrerLista();
                    break;
                case 'f':
                    break;
                default:
                    cout << "comando inválido" << endl;
                    break;
            }
        } catch(runtime_error& e){
            cout << e.what() << endl;
        }
    }while (comando != 'f');

    return 0;
}