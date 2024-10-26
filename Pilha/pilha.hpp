// pilha.hpp
#ifndef PILHA_HPP
#define PILHA_HPP

#include <string>
using namespace std;

struct Dados {
    string mNome;
    char mTipo;
    int mValor;
};

class noh {
    private:
        Dados mDados;
        noh* mAnterior;
    public:
        noh(string nome, char tipo, int valor);
        void setAnterior(noh* anterior);
        string getNome();
        char getTipo();
        int getValor();
        noh* getAnterior();
};

class pilha {
    private:
        noh* mTopo;
        int tamanho;
    public:
        pilha();
        ~pilha();
        bool vazia();
        void limparPilha();
        void empilha(string nome, char tipo, int valor);
        string desempilha();
        string getTopo();
        int getTamanho();
};

#endif // PILHA_HPP
