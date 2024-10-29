#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct dado {
    int valorBase;
    int atual;
};
const int invalido = -1;

class Torneio {
    private:
        dado* heap;
        int inicio;
        int capacidade;
        int tamanho;
        inline int pai(int i){ return (i-1)/2; }
        inline int esquerdo(int i){ return (i*2)+1; }
        inline int direito(int i){ return (i*2)+2; }
        void copiaMaior(int i);
        void copiaSubindo(int i);
        void arruma();
    public:
        Torneio(dado vet[], int tam);
        ~Torneio(){ delete[] heap; }
        int vencedor(){ return heap[0].valorBase; }
        void imprime();
};

Torneio::Torneio(dado vet[], int tam){
    capacidade = 1;
    while (capacidade < tam){
        capacidade *= 2;
    }

    capacidade = (capacidade - 1) + tam;
    inicio = capacidade - tam;
    heap = new dado[capacidade];

    memcpy( &heap[inicio], vet, tam * sizeof(dado) );

    for (int i = 0; i < inicio; i++){
        heap[i].valorBase = invalido;
        heap[i].atual = invalido;
    }

    tamanho = tam;

    arruma();
}

void Torneio::copiaMaior(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = invalido;
    int menor = dir;

    if ((esq < capacidade)){
        if ((dir < capacidade) and (heap[esq].atual == heap[dir].atual)){
            if (heap[esq].valorBase > heap[dir].valorBase) maior = esq;
            else maior = dir;
        } else if ((dir < capacidade) and (heap[dir].atual > heap[esq].atual)) maior = dir;
        else maior = esq;

        if (maior == dir) menor = esq;
        heap[i] = heap[maior];
        heap[i].atual -= heap[menor].atual;
    } else {
        heap[i].atual = invalido;
    }
    //cout << " maior: " << heap[maior].atual << " menor: "<< heap[menor].atual << " i: " << heap[i].atual << endl;
}

void Torneio::arruma(){
    for (int i = inicio - 1; i >= 0; i--){
        //cout << "i: " << i << " esq: " << esquerdo(i) << " dir: " << direito(i);
        copiaMaior(i);
    }
}

int main(){
    int tam;
    cin >> tam;

    dado* vet = new dado[tam];
    for (int i = 0; i < tam; i++){
        cin >> vet[i].valorBase;
        vet[i].atual = vet[i].valorBase;
    }

    Torneio torneio(vet,tam);

    cout << torneio.vencedor() << endl;

    return 0;
}