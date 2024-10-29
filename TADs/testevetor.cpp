#include <iostream>
#include <cstdlib>
using namespace std;

struct vector {
    int* vec;
    int tam;
};

void inicializa(vector* vetor, int n){
    vetor->vec = new int [n];
    vetor->tam = n;
}

void finaliza(vector* vetor){
    delete[] vetor->vec;
    vetor->tam = 0;
}

void preenche(vector* vetor){
    for(int i = 0; i < vetor->tam;i++){
        vetor->vec[i] = rand() % 100;
    }
}

void concatena(vector* vetor1, vector* vetor2, vector* vetorFinal){
    vetorFinal-> tam = vetor1->tam + vetor2->tam;

    for (int i = 0; i < vetor1->tam; i++){
        vetorFinal->vec[i] = vetor1->vec[i];
    }

    int j = 0;
    for (int i = vetor1->tam; i < vetorFinal->tam;i++){
        vetorFinal->vec[i] = vetor2->vec[j];
        j++;
    }
}

void imprime(vector* vetor){
    for (int i = 0; i < vetor->tam;i++){
        cout << vetor->vec[i] << " ";
    }
    cout << endl;
}

int main(){
    vector vec1, vec2, vec3;
    int tam1, tam2;

    cout << "Digite os tamanhos dos vetores: ";
    cin >> tam1 >> tam2;

    srand(time(NULL));

    inicializa(&vec1, tam1);
    inicializa(&vec2, tam2);
    inicializa(&vec3, tam1+tam2);

    preenche(&vec1);
    imprime(&vec1);

    preenche(&vec2);
    imprime(&vec2);

    concatena(&vec1, &vec2, &vec3);
    imprime(&vec3);
}