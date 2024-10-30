#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct dado {
    char operacao;
    int prioridade;
};

class MaxHeap {
private:
    dado* heap;
    int capacidade;
    int tamanho;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i);
    void arruma();
    void corrigeDescendo(int i);
    void corrigeSubindo(int i);
    int buscaIndice(char operacao);

public:
    MaxHeap(int cap);
    ~MaxHeap();
    void imprime();
    dado retiraRaiz();
    void insere(dado d);
    void alteraPrioridade(char operacao, int novaPrioridade);
};

MaxHeap::MaxHeap(int cap) {
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}

MaxHeap::~MaxHeap() {
    delete[] heap;
}

void MaxHeap::arruma() {
    for (int i = (tamanho / 2 - 1); i >= 0; i--) {
        corrigeDescendo(i);
    }
}

int MaxHeap::pai(int i) {
    return (i - 1) / 2;
}

int MaxHeap::esquerdo(int i) {
    return 2 * i + 1;
}

int MaxHeap::direito(int i) {
    return 2 * i + 2;
}

void MaxHeap::corrigeDescendo(int i) {
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;
    if ((esq < tamanho) && (heap[esq].prioridade > heap[maior].prioridade)) {
        maior = esq;
    }
    if ((dir < tamanho) && (heap[dir].prioridade > heap[maior].prioridade)) {
        maior = dir;
    }
    if (maior != i) {
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}

void MaxHeap::corrigeSubindo(int i) {
    int p = pai(i);
    if (i > 0 && heap[i].prioridade > heap[p].prioridade) {
        swap(heap[i], heap[p]);
        corrigeSubindo(p);
    }
}

void MaxHeap::imprime() {
    for (int i = 0; i < tamanho; i++) {
        cout << heap[i].operacao << heap[i].prioridade << " ";
    }
    cout << endl;
}

dado MaxHeap::retiraRaiz() {
    if (tamanho == 0) {
        cerr << "Erro ao retirar raiz" << endl;
        exit(EXIT_FAILURE);
    }
    dado aux = heap[0];
    swap(heap[0], heap[tamanho - 1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}

void MaxHeap::insere(dado d) {
    if (tamanho == capacidade) {
        cerr << "Erro ao inserir" << endl;
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    tamanho++;
    corrigeSubindo(tamanho - 1);
}


int MaxHeap::buscaIndice(char operacao) {
    for (int i = 0; i < tamanho; i++) {
        if (heap[i].operacao == operacao) {
            return i;
        }
    }
    return -1;
}

void MaxHeap::alteraPrioridade(char operacao, int novaPrioridade) {
    int indice = buscaIndice(operacao);
    if (indice == -1) {
        cout << "Operacao não encontrada!" << endl;
        return;
    }

    int prioridadeAntiga = heap[indice].prioridade;
    heap[indice].prioridade = novaPrioridade;

    if (novaPrioridade > prioridadeAntiga) {
        corrigeSubindo(indice);
    } else {
        corrigeDescendo(indice);
    }
}

int main() {
    int capacidade, opcao;
    cin >> capacidade;
    MaxHeap* h = new MaxHeap(capacidade);
    dado entrada, saida;
    cin >> opcao;
    while (opcao != 0) {
        if (opcao == 1) {
            cin >> entrada.operacao >> entrada.prioridade;
            h->insere(entrada);
        } else if (opcao == 2) {
            saida = h->retiraRaiz();
            cout << saida.operacao << saida.prioridade << endl;
        } else if (opcao == 3) {
            h->imprime();
        } else if (opcao == 4) {
            char operacao;
            int novaPrioridade;
            cin >> operacao >> novaPrioridade;
            h->alteraPrioridade(operacao, novaPrioridade);
        }
        cin >> opcao;
    }
    delete h;
    return 0;
}
