#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef int dado;

class MaxHeap {
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        int pai(int i){return (i-1)/2;}
        int esquerdo(int i){return (2*i)+1;}
        int direito(int i){return (2*i)+2;}
        void arruma();
        void corrigeDescendo(int i);
        void corrigeSubindo(int i);
    public:
        MaxHeap(int cap);
        MaxHeap(dado vet[], int tam);
        ~MaxHeap(){delete[] heap;}
        void imprime();
        dado espiaRaiz(){return heap[0];}
        dado retiraRaiz();
        void insere(dado d);
};

MaxHeap::MaxHeap(int cap){
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}

MaxHeap::MaxHeap(dado vet[], int tam){
    capacidade = tam;

    heap = new dado[tam];

    memcpy(heap, vet, tam * sizeof(dado));
    tamanho = tam;

    arruma();
}

void MaxHeap::arruma(){
    for (int i = (tamanho/2-1); i >= 0; i--){
        corrigeDescendo(i);
    }
}

void MaxHeap::corrigeDescendo(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

    if ((esq < tamanho) and (heap[esq] > heap[maior])) maior = esq;
    if ((dir < tamanho) and (heap[dir] > heap[maior])) maior = dir;

    if (maior!=i){
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}

void MaxHeap::corrigeSubindo(int i){
    int p = pai(i);
    if (heap[i] > heap[p]){
        swap(heap[i], heap[p]);
        corrigeSubindo(p);
    }
}

void MaxHeap::imprime(){
    for (int i = 0; i < capacidade; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

dado MaxHeap::retiraRaiz(){
    if (tamanho == 0){
        cerr << "Erro ao retirar a raiz" << endl;
        exit(EXIT_FAILURE);
    }
    dado aux = heap[0];
    swap(heap[0], heap[tamanho-1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}

void MaxHeap::insere(dado d){
    if (tamanho == capacidade){
        cerr << "Erro ao inserir, capacidade máxima atingida" << endl;
        exit(EXIT_FAILURE);
    }
    
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

int main(){
    int tam = 12;
    //dado vet[] = {50,2,90,20,230,43,8,34,66,100,110,3,14};
    dado vet1[] = {46, 33, 5, 11, 23, 25, 9, 123, 37, 12, 16, 40};

    MaxHeap *h = new MaxHeap(vet1,tam);
    h->imprime();
    cout << endl;

    for (int i = 0; i < tam; i++){
        cout << h->retiraRaiz() << " : ";
         h->imprime();
    }
    cout << endl;

    int j;
    for (int i = 0; i < tam; i++){
        cin >> j;
        h->insere(j);
    }
    h->imprime();
    cout << endl;

    for (int i = 0; i < tam; i++){
        cout << h->retiraRaiz() << " : ";
         h->imprime();
    }
    cout << endl;

    delete h;

    return 0;
}