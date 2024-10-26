#include <iostream>
#include <cstdlib>
using namespace std;

class vectorx {
    private:
        int* vetor;
        int tam;
    public:
        //contrutores e destrutor
        vectorx();
        vectorx(int n);
        ~vectorx();

        //métodos
        void preenche();
        void concatena (vectorx* vec1, vectorx* vec2);
        void imprime();
};

vectorx::vectorx(){
    tam = 10;
    vetor = new int[tam];
}

vectorx::vectorx(int n){
    vetor = new int[n];
    tam = n;
}

void vectorx::preenche(){
    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 100;
    }
}

vectorx::~vectorx(){
    delete[] vetor;
    tam = 0;
}

void vectorx::concatena (vectorx* vec1, vectorx* vec2){
    for (int i = 0; i < vec1->tam; i++){
        vetor[i] = vec1->vetor[i];
    }

    int j = 0;
    for (int i = vec1->tam; i < tam; i++){
        vetor[i] = vec2->vetor[j];
        j++;
    }
}

void vectorx::imprime(){
    for (int i = 0; i < tam; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main(){
    int tam1, tam2;

    cout << "Digite o tamanho dos vetores: ";
    cin >> tam1 >> tam2;

    srand(time(NULL));

    vectorx vec1(tam1);
    vectorx vec2;
    vectorx vec3(tam1+10);

    vec1.preenche();
    vec2.preenche();

    vec3.concatena(&vec1, &vec2);

    vec1.imprime();
    vec2.imprime();
    vec3.imprime();
}
