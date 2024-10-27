#include <iostream>
using namespace std;

struct Itens {
    string nome;
    char tipo;
    int valor;
};

void imprimirDado(const Itens& dado){
    cout << "Nome: " << dado.nome << " Tipo: " << dado.tipo << " Valor: " << dado.valor << endl;
}

class Noh{
    friend class Pilha;
    private:
        Itens dado;
        Noh* mAnterior;
    public:
        Noh(Itens d);
};

Noh::Noh(Itens d){
    dado = d;
    mAnterior = NULL;
}

class Pilha {
    private:
        Noh* mTopo;
        //unsigned mTamanho;
    public:
        Pilha();
        ~Pilha(){limpaPilha();}
        void empilha(Itens d);
        Itens desempilha();
        bool vazia(){return (mTopo == NULL);}
        void limpaPilha();
        void getTopo();
        void remoçãoEspecial(int limite);
};

Pilha::Pilha(){
    mTopo = NULL;
    //mTamanho = 0;
}

void Pilha::empilha(Itens d){
    Noh* novo = new Noh(d);
    novo->mAnterior = mTopo;
    mTopo = novo;
    //mTamanho++;
}

Itens Pilha::desempilha(){
    if (not this->vazia()){
        Noh* aux = mTopo;
        Itens auxItem = aux->dado;
        mTopo = aux->mAnterior;
        aux->mAnterior = NULL;
        delete aux;
        //mTamanho--;
        return auxItem;
    } else {
        cout << "Erro: pilha vazia!" << endl;
        return Itens{"", ' ', -1};
    }
}

void Pilha::limpaPilha(){
    while (not vazia()){
        desempilha();
    }
}

void Pilha::getTopo(){
    if (this->vazia()){
        cout << "Erro: pilha vazia!" << endl;
    } else {
        imprimirDado(mTopo->dado);
    }
}

void Pilha::remoçãoEspecial(int limite){
    Pilha auxPilha;

    while (not this->vazia()){
        Itens item = desempilha();
        if (item.valor < limite){
            imprimirDado(item);
        } else {
            auxPilha.empilha(item);
        }
    }

    while (not auxPilha.vazia()){
        empilha(auxPilha.desempilha());
    }
}

int main() {
    Pilha teste;
    char comand;
    Itens info, aux;
    int v;

    do {
        cin >> comand;
        switch (comand){
            case 'i': {
                cin >> info.nome >> info.tipo >> info.valor;
                teste.empilha(info);

                break;
            }
            case 'r':{
                aux = teste.desempilha();
                if (aux.valor != -1){
                    imprimirDado(aux);
                }

                break;
            }
            case 'l':{
                teste.limpaPilha();

                break;
            }
            case 'e':{
                teste.getTopo();

                break;
            }
            case 'x':{
                cin >> v;
                teste.remoçãoEspecial(v);

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