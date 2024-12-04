#include <iostream>
#include <string>
using namespace std;

struct Elemento {
    int chave;
    string valor;
};

class TabelaHash {
private:
    Elemento** tabela;
    int tamanho;

public:
    TabelaHash(int tamanho);
    ~TabelaHash();
    int funcaoHash(int chave);
    void inserir(int chave, const string& valor);
    string recuperar(int chave);
    void limparTabela();
    void imprimir();
};

TabelaHash::TabelaHash(int tamanho) {
    this->tamanho = tamanho;
    tabela = new Elemento*[tamanho];
    for (int i = 0; i < tamanho; i++) {
        tabela[i] = new Elemento[4];
        for (int j = 0; j < 4; j++) {
            tabela[i][j].chave = -1;
            tabela[i][j].valor = "";
        }
    }
}

TabelaHash::~TabelaHash() {
    limparTabela();
}

int TabelaHash::funcaoHash(int chave) {
    return chave % tamanho;
}

void TabelaHash::inserir(int chave, const string& valor) {
    int indice = funcaoHash(chave);
    bool inserido = false;
    bool itemJaExiste = false;
    int i = 0;

    while (i < 4 && !inserido) {
        if (tabela[indice][i].chave == chave) {
            itemJaExiste = true;
            inserido = true;
        }
        else if (tabela[indice][i].chave == -1) {
            tabela[indice][i].chave = chave;
            tabela[indice][i].valor = valor;
            inserido = true;
        }
        i++;
    }

    if (itemJaExiste) {
        cout << "ITEM JÁ ESTÁ NA TABELA!" << endl;
    } else if (!inserido) {
        cout << "NÚMERO MÁXIMO DE COLISÕES PARA CHAVE!" << endl;
    }
}

string TabelaHash::recuperar(int chave) {
    int indice = funcaoHash(chave);
    int i = 0;

    while (i < 4) {
        if (tabela[indice][i].chave == chave) {
            return tabela[indice][i].valor;
        }
        i++;
    }
    return "NÃO ENCONTRADO!";
}

void TabelaHash::limparTabela(){
    for (int i = 0; i < tamanho; i++) {
        delete[] tabela[i];
    }
    delete[] tabela;
}

void TabelaHash::imprimir() {
    for (int i = 0; i < tamanho; i++) {
        cout << i << ":";
        for (int j = 0; j < 4; j++) {
            cout << "[" << tabela[i][j].chave << "/" << tabela[i][j].valor << "]";
        }
        cout << endl;
    }
}

int main() {
    int tamanho, quantidade, chave;
    string valor;

    cin >> tamanho;
    cin >> quantidade;

    TabelaHash hash(tamanho);

    for (int i = 0; i < quantidade; i++) {
        cin >> chave >> valor;
        hash.inserir(chave, valor);
    }

    for (int i = 0; i < 4; i++) {
        cin >> chave;
        cout << hash.recuperar(chave) << endl;
    }

    hash.imprimir();

    return 0;
}
