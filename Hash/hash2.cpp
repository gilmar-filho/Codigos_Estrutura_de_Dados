// Implementação de uma tabela hash com tratamento de colisões por encadeamento.
// O programa permite realizar as seguintes operações sobre a tabela hash:
// - Inserir um item na tabela, tratando colisões pela inserção no início da lista encadeada.
// - Remover item na tabela, exibindo mensagem de erro se o item não existir.
// - Localizar item na tabela, exibindo informações sobre o item ou uma mensagem de erro caso o item não seja encontrado.
// - Imprimir todo o conteúdo da tabela hash, mostrando a posição e os itens presentes.
// A tabela hash é inicializada com um tamanho especificado pelo usuário.
// Os itens têm três atributos: nome (string), tipo (caracter) e valor (inteiro).

// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras. O crédito do código-base está
// no comentário abaixo!

/* 
 * Classe hash, uma tabela hash em que chaves e valores são strings
 * 
 * by Joukim, 2017-2018, Estruturas de Dados
 * Atualizado por Renato, 2023
 * 
 */

#include <iostream>

using namespace std;

const int UMPRIMO = 7;

int funcaoHash(string s, int M) {
    long h = 0;
    for (unsigned i = 0; i < s.length(); i++) {
        h = (UMPRIMO * h + s[i]) % M;   
    }
    return h;
}

class noh {
friend class tabelaHash;
private:
    string chave;
    char tipo;
    int valor;
    noh* proximo = NULL;

public:
    noh(){
        chave = "";
        tipo = 'a';
        valor = 1;        
    }
};

class tabelaHash {
private:
    // vetor de ponteiros de nós
    noh** elementos;
    int capacidade;

public:
    // construtor padrão
    tabelaHash(int cap = 100);
    // destrutor 
    ~tabelaHash();
    // insere um valor v com chave c
    bool insere(string c, char t, int v);
    // recupera um valor associado a uma dada chave
    bool recupera(string c, char& t, int& v);
    // retira um valor associado a uma chave
    bool remove(string c);
    // percorrendo a tabela hash (para fins de debug)
    void imprime();
};

// construtor padrão
tabelaHash::tabelaHash(int cap) {
    capacidade = cap;
    elementos = new noh*[capacidade]; 
    for (int i = 0; i < capacidade; i++) {
        elementos[i] = NULL; 
    }
}

// destrutor
tabelaHash::~tabelaHash() {
    for(int i = 0; i < capacidade; i++){
        noh* atual = elementos[i];
        while (atual != NULL) { // desaloca cada elemento encadeado no vetor de listas
            noh* aux = atual;
            atual = atual->proximo;
            delete aux;
        }
    }
    delete[] elementos;
}

// insere um valor v com chave c
bool tabelaHash::insere(string c, char t, int v) {
    int hash = funcaoHash(c, capacidade);
    noh* novo = new noh();
    novo->chave = c;
    novo->tipo = t;
    novo->valor = v;

    if(elementos[hash] != NULL){
        novo->proximo = elementos[hash];
    }

    elementos[hash] = novo;
    cout << "chave '" << c << "' inserida na posicao " << hash << endl;
    return true;
}

// recupera um valor associado a uma dada chave
bool tabelaHash::recupera(string c, char& t, int& v) {
    int hash = funcaoHash(c, capacidade);

    noh* atual = elementos[hash];
    while(atual!=NULL){
        if (atual->chave == c) {
            t = atual->tipo;
            v = atual->valor;
            return true;
        }
        atual = atual->proximo;
    }

    return false;
}

// retira um valor associado a uma chave
bool tabelaHash::remove(string c) {
    int hash = funcaoHash(c, capacidade);

    if(elementos[hash] == NULL) return false;

    noh* atual = elementos[hash];
    noh* anterior = NULL;

    while(atual!=NULL){
        if(atual->chave == c){
            if (anterior == NULL) { 
                    elementos[hash] = atual->proximo;
            } else {
                    anterior->proximo = atual->proximo; 
            }
            delete atual;
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return false;
}

// percorrendo a tabela hash (para fins de depuração)
void tabelaHash::imprime( ) {
    noh* atual;
    for (int i = 0; i < capacidade; i++) {
        cout << i << ": ";
        atual = elementos[i];
        while (atual != NULL) {
            cout << "[" << atual->chave << "/"
                 << atual->valor << "]";
            atual = atual->proximo;
        }
        cout << endl;
    }
    
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
                        cout << "Erro na inserção!" << endl;
                    break;
                case 'r': // remover
                    cin >> chave;
                    if (not tabela.remove(chave))
                        cout << "Elemento inexistente!" << endl;
                    break;
                case 'l': // buscar
                    cin >> chave;
                    if (not tabela.recupera(chave,tipo,valor))
                        cout << "Elemento inexistente!" << endl;
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