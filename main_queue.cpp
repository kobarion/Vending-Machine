/*
	File main.cpp

	- Alterar val -> cliente
	1. Inserir cliente na fila
	2. Remover cliente da fila
	3. Sair do programa

	* Criar classe cliente
	* Ao inserir na fila solicitar o numero do cliente
	* Ao remover da fila, mostrar mensagem atendendo cliente: X

*/
#include <sys/time.h>
#include <sys/resource.h>
#include "src/list.cpp"
#include "ad.cpp"


int main(){


	List fila;
	Ad* ad;

	int i;
	int opcao;
	string msg;
	bool sair = false;

	while(!sair){
		cout << "1. Inserir propaganda na fila" << endl;
		cout << "2. Remover propaganda da fila" << endl;
		cout << "3. Sair do programa\n" << endl;
		cin >> opcao;

		switch(opcao){
			case 1:
				cout << "Mensagem da propaganda: ";
				cin.ignore();
				getline(cin, msg);
				cout << endl;
				ad = new Ad();
				ad -> setMsg(msg);
				fila.insert(ad->getMsg());
 				break;
			case 2:
				cout << "propaganda: " << fila.remove() << " removida\n" << endl;
				break;
			case 3:
				sair = true;
				break;
			default:
				cout << "Nao existe essa opcao" << endl;
				break;
		}
	}

	return 0;
}

