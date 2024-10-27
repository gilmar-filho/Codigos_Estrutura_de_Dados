#include <iostream>
using namespace std;

struct Robo {
    string nome;
    char tipo;
    int tempo;
};

void imprimeDados(Robo d){
    cout << "Nome: " << d.nome << " Tipo: " << d.tipo << " Valor: " << d.tempo << endl;
}

class Pilha {
    private:
        Robo* dados;
        int mTopo;
        unsigned mCapacidade;
        unsigned mTamanho; 
    public:
        Pilha();
        ~Pilha(){delete[] dados;}
        void empilha(Robo dado);
        Robo desempilha();
        void limpaPilha();
        void espiaTopo();
        bool vazia(){return (mTamanho == 0);}
};

Pilha::Pilha(){
    mCapacidade = 6;
    mTamanho = 0;
    mTopo = -1;
    dados = new Robo[mCapacidade];
}

void Pilha::empilha(Robo dado){
    if (mTamanho < mCapacidade){
        mTopo++;
        dados[mTopo] = dado;
        mTamanho++; 
    } else {
        cout << "Erro: pilha cheia!" << endl;
    }
}

Robo Pilha::desempilha(){
    if (mTamanho > 0){
        Robo aux = dados[mTopo];
        mTopo--;
        mTamanho--;
        return aux;
    } else {
        cout << "Erro: pilha vazia!" << endl;
        return Robo{"", ' ', -1};
    }
}

void Pilha::limpaPilha(){
    while (mTamanho > 0){
        desempilha();
    }
}

void Pilha::espiaTopo(){
    if (mTamanho > 0) {
        imprimeDados(dados[mTopo]);
    } else {
        cout << "Erro: pilha vazia!" << endl;
    }
}

int main(){
    Pilha p1;
    Robo info, aux;
    char comando;

    do {
        cin >> comando;
        switch (comando) {
        case 'i':
            cin >> info.nome >> info.tipo >> info.tempo;
            p1.empilha(info);

            break;

        case 'r':
            aux = p1.desempilha();
            if (aux.tempo != -1) imprimeDados(aux);

            break;

        case 'l':
            p1.limpaPilha();

            break;

        case 'e':
            p1.espiaTopo();

            break;

        case 'f':
            break;

        default:
            break;
        }   
    } while (comando != 'f');

    while (not p1.vazia()){
        imprimeDados(p1.desempilha());
    }

    return 0;
}