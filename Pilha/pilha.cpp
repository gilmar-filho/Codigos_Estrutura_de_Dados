// pilha.cpp
#include "pilha.hpp"
#include <iostream>

// Implementação de noh
noh::noh(string nome, char tipo, int valor) {
    mDados.mNome = nome;
    mDados.mTipo = tipo;
    mDados.mValor = valor;
    mAnterior = NULL;
}

void noh::setAnterior(noh* anterior) {
    mAnterior = anterior;
}

string noh::getNome() {
    return mDados.mNome;
}

char noh::getTipo() {
    return mDados.mTipo;
}

int noh::getValor() {
    return mDados.mValor;
}

noh* noh::getAnterior() {
    return mAnterior;
}

// Implementação de pilha
pilha::pilha() {
    mTopo = NULL;
    tamanho = 0;
}

pilha::~pilha() {
    limparPilha();
}

bool pilha::vazia() {
    return (mTopo == NULL);
}

void pilha::limparPilha() {
    while (not vazia()) {
        desempilha();
    }
}

void pilha::empilha(string nome, char tipo, int valor) {
    noh* novo = new noh(nome, tipo, valor);
    novo->setAnterior(mTopo);
    mTopo = novo;
    tamanho++;
}

string pilha::desempilha() {
    if (vazia()) {
        return "Erro: pilha vazia";
    } else {
        noh* aux = mTopo;
        string saida = "Nome: " + aux->getNome() + " Tipo: " + aux->getTipo() + " Valor: " + to_string(aux->getValor());
        mTopo = aux->getAnterior();
        delete aux;
        tamanho--;
        return saida;
    }
}

string pilha::getTopo() {
    if (!vazia()) {
        return "Nome: " + mTopo->getNome() + " Tipo: " + mTopo->getTipo() + " Valor: " + to_string(mTopo->getValor());
    } else {
        return "Erro: pilha vazia";
    }
}

int pilha::getTamanho() {
    return tamanho;
}
