#include <iostream>
using namespace std;

class Documento {
    private:
        string musica;
        string compositor;
        string estilo;
        string tipoDocumento;
        Artista *artistas;
        int capacidade;
        int tamanho;
        void redimensionarVetorArtistas();
    public:
        Documento();
        void cadastrarDocumento(string m, string c, string e, string tD) :
                    musica (m), compositor (c), estilo (e), tipoDocumento (tD) {}
        void cadastrarArtista();
        string getEstilo() {return estilo}
        void imprimirDocumento();
        void procurarEstilo();
}

Documento::Documento(){
    //Inicializa todos os atributos com valores nulos e o vetor de Artistas com capacidade 10
}

void Documento::cadastrarArtista(){
    //Esse método solicita ao usuário para digitar os dados de um artista e 
}

void Documento::imprimirDocumento(){
    //Imprime todos os dados de um documento
}

void Documento::procurarEstilo(){
    //Imprime os dados de uma partitura/tablatura/cifra e todos os artistas que estão relacionados
}

void Documento::redimensionarVetorArtistas(){
    //Quando o vetor de Artistas enche, esse método é chamado para aumentar em 10 a capacidade do vetor
}

class Artista {
    private:
        string nome;
        string tipoInstrumento;
        string estilo;  
    public:

}