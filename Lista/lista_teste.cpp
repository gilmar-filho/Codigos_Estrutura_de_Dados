#include <iostream>
using namespace std;

typedef int dado;

struct noh {
    dado elemento = 0;
    noh* proximo = NULL;
    noh* pai = NULL;
};

class lista {
    private:
        noh* inicio;
        noh* fim;
        int tamanho;
        void insereEmVazia(dado ent);
        noh* buscaNoh(int posicao);
    public:
        lista();
        ~lista();
        void busca(dado buscado);
        bool isVazia() { return (inicio == NULL); }
        void inserirFim(dado ent);
        void inserirInicio(dado ent);
        void buscaPosicao(int posicao);
        void removerInicio();
        void removerFim();
        void removerPosicao(int posicao);
        void percorrerLista(){
            noh* aux = inicio;
            while (aux != NULL){
                cout << aux->elemento << " ";
                aux = aux->proximo;
            }
            cout << endl;
        }
};

lista::lista(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

lista::~lista(){
    while (not isVazia()){
        removerInicio();
    }
}

void lista::insereEmVazia(dado ent){
    noh* novo = new noh;
    novo->elemento = ent;
    inicio = novo;
    fim = novo;
    tamanho++;
}

noh* lista::buscaNoh(int posicao){
    noh* aux = inicio;
    if ((posicao < 0) and (posicao >= tamanho)){
        cout << "Posição inválida!!!" << endl;
        return NULL;
    } else if (posicao == (tamanho - 1)){
        aux = fim;
    } else {
        if (posicao != 0){
            int pos = 0;
            while (pos != posicao){
                aux = aux->proximo;
            }
        }
    }
    return aux;
}

void lista::busca(dado buscado){
    if (isVazia()){
        cout << "Lista vazia!!!" << endl;
    } else {
        noh* aux = inicio;
        bool encontrado = false;
        int pos = 1;
        while (!encontrado and aux != fim){
            if (aux->elemento == buscado){
                cout << "O elemento " << buscado << " foi encontrado na posição: "
                    << pos << endl;
                encontrado = true;  
            } else aux = aux->proximo;
        }

        if (!encontrado)
            cout << "Elemento não encontrado!!!" << endl;
    }
}

void lista::inserirFim(dado ent){
    if (isVazia()){
        insereEmVazia(ent);
    } else {
        noh* novo = new noh;
        novo->elemento = ent;
        novo->pai = fim;
        fim->proximo = novo;
        fim = novo;
        tamanho++;
    }
}

void lista::inserirInicio(dado ent){
    if (isVazia()){
        insereEmVazia(ent);
    } else {
        noh* novo = new noh;
        novo->elemento = ent;
        novo->proximo = inicio;
        inicio->pai = novo;
        inicio = novo;
        tamanho++;
    }
}

void lista::buscaPosicao(int posicao){
    noh* aux = buscaNoh(posicao);
    if (aux != NULL){
        cout << "O elemento da posição " << posicao << " é:" 
            << aux->elemento << endl;
    }    
}

void lista::removerInicio(){
    if (isVazia()){
       cout << "Lista vazia, nada a remover!" << endl; 
    } else {
        noh* aux = inicio;
        dado removido = inicio->elemento;
        inicio = inicio->proximo;
        if (inicio == NULL){
            fim = NULL;
        } else {
            inicio->pai = NULL;
        }
        delete aux;
        tamanho--;
        cout << "O dado removido é: " << removido << endl;
    }   
}

void lista::removerFim(){
    if (isVazia()) {
        cout << "Lista vazia, nada a remover!" << endl;
    } else {
        noh* aux = fim;
        dado removido = fim->elemento;
        fim = fim->pai;
        if (fim == NULL){
            inicio = NULL;
        } else {
            fim->proximo = NULL;
        }

        delete aux;
        tamanho--;
        cout << "O dado removido é: " << removido << endl;
    } 
}

void lista::removerPosicao(int posicao){
    if (posicao == 0) removerInicio();
    else if (posicao == (tamanho -1)) removerFim();
    else {
        noh* aux = buscaNoh(posicao);
        if (aux != NULL){
            noh* anterior = aux->pai;
            dado removido = aux->elemento;
            anterior->proximo = aux->proximo;
            delete aux;
            tamanho--;
            cout << "O dado removido é: " << removido << endl; 
        }
    }
}

int main(){
    lista teste;
    dado valor;
    //cin >> valor;
    do {
        cin >> valor;
        if (valor != -1) teste.inserirFim(valor);
    } while (valor != -1);

    teste.percorrerLista();
    return 0;
}