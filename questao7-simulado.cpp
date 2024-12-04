#include <iostream>

using namespace std;

typedef int Dado;

class Noh{
    friend class Lista;
    private:
        const Dado dado;
        Noh* proximo;
    public:
        Noh(Dado d = 0);
};

Noh::Noh(Dado d) : dado(d) {
    proximo = nullptr;
}

class Lista{
    private:
        Noh* primeiro;
        Noh* ultimo;
        int tamanho;
        void removeTodos();
    public:
        Lista();
        Lista(const Lista& umaLista);
        ~Lista();
        Lista& operator=(const Lista& umaLista);
        inline void insere(Dado dado);
        void insereNoFim(Dado dado);
        void insereNoInicio(Dado dado);
        void insereNaPosicao(int posicao, Dado dado);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
        Lista dividirEmDuas(int N);
};

Lista::Lista() {
    tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;
}

Lista::Lista(const Lista& umaLista){
    tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;

    Noh* aux = umaLista.primeiro;

    while (aux != nullptr){
        insereNoFim(aux->dado);
        aux = aux->proximo;
    }
}

Lista::~Lista(){
    removeTodos();
}

void Lista::removeTodos(){
    Noh* aux = primeiro;
    Noh* temp;

    while (aux != nullptr){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }

    tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;
}

Lista& Lista::operator=(const Lista& umaLista){
    removeTodos();
    Noh* aux = umaLista.primeiro;

    while (aux != nullptr){
        insereNoFim(aux->dado);
        aux = aux->proximo;
    }

    return *this;
}

void Lista::insere(Dado dado){
    insereNoFim(dado);
}

void Lista::insereNoFim(Dado dado){
    Noh* novo = new Noh(dado);

    if (vazia()){
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

void Lista::insereNoInicio(Dado dado){
    Noh* novo = new Noh(dado);

    if (vazia()){
        primeiro = novo;
        ultimo = novo;
    } else {
        primeiro->proximo = novo;
        primeiro = novo;
    }
    tamanho++;
}

void Lista::insereNaPosicao(int posicao, Dado dado){
    Noh* novo = new Noh(dado);

    if ((posicao <= tamanho) && (posicao >= 0)){
        if (vazia()){
            primeiro = novo;
            ultimo = novo;
        } else if (posicao == 0){
            novo->proximo = primeiro;
            primeiro = novo;
        } else if (posicao == tamanho){
            ultimo->proximo = novo;
            ultimo = novo;
        } else {
            Noh* aux = primeiro;
            int posAux = 0;

            while ( posAux < (posicao - 1)){
                aux = aux->proximo;
                posAux++;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        tamanho++;
    } else {
        cout << "Posição inválida!" << endl;
        exit(EXIT_FAILURE);
    }
}

int Lista::procura(Dado valor){
    Noh* aux = primeiro;
    int posAux = 0;

    while ((aux != nullptr) && (aux->dado != valor)){
        posAux++;
        aux = aux->proximo;
    }

    if (aux == nullptr){
        posAux = -1;
    }

    return posAux;
}

void Lista::imprime(){
    Noh* aux = primeiro;

    while (aux != nullptr){
        cout << aux->dado << " ";
        aux = aux->proximo;
    }

    cout << endl;
}

bool Lista::vazia(){
    return primeiro == nullptr;
}

Lista Lista::dividirEmDuas(int N){
    if (N < 0 or N >= tamanho) {
        imprime();
        if (N >= tamanho) {
            cout << -1 << endl;
        } else {
            cout << "" << endl;
        }
        Lista listaVazia;
        return listaVazia;
    }

    Lista novaLista;
    Noh* aux = primeiro;
    int posAux = 0;

    while (aux != nullptr && posAux <= N) {
        aux = aux->proximo;
        posAux++;
    }

    while (aux != nullptr) {
        novaLista.insereNoFim(aux->dado);
        aux = aux->proximo;
    }

    Noh* atual = primeiro;
    posAux = 0;
    while (atual != nullptr && posAux < N) {
        atual = atual->proximo;
        posAux++;
    }

    if (atual != nullptr) {
        atual->proximo = nullptr;
    }

    imprime();
    novaLista.imprime();

    return novaLista;
}

int main() {
    Lista lista;
    int m, n;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n;
        lista.insere(n);
    }

    int posicao;
    cin >> posicao;

    lista.dividirEmDuas(posicao);

    return 0;
}
