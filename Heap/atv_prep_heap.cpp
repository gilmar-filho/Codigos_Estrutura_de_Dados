#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Dado{
    string nome;
    char tipo;
    int qtdEnergia;
    int tempo;
    int prioridade;
};

void imprimirDado(Dado d){
    cout << "[" << d.nome << "/" << d.tipo << "/" << d.qtdEnergia<< "/" << d.tempo << "/" << d.prioridade << "] ";
}

class heap{
    private:
        Dado* mHeap;
        int capacidade;
        int tamanho;
        inline int pai(int i){return (i-1)/2;}
        inline int esquerdo(int i){return (2*i)+1;} 
        inline int direito(int i){return (2*i)+2;}
        void arruma();
        void corrigeDescendo(int i);
        void corrigeSubindo(int i); 
    public:
        heap(int cap);
        ~heap(){delete[] mHeap;}
        void inserir(Dado d);
        void imprime();
        Dado retiraRaiz();
};

heap::heap(int cap){
    capacidade = cap;
    tamanho = 0;
    mHeap = new Dado[capacidade];
}

void heap::inserir(Dado d){
    if (tamanho == capacidade){
        cout << "Erro ao inserir" << endl;
    } else {
        mHeap[tamanho] = d;
        corrigeSubindo(tamanho);
        tamanho++;   
    }
}

void heap::imprime(){
    if (tamanho > 0){
        for (int i = 0; i < tamanho; i++){
            imprimirDado(mHeap[i]);
        }
    } else {
        cout << "Heap vazia!";
    }
    cout << endl;
}

Dado heap::retiraRaiz(){
    Dado aux;
    if (tamanho == 0){
        cout << "Erro ao retirar raiz" << endl;
    } else {
        aux = mHeap[0];
        swap(mHeap[0], mHeap[tamanho-1]);
        tamanho--;
        corrigeDescendo(0);
    }
    return aux;
}

void heap::arruma(){
    for (int i = ((tamanho/2)-1); i >= 0; i--){
        corrigeDescendo(i);
    }
}

void heap::corrigeDescendo(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

    if ((esq < tamanho) and (mHeap[esq].qtdEnergia > mHeap[maior].qtdEnergia)) maior = esq;
    if ((dir < tamanho) and (mHeap[dir].qtdEnergia > mHeap[maior].qtdEnergia)) maior = dir;

    if (maior!=i){ //teste de alteração
        swap(mHeap[i], mHeap[maior]);
        corrigeDescendo(i);
    }
}

void heap::corrigeSubindo(int i){
    int p = pai(i);
    if (mHeap[i].qtdEnergia > mHeap[p].qtdEnergia){
        swap(mHeap[i], mHeap[p]);
        corrigeSubindo(p);
    }
}

int main() { // outro teste
    int capacidade;
    Dado info;
    char comando;

    cin >> capacidade;
    heap meuHeap(capacidade);

    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> info.nome >> info.tipo >> info.qtdEnergia >> info.tempo >> info.prioridade;
                meuHeap.inserir(info);
                break;
            case 'r': // remover
                info = meuHeap.retiraRaiz();
                if (info.nome != ""){
                    cout << info.nome << endl;
                }
                break;
            case 'p': // imprimir
                meuHeap.imprime();
                break;
            case 'f': // finalizar
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    cout << endl;
    return 0;
}