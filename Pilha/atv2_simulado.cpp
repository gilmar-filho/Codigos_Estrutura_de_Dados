#include <iostream>
using namespace std;

struct dado {
    int elemento;
    dado* proximo;
};


class pilha{
    private:
        dado *topo;
    public:
        pilha(){
            topo = NULL;
        }
        void empilha (dado entrada){
            dado *novo = new dado;
            *novo = entrada;
            novo->proximo = topo;
            topo = novo;
        }
        int desempilha(){
            if (topo == NULL) throw runtime_error("Pilha vazia!");
            int removido;
            dado *apagado = topo;
            removido = topo->elemento;
            topo = topo->proximo;
            apagado->proximo = NULL;
            delete apagado;
            return removido;
        }
        ~pilha(){
            while (topo != NULL)
                desempilha();
        }
        void inverte(){
            // FAÇA SEU CÓDIGO PARA INVERSÃO DA PILHA
            pilha aux1;
            dado auxDado = {0, NULL};

            while (this->topo != NULL){
                auxDado.elemento = this->desempilha();
                aux1.empilha(auxDado);
            }
            
            topo = aux1.topo;
            aux1.topo = NULL;

            //pilha aux2;

            /*bool teste = true;
            while (teste){
                try {
                    auxDado.elemento = aux1.desempilha();
                    aux2.empilha(auxDado);
                    //cout << "ok" << endl;
                } catch (const runtime_error& e) {
                    teste = false;
                    //cout << "parei" << endl;
                }
            }
            teste = true;
            while (teste){
                try {
                    auxDado.elemento = aux2.desempilha();
                    this->empilha(auxDado);
                    //cout << "ok" << endl;
                } catch (const runtime_error& e) {
                    teste = false;
                    //cout << "parei" << endl;
                }
            }*/
        }
        void imprime(){
            // FAÇA SEU CÓDIGO PARA IMPRESSÃO DA PILHA
            dado aux;
            while (this->topo != NULL){
                aux.elemento = this->desempilha();
                cout << aux.elemento << " ";
            }
            cout << endl;
        }
 };
 int main(){
    int tamanho;
    cin>> tamanho;
    dado entrada;
    pilha mp;
    for (int i=0; i<tamanho; i++){
        cin>>entrada.elemento;
        mp.empilha(entrada);
    }
    mp.inverte();
    mp.imprime();
    return 0;
 }