/*
Crie um programa que seja capaz de armazenar em uma lista encadeada as equipes de uma maratona de programação. Para cada equipe deverá ser informado o seu nome, o nome do líder da equipe, a linguagem de programação que será utilizada e a quantidade de membros. Você poderá utilizar o código fornecido como base de implementação.

Os comandos que deverão ser utilizados para execução do programa são:

i: inserir uma nova equipe no inicio da lista. O formato de entrada é: NomeEquipe Lider Linguagem QtdMembro
h: inserir uma nova equipe no fim da lista. O formato de entrada é: NomeEquipe Lider Linguagem QtdMembros
m: inserir uma nova equipe na posição informada pelo usuário através de um número inteiro. Considere 0 como a posição inicial da lista. Caso não seja possível inserir na posição indicada imprima "Posição Inexistente!". O formato de entrada é: posiçãoASerInserida NomeEquipe Lider Linguagem QtdMembros
r: apagar uma determinada equipe do início da lista. Caso não exista a equipe deverá imprimir Remoção em lista vazia!
a: apagar uma determinada equipe do fim da lista. Caso não exista a equipe deverá imprimir Remoção em lista vazia!
p: imprimir lista de equipes cadastradas. Imprimir Lista vazia! quando não tiver elemento a ser impresso.
s: buscar por uma equipe a partir de seu nome. Imprimir Nao encontrado quando a busca não obtiver sucesso.
Nota: o formato de saída das equipes deve ser: (Nome, Lider, Linguagem, QtdMembros). Para mais instâncias de equipes (comando de impressão), cada uma delas devem ser separadas por quebras de linha.

Entradas:

Comandos detalhados no exercício
Saídas:

Impressões detalhadas no exercício
Exemplo de Entrada e Saída misturados:

r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s Thundercats
Lista vazia!
i Vingadores Stark Ruby 3
h LigaDaJustica Batman C++ 4
m 1 MuppetBabies Kermit Phyton 9
p
(Vingadores, Stark, Ruby, 3)
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
s Thundercats
Nao encontrado
r
p
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
a
p
(MuppetBabies, Kermit, Phyton, 9)
f
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct equipe {
    string nomeEquipe;
    string lider;
    string linguagem;
    int qtdMembros;
};

class noh {
friend class lista;
private:
    equipe elenco;
    noh* proximo;
public:
    noh(equipe d);
};

noh::noh(equipe d) {
    elenco = d;
    proximo = NULL;
}

class lista {
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
    void removeTodos(); 
    //void imprimeReversoAux(noh* umNoh);
public:
    lista();
    //lista(const lista& umaLista);
    ~lista();
    lista& operator=(const lista& umaLista);
    //inline void insere(equipe elenco);
    void insereNoFim(equipe elenco);
    void insereNoInicio(equipe elenco);
    void insereNaPosicao(int posicao, equipe elenco);
    int procura(string valor);
    void imprime();
    //void imprimeReverso();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
};

lista::lista() {
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

lista::~lista() {
    removeTodos();
}

void lista::removeTodos() {
    noh* aux = primeiro;
    while (aux != NULL) {
        noh* temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

lista& lista::operator=(const lista& umaLista) {
    removeTodos();
    noh* aux = umaLista.primeiro;
    while (aux != NULL) {
        insereNoFim(aux->elenco);
        aux = aux->proximo;
    }
    return *this;
}

inline bool lista::vazia() {
    return (primeiro == NULL);
}

void lista::insereNoFim(equipe elenco) {
    noh* novoNo = new noh(elenco);
    if (vazia()) {
        primeiro = novoNo;
        ultimo = novoNo;
    } else {
        ultimo->proximo = novoNo;
        ultimo = novoNo;
    }
    tamanho++;
}

void lista::insereNoInicio(equipe elenco) {
    noh* novoNo = new noh(elenco);
    if (vazia()) {
        primeiro = novoNo;
        ultimo = novoNo;
    } else {
        novoNo->proximo = primeiro;
        primeiro = novoNo;
    }
    tamanho++;
}

void lista::insereNaPosicao(int posicao, equipe elenco) {
    if (posicao < 0 || posicao > tamanho) throw runtime_error("Posição Inexistente!");
    if (posicao == 0) {
        insereNoInicio(elenco);
    } else if (posicao == tamanho) {
        insereNoFim(elenco);
    } else {
		noh* novoNo = new noh(elenco);
		noh* aux = primeiro;
		for (int i = 0; i < posicao - 1; i++) {
			aux = aux->proximo;
		}
		novoNo->proximo = aux->proximo;
		aux->proximo = novoNo;
		tamanho++;
	}
}

int lista::procura(string valor) {
    noh* aux = primeiro;
    int pos = 0;
    while (aux != NULL) {
        if (aux->elenco.nomeEquipe == valor) {
            return pos;
        }
        aux = aux->proximo;
        pos++;
    }
    cout << "Nao encontrado" << endl;
    return -1;
}

void lista::imprime() {
    if (vazia())throw runtime_error("Lista vazia!");
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << "(" << aux->elenco.nomeEquipe << ", "
             << aux->elenco.lider << ", "
             << aux->elenco.linguagem << ", "
             << aux->elenco.qtdMembros << ")" << endl;
        aux = aux->proximo;
    }
}

void lista::removeNoInicio() {
    if (vazia())throw runtime_error("Remoção em lista vazia!");
    noh* temp = primeiro;
    primeiro = primeiro->proximo;
    delete temp;
    tamanho--;
    if (vazia()) {
        ultimo = NULL;
    }
}

void lista::removeNoFim() {
    if (vazia())throw runtime_error("Remoção em lista vazia!");
    if (primeiro == ultimo) {
        delete primeiro;
        primeiro = NULL;
        ultimo = NULL;
    } else {
        noh* aux = primeiro;
        while (aux->proximo != ultimo) {
            aux = aux->proximo;
        }
        delete ultimo;
        ultimo = aux;
        ultimo->proximo = NULL;
    }
    tamanho--;
}

int main() {
    lista minhaLista;
    equipe info;
    char comando;
    int posicao;
    string nomeEquipe;

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoInicio(info);
                    break;
                case 'h': // inserir
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoFim(info);
                    break;             
                case 'm': // inserir
                    cin >> posicao;
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNaPosicao(posicao,info);
                    break;             
                case 's': // remover
                    cin >> nomeEquipe;
                    if(minhaLista.vazia()){
						cout << "Lista Vazia!" << endl;
					} else if (minhaLista.procura(nomeEquipe) != -1) {
						cout << minhaLista.procura(nomeEquipe) <<endl;
                    }
                    break;                    
                case 'r': // remover
                    minhaLista.removeNoInicio();
                    break;
                case 'a': // remover
                    minhaLista.removeNoFim();
                    break;                                   
                case 'p': // limpar tudo
                    minhaLista.imprime();
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cout << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    cout << endl;
    return 0;
}
