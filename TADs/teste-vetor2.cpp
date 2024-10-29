#include <iostream>
#include <cstdlib>
using namespace std;

struct vectorx {
    int* vetor;
    int tam;
};

void inicializa(vectorx* vec, int n){
    vec->vetor = new int[n];
    vec->tam = n;
}

void preenche(vectorx* vec){
    for (int i = 0; i < vec->tam;i++){
        vec->vetor[i] = rand() % 100;
    }
}

void finaliza(vectorx* vec){
    delete[] vec->vetor;
    vec->tam = 0;
}

void concatena(vectorx* vec1, vectorx* vec2, vectorx* vecFinal){
    vecFinal->tam = vec1->tam + vec2->tam;

    for (int i = 0; i < vec1->tam;i++){
        vecFinal->vetor[i] = vec1->vetor[i];
    }

    int j = 0;
    for (int i = vec1->tam; i < vecFinal->tam; i++){
        vecFinal->vetor[i] = vec2->vetor[j];
        j++;
    }
}

void imprime(vectorx* vec){
    for (int i = 0; i < vec->tam; i++){
        cout << vec->vetor[i] << " ";
    }
    cout << endl;
}

int main(){
    vectorx vec1, vec2, vec3;
    int tam1, tam2;

    cout << "Digite o tamanho dos dois vetores: ";
    cin >> tam1 >> tam2;

    inicializa(&vec1, tam1);
    inicializa(&vec2, tam2);
    inicializa(&vec3, tam1+tam2);

    preenche(&vec1);
    preenche(&vec2);

    concatena(&vec1, &vec2, &vec3);

    imprime(&vec1);
    imprime(&vec2);
    imprime(&vec3);

    finaliza(&vec1);
    finaliza(&vec2);
    finaliza(&vec3);
}