/*
	File: main_queue.cpp

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Test program for a queue using linked lists.
	Having the following operations:

	1. Inserts ad into queue 1.
	2. Inserts ad into queue 2.
	3. Removes ad from queue 1.
	4. Removes ad from queue 2.
	5. Reads address from the first and last element of the queue.
	6. Inserts queue 2 into queue 1's end.
	7. Inserts first element into queue's end.
	8. Lists all elements from both queues.
	9. Exits the program.

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 22/11/2018
*/

#include "../src/list.cpp"
#include "ad.cpp"


int main(){

	List fila1, fila2;
	Ad* ad;

	Node* head_queue2;
	Node* tail_queue1;

	int i;
	int opcao;
	string msg;
	bool sair = false;

	while(!sair){
		cout << "1. Inserir propaganda na fila 1" << endl;
		cout << "2. Inserir propaganda na fila 2" << endl;
		cout << "3. Remover propaganda da fila1" << endl;
		cout << "4. Remover propaganda da fila2" << endl;
		cout << "5. Ler endereco do primeiro e ultimo elemento da fila" << endl;
		cout << "6. Inserir fila 2 no final da fila1" << endl;
		cout << "7. Inserir primeiro elemento no final da fila" << endl;
		cout << "8. Listar todos" << endl;
		cout << "9. Sair do programa\n" << endl;
		cin >> opcao;

		switch(opcao){
			case 1:
				cout << "Mensagem da propaganda: ";
				cin.ignore();
				getline(cin, msg);
				cout << endl;
				ad = new Ad();
				ad -> setMsg(msg);
				fila1.insert(ad->getMsg());
 				break;
 			case 2:
				cout << "Mensagem da propaganda: ";
				cin.ignore();
				getline(cin, msg);
				cout << endl;
				ad = new Ad();
				ad -> setMsg(msg);
				fila2.insert(ad->getMsg());
 				break;
			case 3:
				cout << "propaganda: " << fila1.remove() << " removida\n" << endl;
				break;
			case 4:
				cout << "propaganda: " << fila2.remove() << " removida\n" << endl;
				break;
			case 5:
				cout << "Head (fila 1): " << fila1.readHead() << endl;
				cout << "Tail (fila 1): " << fila1.readTail() << endl;
				cout << "Head (fila 2): " << fila2.readHead() << endl;
				cout << "Tail (fila 2): " << fila2.readTail() << endl;
				break;
			case 6:
				cout << "Fila 2 inserida no final da fila 1" << endl;
				head_queue2 = fila2.readHead();
				tail_queue1 = fila1.readTail();
				fila1.insertAtEnd(tail_queue1, head_queue2);
				fila2.newHead();
				break;
			case 7:
				cout << "Primeiro elemento inserido no final da fila 1" << endl;
				msg = fila1.readFirst();
				cout << msg << endl;
				fila1.moveToEnd();
				break;
			case 8:
				cout << "Fila 1:" << endl;
				fila1.listAll();
				cout << "Fila 2:" << endl;
				fila2.listAll();
				break;
			case 9:
				sair = true;
				break;
			default:
				cout << "Nao existe essa opcao" << endl;
				break;
		}
	}

	return 0;
}

