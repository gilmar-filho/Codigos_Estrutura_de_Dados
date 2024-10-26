#include <iostream>
#include <string>
using namespace std;

class Especies{
    private:
        string mNome;
        string mPeriodoDePlantio;
        int mTempoDeProducao;
    public:
        Especies(string mNome, string mPeriodoDePlantio, int mTempoDeProducao);
        // Especies();
        // void cadastrarEspecie(string nome, string periodo, int tempo);
        void mostrarEspecie();
};

Especies::Especies(string mNome, string mPeriodoDePlantio, int mTempoDeProducao){
    this->mNome = mNome;
    this->mPeriodoDePlantio = mPeriodoDePlantio;
    this->mTempoDeProducao = mTempoDeProducao;
}

// Especies::Especies(){
//     mNome = ' ';
//     mPeriodoDePlantio = ' ';
//     mTempoDeProducao = 0;
// }

// void Especies::cadastrarEspecie(string nome, string periodo, int tempo){
//     mNome = nome;
//     mPeriodoDePlantio = periodo;
//     mTempoDeProducao = tempo;
// }

void Especies::mostrarEspecie(){
    // Todos os dados da espécie devem ser mostrados na tela
}


class Fornecedor{
    private:
        string mNome;
        string mProdutoDeInteresse;
        int telefoneDeContato;
    public:
        Fornecedor(string nome, string produto, int telefone);
        // Fornecedor();
        // void cadastrarFornecedor(string mNome, string mProdutoDeInteresse, int telefoneDeContato);
        string *buscarFornecedoresPorProduto(const string& produto);
        void mostrarFornecedor();
};

Fornecedor::Fornecedor(string nome, string produto, int telefone){
    mNome = nome;
    mProdutoDeInteresse = produto;
    telefoneDeContato = telefone;
}

// Fornecedor::Fornecedor(){
//     mNome = ' ';
//     mProdutoDeInteresse = ' ';
//     telefoneDeContato = 0;
// }

// void Fornecedor::cadastrarFornecedor(string mNome, string mProdutoDeInteresse, int telefoneDeContato){
//     this->mNome = mNome;
//     this->mProdutoDeInteresse = mProdutoDeInteresse;
//     this->telefoneDeContato = telefoneDeContato;
// }

string *Fornecedor::buscarFornecedoresPorProduto(const string& produto){
    // Deve retornar um vetor de strings com os nomes dos fornecedores para um produto específico
}

void Fornecedor::mostrarFornecedor(){
    // Todos os dados do fornecedor devem ser mostrados na tela
}