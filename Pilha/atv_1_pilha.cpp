#include <iostream>
#include <stdexcept>
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
        noh (string nome, char mTipo, int valor);
        void setAnterior (noh* anterior){mAnterior = anterior;}
        string getNome() {return mDados.mNome;}
        char getTipo() {return mDados.mTipo;}
        int getValor() {return mDados.mValor;}
        noh* getAnterior() {return mAnterior;}
};

noh::noh(string nome, char tipo, int valor){
    mDados.mNome = nome;
    mDados.mTipo = tipo;
    mDados.mValor = valor;
    mAnterior = NULL;
}

class pilha {
    private:
        noh* mTopo;
    public:
        pilha();
        ~pilha(){limparPilha();}
        bool vazia(){return (mTopo == NULL);}
        void limparPilha(){if (not vazia()) desempilha();}
        void empilha(string nome, char tipo, int valor);
        string desempilha();
        string getTopo();
};

pilha::pilha(){
    mTopo = NULL;
}

void pilha::empilha(string nome, char tipo, int valor){
    noh* novo = new noh(nome,tipo,valor);
    novo->setAnterior(mTopo);
    mTopo = novo;
}

string pilha::desempilha(){
    string saida = "Erro: pilha vazia";

    if (not vazia()){
        noh* aux = mTopo;
        saida = "Nome: " + aux->getNome() + " Tipo: " + aux->getTipo() + " Valor: " + to_string(aux->getValor());
        mTopo = aux->getAnterior();
        aux->setAnterior(NULL);
        delete aux;
    }

    return saida;
}

string pilha::getTopo(){
    if (not vazia()){
        return "Nome: " + mTopo->getNome() + " Tipo: " + mTopo->getTipo() + " Valor: " + to_string(mTopo->getValor());
    }
    return "Erro: pilha vazia";
}

int main() {
    pilha teste;
    char comand;

    do {
        cin >> comand;
        switch (comand){
            case 'i': {
                string n;
                char t;
                int v;

                cin >> n >> t >> v;
                teste.empilha(n,t,v);

                break;
            }
            case 'r':{
                cout << teste.desempilha() << endl;

                break;
            }
            case 'l':{
                teste.limparPilha();

                break;
            }
            case 'e':{
                cout << teste.getTopo() << endl;

                break;
            }
            case 'f':{
                while (not teste.vazia()){
                    cout << teste.desempilha() << endl;
                }

                break;
            }
            default :{
                break;
            }
        }
    } while (comand != 'f');

    return 0;
}

