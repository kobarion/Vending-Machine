#include <iostream>
#include "controlador.cpp"
using namespace std;

string inputDecoder(int i);

int main(){

    int input;
    string stateInput;
    Controlador vendingMachine;

    while(1){
    	cout << "\n1. M025" << endl << "2. M050" << endl << "3. M100" << endl;
    	cout << "4. DEV" << endl << "5. ETIRPS" << endl << "6. MEET\n" << endl;
    	cout << "input: ";
	cin >> input;

    	stateInput = inputDecoder(input);

	vendingMachine.nextState(stateInput);
    }
}

string inputDecoder(int i){

	string input;

	switch(i){
		case 1:
			input = "m025";
			break;
		case 2:
			input = "m050";
			break;
		case 3:
			input = "m100";
			break;
		case 4:
			input = "dev";
			break;
		case 5:
			input = "etirps";
			break;
		case 6:
			input = "meets";
			break;
		default:
			input = "nada";
			break;
	}
	
	return input;
}
