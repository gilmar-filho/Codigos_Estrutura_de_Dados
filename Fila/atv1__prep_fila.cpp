#include <iostream>
using namespace std;

struct Itens {
    string assunto;
    string nome;
    char tipo;
    int numero;
};

void imprimirItem(const Itens& i){
    cout << "Nome: " << i.assunto << " Assunto: " << i.nome << " Tipo: " << i.tipo << " Processo: " << i.numero << endl;
}

class Fila {
    private:
        Itens* dados;
        int inicio;
        int fim;
        unsigned capacidade;
        unsigned tamanho;
    public:
        Fila();
        ~Fila(){delete[] dados;}
        void enfileira(Itens d);
        Itens desenfileira();
        void limpaFila();
        bool vazia(){return (tamanho == 0);}
        void espiaTopo();
};

Fila::Fila(){
    capacidade = 6;
    tamanho = 0;
    inicio = -1;
    fim = -1;
    dados = new Itens[capacidade];
}

void Fila::enfileira(Itens d){
    if (tamanho < capacidade){
        fim++;
        fim = fim % capacidade;
        dados[fim] = d;
        if (tamanho == 0){
            inicio++;
        }
        tamanho++;
    } else {
        cout << "Erro: fila cheia!" << endl;
    }
}

Itens Fila::desenfileira(){
    if (tamanho > 0){
        Itens aux = dados[inicio];
        inicio++;
        inicio = inicio % capacidade;
        tamanho--;
        return aux;
    } else {
        cout << "Erro: fila vazia!" << endl;
        return Itens{"", "", ' ', -1};
    }
}

void Fila::limpaFila(){
    for (unsigned i = 0; i < capacidade; i++){
        dados[i] = {"", "", ' ', 0};
    }
    tamanho = 0;
    inicio = -1;
    fim = -1;
}

void Fila::espiaTopo(){
    if (tamanho > 0){
        imprimirItem(dados[inicio]);
    } else {
        cout << "Erro: fila vazia!" << endl;
    }
}

int main(){
    Fila f;
    Itens info, aux;
    char comando;

    do {
        cin >> comando;
        switch (comando) {
            case 'i':
                cin >> info.assunto >> info.nome >> info.tipo >> info.numero;
                f.enfileira(info);

                break;
            case 'r':
                aux = f.desenfileira();
                if (aux.numero != -1){
                    imprimirItem(aux);
                }

                break;
            case 'l':
                f.limpaFila();

                break;
            case 'e':
                f.espiaTopo();

                break;
            case 'f':
                while (not f.vazia()){
                    imprimirItem(f.desenfileira());
                }
                break;
            default:
                break;
        }
    } while (comando != 'f');

    return 0;
}