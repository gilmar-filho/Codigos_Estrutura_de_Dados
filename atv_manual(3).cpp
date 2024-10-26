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
        ~Controle();
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

Controle::~Controle(){
    //Desaloca todos os espaços de memória dedicados aos vetores e zera os valores dos
    //atributos tamArt, tamDoc e capacidade
}

void Controle::preencherArtista(string nArt, string tInstr, string estArt){
    //Cadastra um novo artista e acrescenta um à tamArt. Caso não houver espaço no vetor, esse método chama 
    //redimensionarVetor(false)
}

void Controle::preencherDocumento(string nMus, string nComp, string est, string tDoc){
    //Cadastra um novo documento e acrescenta um à tamDoc. Caso não houver espaço no vetor, esse método chama 
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