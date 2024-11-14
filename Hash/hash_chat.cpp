#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int UMPRIMO = 7;

// Um noh guarda um par (chave / valor) 
class noh {
    friend class lista;
    friend class tabelaHash;
    private:
        string chave;
        char tipo;
        int valor;
        noh* proximo;
        noh(const string& c = "", const char& t = 'a', const int& v=0, noh* prox = nullptr):
            chave(c), tipo(t), valor(v), proximo(prox) { }
};

// Uma lista guarda todos os Nos cuja chave foi mapeada na mesma posição.
class lista {
    friend class tabelaHash;
    private:
        noh* primeiro; // primeiro nó da lista
        unsigned short numElementos; // quantidade de valores na lista
        void inserirVazia(const string& c, const char& t, const int& v);
    public:
        lista(); // Construtor
        ~lista(); // Destrutor
        void removeTodos();
        unsigned short tamanho() { return numElementos; } // Consulta do Tamanho
        // Adiciona um novo par (chave, valor) na lista
        // Insere no início, para não precisar de ponteiro para o fim
        void insere(const string& c, const char& t, const int& v);
        // Remove o noh com dada chave da lista.
        // Se a chave não existe, retorna informação.
        bool remove(const string& c);
        // Busca um elemento na lista, retorna falso se não encontrado
        // o valor buscado é retornado por passagem por referência
        // na variável valorBuscado
        bool busca(const string& c, char& tipoBuscado, int& valorBuscado);
        // Verifica se já tem algum dado na lista com 
        // uma dada chave
        bool verificaOcorrencia(const string& c);
        // Imprime o conteúdo da lista, para fins de depuração
        void imprime() {
            noh* atual = primeiro;
            while (atual != nullptr) {
                    cout << "[" << atual->chave << "/"
                         << atual->valor << "] ";
                    atual = atual->proximo;
            }
        }

        bool vazia() { return (primeiro == nullptr); }
};

lista::lista() {
    primeiro = nullptr;
    numElementos = 0;
}

lista::~lista() {
    removeTodos();
}

void lista::removeTodos() {
    noh* aux = primeiro;
    while (aux != nullptr) {
        noh* temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    primeiro = nullptr;
    numElementos = 0;
}

void lista::inserirVazia(const string& c, const char& t, const int& v) {
    noh* novo = new noh(c, t, v);
    primeiro = novo;
    numElementos++;
}

void lista::insere(const string& c, const char& t, const int& v) {
    if (vazia()) inserirVazia(c, t, v);
    else {
        noh* novo = new noh(c, t, v);
        novo->proximo = primeiro;
        primeiro = novo;
        numElementos++;
    }
}

bool lista::remove(const string& c) {
    if (vazia()) throw runtime_error("Erro: lista vazia!");
    else {
        noh* atual = primeiro;
        noh* anterior = nullptr;

        while (atual != nullptr && atual->chave != c) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == nullptr) return false;
        if (anterior == nullptr) primeiro = atual->proximo;
        else anterior->proximo = atual->proximo;

        delete atual;
        numElementos--;
        return true;
    }
}

bool lista::busca(const string& c, char& tipoBuscado, int& valorBuscado) {
    if (vazia()) throw runtime_error("Erro: lista vazia!");
    else {
        noh* aux = primeiro;
        while (aux != nullptr) {
            if (aux->chave == c) {
                tipoBuscado = aux->tipo;
                valorBuscado = aux->valor;
                return true;
            }
            aux = aux->proximo;
        }
        return false;
    }
}

bool lista::verificaOcorrencia(const string& c) {
    noh* aux = primeiro;
    while (aux != nullptr) {
        if (aux->chave == c) return true;
        aux = aux->proximo;
    }
    return false;
}

class tabelaHash {
    private:
        lista** tabela; // vetor de ponteiros para lista
        unsigned numPosicoes; // quantidade de posições na tabela hash
        unsigned funcaoHash(const string& s) const; // converte uma chave (string) num endereço da tabela
    public:
        tabelaHash(unsigned cap = 100); // construtor padrão
        ~tabelaHash();
        bool insere(const string& c, const char t, const int v);
        bool valor(const string& c, char& tipoBuscado, int& valorRetorno);
        bool remove(const string& c);
        void imprime() const;
};

unsigned tabelaHash::funcaoHash(const string& s) const {
    unsigned pos = 0;
    for (unsigned int i = 0; i < s.size(); ++i)
        pos = (UMPRIMO * pos + s[i]) % numPosicoes;
    return pos;
}

tabelaHash::tabelaHash(unsigned cap) {
    tabela = new lista*[cap];
    for (unsigned i = 0; i < cap; i++) tabela[i] = new lista();
    numPosicoes = cap;
}

tabelaHash::~tabelaHash() {
    for (unsigned i = 0; i < numPosicoes; i++) {
        delete tabela[i];
    }
    delete[] tabela;
}

bool tabelaHash::insere(const string& c, const char t, const int v) {
    unsigned pos = funcaoHash(c);
    if (!tabela[pos]->verificaOcorrencia(c)) {
        tabela[pos]->insere(c, t, v);
        return true;
    } else {
        return false;
    }
}

bool tabelaHash::valor(const string& c, char& tipoBuscado, int& valorRetorno) {
    unsigned pos = funcaoHash(c);
    return tabela[pos]->busca(c, tipoBuscado, valorRetorno);
}

bool tabelaHash::remove(const string& c) {  
    unsigned pos = funcaoHash(c);
    return tabela[pos]->remove(c);
}

void tabelaHash::imprime() const {
    for (unsigned i = 0; i < numPosicoes; i++) {
        cout << i << ": ";
        tabela[i]->imprime();
        cout << endl;
    }
}

int main() {
    int tamanhoTH;
    cin >> tamanhoTH;
    tabelaHash tabela(tamanhoTH);
    char comando;
    string chave;
    char tipo;
    int valor;    
    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> chave >> tipo >> valor;
                    if (!tabela.insere(chave, tipo, valor))
                        cout << "Erro na inserção: chave já existente!" << endl;
                    break;
                case 'r': // remover
                    cin >> chave;
                    if (!tabela.remove(chave))
                        cout << "Erro na remoção: chave não encontrada!" << endl;
                    break;
                case 'l': // busca
                    cin >> chave;
                    if (!tabela.valor(chave, tipo, valor))
                        cout << "Erro na busca: chave não encontrada!" << endl;
                    else
                        cout << "Tipo: " << tipo << " Valor: " << valor << endl;
                    break;
                case 'p': // mostrar estrutura
                    tabela.imprime();
                    break;
                case 'f': // finalizar
                    break;
                default:
                    cout << "Comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    return 0;
}
