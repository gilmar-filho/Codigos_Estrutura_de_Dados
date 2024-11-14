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
        noh(const string& c = "", const char& t = 'a', const int& v=0, noh* prox = NULL):
            chave(c), tipo(t), valor(v), proximo(prox) { }
};

// Uma lista guarda todos os Nos cuja chave foi mapeada na mesma posição.
class lista {
    friend class tabelaHash;
    private:
        noh* primeiro; // primeiro nó da lista
        unsigned short numElementos; // quantidade de valores na lista
        void inserirVazia(const string& c, const char& t,const int& v);
    public:
        lista(); // Construtor
        ~lista(); // Destrutor
        void removeTodos();
        unsigned short tamanho() { return numElementos; } // Consulta do Tamanho
        // Adiciona um novo par (chave, valor) na lista
        // Insere no início, para não precisar de ponteiro para o fim
        void insere(const string& c, const char& t,const int& v);
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
            while (atual != NULL) {
                    cout << "[" << atual->chave << "/"
                         << atual->valor << "]";
                    atual = atual->proximo;
            }
        }

        bool vazia(){ return (primeiro == NULL); }
};

lista::lista(){
    primeiro = NULL;
    numElementos = 0;
}

lista::~lista(){
    removeTodos();
}

void lista::removeTodos(){
    noh* aux = primeiro;
    while (aux != NULL){
        primeiro = aux->proximo;
        delete aux;
    }
    
    primeiro = NULL;
    numElementos = 0;
}

void lista::inserirVazia(const string& c, const char& t,const int& v){
    noh* novo = new noh(c,t,v);
    primeiro = novo;
    numElementos++;
}

void lista::insere(const string& c, const char& t,const int& v) {
    if (vazia()) inserirVazia(c,t,v);
    else {
        noh* novo = new noh(c,t,v);
        novo->proximo = primeiro;
        primeiro = novo;
        numElementos++;
    }
}

bool lista::remove(const string& c){
    if (vazia()) throw runtime_error("Erro: hash vazia!");
    else {
        noh* aux = primeiro;

        while (aux != NULL){
            if (aux->chave == c) {
                primeiro = aux->proximo;
                delete aux;
                return true;
            } else aux = aux->proximo;
        }
        return false;
    }
}

bool lista::busca(const string& c, char& tipoBuscado, int& valorBuscado){
    if (vazia()) throw runtime_error("Erro: hash vazia!");
    else {
        noh* aux = primeiro;

        while (aux != NULL){
            if (aux->chave == c) {
                tipoBuscado = aux->tipo;
                valorBuscado = aux->valor;
                return true;
            }
            else aux = aux->proximo;
        }

        return false;
    }
}

bool lista::verificaOcorrencia(const string& c) {
    noh* aux = primeiro;

    while (aux != NULL){
        if (aux->chave == c) return true;
        else aux = aux->proximo;
    }

    return false;
}

class tabelaHash {
    private:
        // vetor de ponteiros para lista
        lista* *tabela;
        // quantidade de posições na tabela hash
        unsigned numPosicoes;
        // converte uma chave (string) num endereço da tabela 
        // - versão simples
        unsigned funcaoHash(const string& s) {
            return funcaoHash(s, numPosicoes);
        } 
        // converte uma chave (string) num endereço da tabela 
        // - versão para redimensionamento
        unsigned funcaoHash(const string& s, int cap) {
            unsigned pos = 0;
            for (unsigned int i = 0; i < s.size(); ++i)
                pos = (UMPRIMO * pos + s[i]) % cap;
            return pos;
        }
    public:
        // construtor padrão
        tabelaHash(unsigned cap = 100);
        ~tabelaHash();
        // Insere um nó com dada chave e valor.
        bool insere(const string& c, char& t, const int& v);
        // Retorna um valor associado a uma dada chave.
        // Se a chave não existe, retorna "NÃO ENCONTRADO!".
        bool valor(const string& c, char& tipoBuscado, int& valorRetorno);
        // Retira do hash um nó com dada chave.
        bool remove(const string& c);
        // Imprime o conteúdo interno do hash (para fins de depuração)
        void imprime() {
            for (unsigned i = 0; i < numPosicoes; i++) {
                cout << i << ": ";
                tabela[i].imprime();
                cout << endl;
            }
        }
};

tabelaHash::tabelaHash(unsigned cap = 100){
    tabela = new lista*[cap];
    for (int i = 0; i < cap; i++) tabela[i] = NULL;
    numPosicoes = 0;
}

tabelaHash::~tabelaHash(){
    for (int i = 0; i < cap; i++){
        tabela[i]->removeTodos;
        tabela[i] = NULL;
    }
    numPosicoes = 0;
}

bool tabelaHash::insere(const string& c, char& t, const int& v){
    unsigned pos = funcaoHash(c);
    tabela[pos]->insere(c,t,v);
}

bool tabelaHash::valor(const string& c, char& tipoBuscado, int& valorRetorno){
    unsigned pos = funcaoHash(c);
    return tabela[pos]->busca(c,tipoBuscado,valorRetorno);
}

bool tabelaHash::remove(const string& c) {  
    unsigned pos = funcaoHash(c);
    return tabela[pos]->remove(c,tipoBuscado,valorRetorno);
}

int main() {
    int tamanhoTH;
    cin >> tamanhoTH;
    tabelaHash tabela(tamanhoTH);
    char comando;
    string chave;
    char tipo = 'a';
    int valor = -1;    
    do {
        try{
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> chave >> tipo>> valor;
                    if (not tabela.insere(chave, tipo, valor))
                        cout << "Erro na inserção: chave já existente!" << endl;
                    break;
                case 'r': // remover
                    cin >> chave;
                    if (not tabela.remove(chave))
                        cout << "Erro na remoção: chave não encontrada!" << endl;
                    break;
                case 'l': // remover
                    cin >> chave;
                    if (not tabela.valor(chave,tipo,valor))
                        cout << "Erro na busca: chave não encontrada!" << endl;
                    else
                        cout << "Tipo: " << tipo << " Valor: " << valor << endl;
                    break;
                case 'p': // mostrar estrutura
                    tabela.imprime();
                    break;

                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    tabela.imprime();
    cout << endl;
    return 0;
}