#include <iostream>
using namespace std;

class Livro{
    private:
        string titulo;
        string autor;
        long isbn;
    public:
        Livro();
        void cadastrar(string t, string a, long c);
        string getTitulo();
        string getDados();
};

Livro::Livro(){
    this->titulo = "";
    this->autor = "";
    this->isbn = 0;
}

void Livro::cadastrar(string t, string a, long c){
    titulo = t;
    autor = a;
    isbn = c;
}

string Livro::getTitulo(){
    return titulo;
}

string Livro::getDados(){
    string c = to_string(isbn);
    return titulo + "\n" + autor + "\n" + c;
}

class Biblioteca{
    private:
        Livro *livros;
        int capacidade;
        int tamanho;
    public:
        Biblioteca();
        Biblioteca(int c);
        ~Biblioteca();
        int getCapacidade();
        int getTamanho();
        void cadastrarLivro(string t, string a, long c);
        bool procurarLivro(string t);
};

Biblioteca::Biblioteca(){
    livros = new Livro[10];
    capacidade = 10;
    tamanho = 0;
}

Biblioteca::Biblioteca(int c){
    livros = new Livro[c];
    capacidade = c;
    tamanho = 0;
}

int Biblioteca::getCapacidade(){
    return capacidade;
}

int Biblioteca::getTamanho(){
    return tamanho;
}

void Biblioteca::cadastrarLivro(string t, string a, long c){
    livros[tamanho].cadastrar(t,a,c);
    tamanho++;
}

bool Biblioteca::procurarLivro(string t){
    for (int i = 0; i < tamanho; i++){
        if (livros[i].getTitulo() == t){
            cout << livros[i].getDados() << endl;
            return true;
        }
    }
    return false;
}

Biblioteca::~Biblioteca(){
    delete[] livros;
    capacidade = 0;
    tamanho = 0;
}

int menu(){
    int opcao;
    cout << "Escolha uma opção abaixo\n" << "1- Cadastrar livro\n" 
        << "2- Buscar Livro\n" << "0- Sair\n" << "Digite sua opção: ";

    cin >> opcao;
    return opcao;  
}

int main(){
    int c;
    cout << "Digite a capacidade da sua biblioteca:";
    cin >> c;

    Biblioteca acervo(c);

    int opcao;

    do {
        switch (opcao = menu()){
        case 1: {
            if (acervo.getTamanho() < acervo.getCapacidade()){
                string t, a;
                long c;
                cout << "Titulo: ";
                cin >> t;
                cout << "Autor: ";
                cin >> a;
                cout << "ISBN: ";
                cin >> c;

                acervo.cadastrarLivro(t,a,c);

                cout << "Livro cadastrado com sucesso!!!" << endl;
            } else {
                cout << "Biblioteca cheia!!!" << endl;
            }
            
            break; 
        }
        case 2: {
            string t1;
            cout << "Título procurado: ";
            cin >> t1;

            if (!acervo.procurarLivro(t1)) 
                cout << "Livro não encontrado!!!" << endl;

            break;
        }
        default:
            cout << "Até Mais!!!" << endl;
            break;
        }
    } while (opcao != 0);

    return 0;
}

/*int main() {
    int capacidade;
    cout << "Digite a capacidade da sua biblioteca (se não digitar nenhum valor, a biblioteca terá capacidade 10): ";
    
    // Verifica se a entrada de capacidade foi válida
    cin >> capacidade;

    Biblioteca acervo(capacidade);

    int opcao = menu();

    do {
        switch (opcao) {
        case 1: {
            if (acervo.getTamanho() < acervo.getCapacidade()) {
                string titulo, autor;
                long isbn;

                cin.ignore();  // Limpa o buffer antes de ler strings
                cout << "Titulo: ";
                getline(cin, titulo);  // Lê a linha inteira, permitindo espaços

                cout << "Autor: ";
                getline(cin, autor);  // Lê a linha inteira

                cout << "ISBN: ";
                cin >> isbn;

                acervo.cadastrarLivro(titulo, autor, isbn);
                cout << "Livro cadastrado com sucesso!!!" << endl;
            } else {
                cout << "Biblioteca cheia!!!" << endl;
            }
            break;
        }

        case 2: {
            string titulo;
            cin.ignore();  // Limpa o buffer antes de ler strings
            cout << "Título procurado: ";
            getline(cin, titulo);  // Lê a linha inteira

            if (!acervo.procurarLivro(titulo)) {
                cout << "Livro não encontrado!!!" << endl;
            }
            break;
        }

        default:
            cout << "Até Mais!!!" << endl;
            break;
        }

        opcao = menu();  // Pede nova opção
    } while (opcao != 0);

    return 0;
}*/

