#include <iostream>
#include <stdexcept>
using namespace std;

struct Dado{
    string nome;
    char tipo;
    int valor;
};

void imprimirDado(const Dado& dado){
    cout << "Nome: " << dado.nome << "Tipo: " << dado.tipo << "Valor: " << dado.valor << endl;
}

class noh {
    friend class pilha;
    private:
        Dado mDados;
        noh* mAnterior;
    public:
        noh(Dado dado);
};

noh::noh(Dado dado){
    mDados = dado;
    mAnterior = NULL;
}

class pilha {
    private: 
        noh* mTopo;
    public:
        pilha(){mTopo = NULL;}
        ~pilha(){limparPilha();}
        void empilha (const Dado& dado);
        Dado desempilha();
        void limparPilha();
        bool vazia(){return (mTopo == NULL);}
        void getTopo();
};

void pilha::empilha(const Dado& dado){
    noh* novo = new noh(dado);
    novo->mAnterior = mTopo;
    mTopo = novo;
}

Dado pilha::desempilha(){
    if (this->vazia()) throw runtime_error("Erro: pilha vazia!");

    noh* aux = mTopo;
    Dado auxDado = aux->mDados;
    mTopo = aux->mAnterior;
    aux->mAnterior = NULL;
    delete[] aux;
    return auxDado;
}

void pilha::limparPilha(){
    while (not vazia()){
        desempilha();
    }
}

void pilha::getTopo(){
    if (this->vazia()) throw runtime_error("Erro: pilha vazia!");

    imprimirDado(mTopo->mDados);
}

int main() {
    pilha teste;
    char comand;
    Dado info;

    do {
        cin >> comand;
        switch (comand){
            case 'i': {
                cin >> info.nome >> info.tipo >> info.valor;
                teste.empilha(info);

                break;
            }
            case 'r':{
                imprimirDado(teste.desempilha());

                break;
            }
            case 'l':{
                teste.limparPilha();

                break;
            }
            case 'e':{
                teste.getTopo();

                break;
            }
            case 'f':{
                while (not teste.vazia()){
                    imprimirDado(teste.desempilha());
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