#include <iostream>
using namespace std;

class Documento {
    friend class Controle;
    private:
        string nomeMusica;
        string nomeCompositor;
        string estilo;
        string tipoDocumento;
    public:
        Documento();
        void cadastrarDocumento(string nMus, string nComp, string est, string tDoc);
        void imprimirDados();
        //string getEstilo(){return estilo} //Retorna o estilo do documento
};

Documento::Documento(){
    //Inicializa os atributos
}

void Documento::cadastrarDocumento(string nMus, string nComp, string est, string tDoc) {
    //Cadastra um novo documento
}

void Documento::imprimirDados(){
    //Imprime as informações de um documento
}

class Artista {
    friend class Controle;
    public:
        string nomeArtista;
        string tipoInstrumento;
        string estiloArtista;    
    private:
        Artista();
        void cadastrarArtista(string nArt, string tInstr, string estArt);
        //string getEstiloArtista(){return estiloArtista} //Retorna o estilo do artista/banda
        //void procurarDocumento();
        void imprimirArtista();
};

Artista::Artista(){
    //Inicializa os atributos
}

void Artista::cadastrarArtista(string nArt, string tInstr, string estArt){
    //Cadastra um novo artista/banda
}

void Artista::imprimirArtista(){
    //Imprime os dados de um Artista
}

class Controle {
    private:
        Documento* documentos;
        Artista* artistas;
        int tamArt, tamDoc;
        int capacidade;
        void redimencionarVetor(Documento &doc, Artista &art, int indice);
    public:
        Controle();
        Controle(int cap);
        void preencherArtista(string nArt, string tInstr, string estArt);
        void preencherDocumento(string nMus, string nComp, string est, string tDoc);
        void procurar(string estiloProcurado);
}

Controle::Controle(){
    //Inicializa os atributos e listas de objetos com capacidade 20
}

Controle::Controle(int cap){
    //Inicializa os atributos e listas de objetos com a capacidade descrita pelo
    //usuário
}

void Controle::preencherArtista(string nArt, string tInstr, string estArt){
    //Cadastra um novo artista. Caso não houver espaço no vetor, esse método chama 
    //redimensionarVetor(false)
}

void Controle::preencherDocumento(string nMus, string nComp, string est, string tDoc){
    //Cadastra um novo documento. Caso não houver espaço no vetor, esse método chama 
    //redimensionarVetor(true)
}

void Controle::procurar(string estiloProcurado){
    //Imprime os dados de todos os Documentos e Artistas relacionados com esse estilo
}

void Controle::redimencionarVetor(bool indice){
    //Redimenciona o vetor que precisar a partir do indice, adicionando mais 10 espaços. Como são apenas
    //dois vetores, uma variável booleana parece mais interessante. Dentro desse método deve haver um if...else
    //que verifique o indice e no caso TRUE redimencione o vetor de Documentos e no caso FALSE o vetor de Artistas.
    //Esse indice deve ser passado quando houver a necessidade de redimensionamento
}