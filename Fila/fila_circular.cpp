#include <iostream>
using namespace std;

class filaCircular {
    private:
        int mInicio;
        int mFim;
        int* dado;
        unsigned mCapacidade;
        unsigned mTamanho;
    public:
        filaCircular(int capacidade = 10);
        ~filaCircular(){delete[] dado;}
        void enfileira(int valor);
        int desenfileira();
        void depura();
};

filaCircular::filaCircular(int capacidade){
    mInicio = -1;
    mFim = -1;
    mCapacidade = capacidade;
    dado = new int[mCapacidade];
    mTamanho = 0;
}

void filaCircular::enfileira(int valor){
    if (mTamanho <= mCapacidade){
        mFim++;
        mFim = mFim % mCapacidade;
        //cout << "Fim: " << mFim << endl;
        dado[mFim] = valor;
        if (mTamanho == 0) {
            mInicio++;
            //mInicio = mInicio % mCapacidade;
        }
        mTamanho++;
    } else {
        cerr << "Fila cheia!!!" << endl;
    }
}

int filaCircular::desenfileira(){
    if (mTamanho > 0){
        int valor = dado[mInicio];
        mTamanho--;
        if (mTamanho > 0){
            mInicio++;
            mInicio = mInicio % mCapacidade;
        } else {
            mInicio = -1;
            mFim = -1;
        }
        return valor;
    } else {
        cerr << "Fila vazia!!!" << endl;
        return -1;
    } 
}

void filaCircular::depura(){
    cout << "Inicio: " << mInicio << endl;
    cout << "Fim: " << mFim << endl;
    cout << "Tamanho: " << mTamanho << endl;
    cout << "vetor: ";
    for (unsigned i = 0; i < mCapacidade; i++){
        cout << dado[i] << " ";
    }
    cout << endl;
}

int main(){
    filaCircular f1(12);
    int valor;
    cout << 1 % 12 << endl;
    for (int i = 0; i < 12; i++){
        cin >> valor;
        f1.enfileira(valor);
    }

    cout << "10 dados: ";
    for (int i = 0; i < 10; i++){
        cout << f1.desenfileira() << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++){
        cin >> valor;
        f1.enfileira(valor);
    }

    cout << "3 dados: ";
    for (int i = 0; i < 3; i++){
        cout << f1.desenfileira() << " ";
    }
    cout << endl;

    f1.depura();
    return 0;
}