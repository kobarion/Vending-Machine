#include <iostream>

using namespace std;

class Controlador {
    int state;
    public:
        Controlador();
        ~Controlador();
        void nextState(string input);
};

Controlador::Controlador(){
    state = 0;
}

Controlador::~Controlador(){}

void Controlador::nextState(string input){
	
    switch(state){
        case 0: 
            if (input == "nada") state = 0;
            else if (input == "dev") {
                cout << "Devolve 0 creditos." << endl;
                state = 0;
            }
            else if (input == "etirps") {
                cout << "Creditos insuficientes." << endl;
            }
            else if (input == "meets"){
            	cout << "Creditos insuficientes." << endl;
            }
            else if (input == "m025") {
                cout << "25 creditos." << endl;
                state = 25;
            }
            else if (input == "m050") {
                cout << "50 creditos." << endl;
                state = 50;
            }
            else if (input == "m100") {
                cout << "100 creditos." << endl;
                state = 100;
            }
            break;
        case 25:
            if (input == "nada") state = 25;
            else if (input == "dev") {
                cout << "Devolve 25 creditos." << endl;
                state = 0;
            }
            else if (input == "etirps") {
                cout << "Creditos insuficientes." << endl;
            }
            else if (input == "meets"){
            	cout << "Creditos insuficientes." << endl;
            }
            else if (input == "m025"){
                cout << "50 creditos." << endl;
                state = 50;
            }
            else if (input == "m050") {
                cout << "75 creditos." << endl;
                state = 75;
            }
            else if (input == "m100") {
                cout << "125 creditos." << endl;
                state = 125;
            }
            break;
        case 50:
            if (input == "nada") state = 50;
            else if (input == "dev") {
                cout << "Devolve 50 creditos." << endl;
                state = 0;
            }
            else if (input == "etirps") {
                cout << "Creditos insuficientes." << endl;
            }
            else if (input == "meets"){
            	cout << "Creditos insuficientes." << endl;
            }
            else if (input == "m025") {
                cout << "75 creditos." << endl;
                state = 75;
            }
            else if (input == "m050") {
                cout << "100 creditos." << endl;
                state = 100;
            }
            else if (input == "m100") {
                cout << "150 creditos." << endl;
                state = 150;
            }
            break;
        case 75:
            if (input == "nada") state = 75;
            else if (input == "dev") {
                cout << "Devolve 75 creditos." << endl;
                state = 0;
            }
            else if (input == "etirps") {
                cout << "Creditos insuficientes." << endl;
            }
            else if (input == "meets"){
            	cout << "Creditos insuficientes." << endl;
            }
            else if (input == "m025") {
                cout << "100 creditos." << endl;
                state = 100;
            }
            else if (input == "m050") {
                cout << "125 creditos." << endl;
                state = 125;
            }
            else if (input == "m100") {
                cout << "150 creditos. Devolve 25." << endl;
                state = 150;
            }      
            break;
        case 100:
            if (input == "nada") state = 100;
            else if (input == "dev") {
            	cout << "Devolve 100 creditos." << endl;
                state = 0;
            }
            else if (input == "etirps") {
                cout << "Creditos insuficientes." << endl;
            }
            else if (input == "meets"){
            	cout << "Creditos insuficientes." << endl;
            }
            else if (input == "m025") {
            	cout << "125 creditos." << endl;
            	state = 125;
            }
            else if (input == "m050") {
            	cout << "150 creditos." << endl;
            	state = 150;
            }
            else if (input == "m100") {
                cout << "150 creditos. Devolve 50." << endl;
                state = 150;
            }
            break;
        case 125:
            if (input == "nada") state = 125;
            else if (input == "dev") {
            	cout << "Devolve 125 creditos." << endl;
                state = 0;
            }
            else if (input == "etirps") {
                cout << "Creditos insuficientes." << endl;
            }
            else if (input == "meets"){
            	cout << "Creditos insuficientes." << endl;
            }
            else if (input == "m025") {
            	cout << "150 creditos." << endl;
            	state = 150;
            }
            else if (input == "m050") {
                cout << "150 creditos. Devolve 25." << endl;            	
                state = 150;
            }
            else if (input == "m100") {
                cout << "150 creditos. Devolve 50." << endl;
                state = 150;
            }
            break;
        case 150:
            if (input == "nada") state = 150;
            else if (input == "dev") {
            	cout << "Devolve 150 creditos." << endl;            	
                state = 0;
            }
            else if (input == "meets") {
            	cout << "-MEET-" << endl;
                state = 0;
            }
            else if (input == "etirps") {
            	cout << "-ETIRPS-" << endl;
                state = 0;
            }            
            else if (input == "m025") {
            	cout << "150 creditos. Devolve 25." << endl;
                state = 150;
            }
            else if (input == "m050") {
            	cout << "150 creditos. Devolve 50." << endl;            	
                state = 150;
            }
            else if (input == "m100") {
            	cout << "150 creditos. Devolve 100." << endl;
                state = 150;
            }
            break;
        default:
            break;
    }
}
