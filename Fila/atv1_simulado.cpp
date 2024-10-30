#include <iostream>
using namespace std;

struct dado{
	string nome = "vazio";
	string tipo;
	dado *proximo;
};

class fila{
	private:
		dado *inicio;
		dado *fim;
	public:
		fila(){
			inicio = NULL;
			fim = NULL;			
		}
		void enfileirar (dado entrada){
			dado *novo = new dado;
			*novo = entrada;
			if (fim != NULL)
				fim->proximo = novo;
			else
				inicio = novo;
			fim = novo;
		}
		dado desenfileirar(){
			if (inicio == NULL){
				return dado{"", "", NULL};
			}// throw runtime_error("Fila vazia!");
			dado *retornado = new dado;
			dado *removido = inicio;
			if (inicio == fim)
				fim = NULL;
			retornado->nome = inicio->nome;
			retornado->tipo = inicio->tipo;
			inicio = inicio->proximo;
			removido->proximo = NULL;
			delete removido;
			return *retornado;
		}
		~fila(){
			while (inicio != NULL)
				desenfileirar();
		}
		bool vazia(){ return (inicio == NULL); }
		/*dado atendimento (string tipo){
		    // FAÇA SEU CÓDIGO AQUI
			fila aux;
			dado retorno = {"", "", NULL};
			dado auxDado;
			do {
				auxDado = this->desenfileirar();
				if (auxDado.tipo != tipo) aux.enfileirar(auxDado);
				if ((retorno.proximo != NULL) and (auxDado.tipo == tipo)) retorno = auxDado;
			} while (not this->vazia());

			while (aux.getInicio() != NULL){
				this->enfileirar(aux.desenfileirar());
			}

			if (this->inicio == NULL){
				return dado{"", "", NULL};
			} else {
				return retorno;
			}
		return retorno;
		}*/
};
		int main(){
			fila filaNormal, filaPrioridade, filaAtendidos;
			string comando,tipo;
			dado entrada, atendido;
			int contadorPrioridade = 0;
			cin>>comando;
			while (comando != "fim"){
					if (comando == "normal"){
						cin>>entrada.nome;
						entrada.tipo = "normal";
						filaNormal.enfileirar(entrada);
					} else if (comando == "prioridade"){
						cin>>entrada.nome;
						entrada.tipo = "prioridade";
						filaPrioridade.enfileirar(entrada);
					} else if (comando == "atender"){
						//COMPLETE AQUI
						/*dado atendimento = banco.atendimento("prioridade");
						if (atendimento.proximo != NULL){
							cout << atendimento.nome << endl;
						} else {
							atendimento = banco.atendimento("normal");
							if (atendimento.proximo != NULL) cout << atendimento.nome << endl;
							else cout << "AGUARDE" << endl;
						}*/
						if ((contadorPrioridade < 3) and (not filaPrioridade.vazia())){
							atendido = filaPrioridade.desenfileirar();
							if (atendido.nome != ""){
								filaAtendidos.enfileirar(atendido);
							}
							contadorPrioridade++;
						} else if ((contadorPrioridade == 3) and (not filaNormal.vazia())){
							atendido = filaNormal.desenfileirar();
							if (atendido.nome != ""){
								filaAtendidos.enfileirar(atendido);
							}
							contadorPrioridade = 0;
						} else {
							atendido = {"AGUARDE", "", NULL};
							filaAtendidos.enfileirar(atendido);
						}
					}
					cin>>comando;
			}

			while (not filaAtendidos.vazia()){
				cout << filaAtendidos.desenfileirar().nome << endl;
			}
	return 0;
}