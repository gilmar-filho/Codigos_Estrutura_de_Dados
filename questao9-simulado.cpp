#include <iostream>
#include <string>

using namespace std;

const int UMPRIMO = 39;

int funcaoHash(string chave, int limite) {
    int pos = 0;
    for (unsigned i = 0; i < chave.length(); i++)
        pos = (UMPRIMO * pos + chave[i]) % limite;
    return pos;
}

class noh {
    friend class tabelaHash;
    private:
        string chave;
        string valor;
        noh* proximo = NULL;
    public:
        noh(string c, string v) {
            chave = c;
            valor = v;
        }
};

class tabelaHash {
    private:
        noh** elementos;
        int capacidade;
    public:
        tabelaHash(int cap = 100);
        ~tabelaHash();
        void insere(string c, string v);
        string recupera(string c);
        void altera(string c, string v);
        void remove(string c);
        void percorre();
};

tabelaHash::tabelaHash(int cap) {
    elementos = new noh*[cap];
    capacidade = cap;
    for (int i = 0; i < cap; i++)
        elementos[i] = NULL;
}

tabelaHash::~tabelaHash() {
    for (int i = 0; i < capacidade; i++) {
        noh* atual = elementos[i];
        while (atual != NULL) {
            noh* aux = atual;
            atual = atual->proximo;
            delete aux;
        }
    }
    delete[] elementos;
}

void tabelaHash::insere(string c, string v) {
    int h = funcaoHash(c, capacidade);
    noh* novo = new noh(c, v);
    if (elementos[h] == NULL) {
        elementos[h] = novo;
    } else {
        noh* atual = elementos[h];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

string tabelaHash::recupera(string c) {
    int h = funcaoHash(c, capacidade);
    if (elementos[h] != NULL) {
        noh* atual = elementos[h];
        while (atual != NULL && atual->chave != c) {
            atual = atual->proximo;
        }
        if (atual != NULL) {
            return atual->valor;
        }
    }
    return "NAO ENCONTRADO!";
}

void tabelaHash::altera(string c, string v) {
    int h = funcaoHash(c, capacidade);
    if (elementos[h] != NULL) {
        noh* atual = elementos[h];
        while (atual != NULL && atual->chave != c) {
            atual = atual->proximo;
        }
        if (atual != NULL) {
            atual->valor = v;
        } else {
            cout << "ERRO NA ALTERACAO!" << endl;
        }
    } else {
        cout << "ERRO NA ALTERACAO!" << endl;
    }
}

void tabelaHash::remove(string c) {
    int h = funcaoHash(c, capacidade);
    if (elementos[h] != NULL) {
        noh* atual = elementos[h];
        noh* anterior = NULL;
        while (atual != NULL && atual->chave != c) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual != NULL) {
            if (anterior == NULL) {
                elementos[h] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            delete atual;
        } else {
            cout << "ERRO NA REMOCAO!" << endl;
        }
    } else {
        cout << "ERRO NA REMOCAO!" << endl;
    }
}

void tabelaHash::percorre() {
    for (int i = 0; i < capacidade; i++) {
        cout << i << ":";
        noh* atual = elementos[i];
        while (atual != NULL) {
            cout << "[" << atual->chave << "/" << atual->valor << "]->";
            atual = atual->proximo;
        }
        cout << "NULL  " << endl;
    }
}

int main() {
    tabelaHash th(10);
    int qtdade;
    string chave;
    string valor;

    cin >> qtdade;
    for (int i = 0; i < qtdade; i++) {
        cin >> chave >> valor;
        th.insere(chave, valor);
    }

    cin >> qtdade;
    for (int i = 0; i < qtdade; i++) {
        cin >> chave >> valor;
        th.altera(chave, valor);
    }

    cin >> qtdade;
    for (int i = 0; i < qtdade; i++) {
        cin >> chave;
        th.remove(chave);
    }

    cin >> qtdade;
    for (int i = 0; i < qtdade; i++) {
        cin >> chave;
        cout << th.recupera(chave) << endl;
    }

    cout << endl;
    th.percorre();
    cout << endl;

    return 0;
}
