/*
    File: controller.cpp
    Implementation file for class Controller

    UFSC - EEL7323 - C++ Programming for Embedded Systems

    Project: Vending Machine
    Description: Class Controller is the definition for a controller 
    of the vending machine full state machine.  

    Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
    Github: https://github.com/kobarion/Vending-Machine

    Last changed in: 03/11/2018
*/

#include "../include/controller.h"

Controller::Controller(){
    state = 0;

    #ifdef sysPC
    system = new PC;
    #endif

    #ifdef sysRPi
    system = new RPi;
    #endif
}

Controller::~Controller(){
    delete system;
}

void Controller::nextState(){

    system -> displayMessage("\n1. M025    2. M050    3. M100\n4. DEV    5. ETIRPS    6. MEETS\n");

    input = system -> inputSystem();

    switch(state){
        case 0: 
            if (input == "nada") state = 0;
            else if (input == "dev") {
                system -> displayMessage("Devolve 0 creditos.");
                state = 0;
            }
            else if (input == "etirps") {
                system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "meets"){
            	system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "m025") {
                system -> displayMessage("25 creditos."); 
                state = 25;
            }
            else if (input == "m050") {
                system -> displayMessage("50 creditos."); 
                state = 50;
            }
            else if (input == "m100") {
                system -> displayMessage("100 creditos."); 
                state = 100;
            }
            break;
        case 25:
            if (input == "nada") state = 25;
            else if (input == "dev") {
                system -> displayMessage("Devolve 25 creditos."); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "meets"){
            	system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "m025"){
                system -> displayMessage("50 creditos."); 
                state = 50;
            }
            else if (input == "m050") {
                system -> displayMessage("75 creditos."); 
                state = 75;
            }
            else if (input == "m100") {
                system -> displayMessage("125 creditos."); 
                state = 125;
            }
            break;
        case 50:
            if (input == "nada") state = 50;
            else if (input == "dev") {
                system -> displayMessage("Devolve 50 creditos."); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "meets"){
            	system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "m025") {
                system -> displayMessage("75 creditos."); 
                state = 75;
            }
            else if (input == "m050") {
                system -> displayMessage("100 creditos."); 
                state = 100;
            }
            else if (input == "m100") {
                system -> displayMessage("150 creditos."); 
                state = 150;
            }
            break;
        case 75:
            if (input == "nada") state = 75;
            else if (input == "dev") {
                system -> displayMessage("Devolve 75 creditos."); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "meets"){
            	system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "m025") {
                system -> displayMessage("100 creditos."); 
                state = 100;
            }
            else if (input == "m050") {
                system -> displayMessage("125 creditos."); 
                state = 125;
            }
            else if (input == "m100") {
                system -> displayMessage("150 creditos. Devolve 25."); 
                state = 150;
            }      
            break;
        case 100:
            if (input == "nada") state = 100;
            else if (input == "dev") {
            	system -> displayMessage("Devolve 100 creditos."); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "meets"){
            	system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "m025") {
            	system -> displayMessage("125 creditos."); 
            	state = 125;
            }
            else if (input == "m050") {
            	system -> displayMessage("150 creditos."); 
            	state = 150;
            }
            else if (input == "m100") {
                system -> displayMessage("150 creditos. Devolve 50."); 
                state = 150;
            }
            break;
        case 125:
            if (input == "nada") state = 125;
            else if (input == "dev") {
            	system -> displayMessage("Devolve 125 creditos."); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "meets"){
            	system -> displayMessage("Creditos insuficientes."); 
            }
            else if (input == "m025") {
            	system -> displayMessage("150 creditos."); 
            	state = 150;
            }
            else if (input == "m050") {
                system -> displayMessage("150 creditos. Devolve 25.");             	
                state = 150;
            }
            else if (input == "m100") {
                system -> displayMessage("150 creditos. Devolve 50."); 
                state = 150;
            }
            break;
        case 150:
            if (input == "nada") state = 150;
            else if (input == "dev") {
            	system -> displayMessage("Devolve 150 creditos.");           	
                state = 0;
            }
            else if (input == "meets") {
            	system -> displayMessage("-MEET-");
                state = 0;
            }
            else if (input == "etirps") {
            	system -> displayMessage("-ETIRPS-");
                state = 0;
            }            
            else if (input == "m025") {
            	system -> displayMessage("150 creditos. Devolve 25."); 
                state = 150;
            }
            else if (input == "m050") {
            	system -> displayMessage("150 creditos. Devolve 50.");             	
                state = 150;
            }
            else if (input == "m100") {
            	system -> displayMessage("150 creditos. Devolve 100."); 
                state = 150;
            }
            break;
        default:
            break;
    }
}
