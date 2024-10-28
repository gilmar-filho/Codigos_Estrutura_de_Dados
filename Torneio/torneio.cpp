#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef int dado;
const int invalido = -1;

class Torneio {
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        int inicioDados;
        inline int pai(int i){return (i-1)/2;}
        inline int esquerdo(int i){return (i*2)+1;}
        inline int direito(int i){return (i*2)+2;}
        void arruma();
        void copiaMaior(int i);
        void copiaSubindo(int i);
    public:
        Torneio(int numFolhas);
        Torneio(dado vet[], int tam);
        ~Torneio(){delete[] heap;}
        void insere(dado d);
        void imprime();
};

Torneio::Torneio(dado vet[], int tam){
    capacidade = 1;
    while (capacidade < tam){
        capacidade *= 2;
    }

    capacidade = capacidade - 1 + tam;

    heap = new dado[capacidade];
    inicioDados = capacidade - tam;

    cout << "inicioDados: " << inicioDados << endl;
    cout << "capacidade: " << capacidade << endl;

    memcpy(&heap[inicioDados], vet, tam*sizeof(dado));

    for (int i = 0; i < inicioDados; i++) {
        heap[i] = invalido;
    }

    tamanho = tam;

    arruma();
}

Torneio::Torneio(int numFolhas){
    capacidade = 1;
    while (capacidade < numFolhas){
        capacidade *= 2;
    }

    capacidade = capacidade - 1 + numFolhas;
    heap = new dado[capacidade];
    inicioDados = capacidade-numFolhas;

    cout << "inicioDados: " << inicioDados << endl;
    cout << "capacidade: " << capacidade << endl;

    for (int i = 0; i < capacidade; i++){
        heap[i] = invalido;
    }
}

void Torneio::arruma(){
    cout << "arruma: " << inicioDados-1 << endl;
    for (int i = inicioDados - 1; i >= 0; i--){
        copiaMaior(i);
    }
}

void Torneio::copiaMaior(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    cout << "i: " << i << " e: " << esq << " d: " << dir << endl;
    int maior = -1;
    if (esq < capacidade){
        if ((dir < capacidade) and (heap[dir] > heap[esq])){
            maior = dir;
        } else {
            maior = esq;
        }
        heap[i] = heap[maior];
    } else {
        heap[i] = invalido;
    }
    imprime();
}

void Torneio::copiaSubindo(int i){
    int p = pai(i);
    if (heap[i] > heap[p]){
        heap[p] = heap[i];
        copiaSubindo(p);
    }
    imprime();
}

void Torneio::insere(dado d){
    if (tamanho == capacidade){
        cerr << "Erro ao inserir" << endl;
        exit(EXIT_FAILURE);
    } else {
        heap[tamanho+inicioDados] = d;
        copiaSubindo(tamanho+inicioDados);
        tamanho++;
    }
}

void Torneio::imprime(){
    for (int i = 0; i < capacidade; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main(){
    int tam = 9;
    dado vet1[] = {50,2,90,20,230,43,8,34,66};

    Torneio *h = new Torneio(vet1, tam);
    h->imprime();
    delete h;

    cout << endl << endl << "heap 13" << endl;

    tam = 13;
    dado vet2[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};
    h = new Torneio(vet2, tam);
    h->imprime();
    delete h;

    cout << endl << endl << "heap 9" << endl;

    tam = 9;
    h = new Torneio(9);
    for (int i = 0; i < tam; i++){
        h->insere(vet1[i]);
        h->imprime();
    }
    delete h;

    return 0;
}