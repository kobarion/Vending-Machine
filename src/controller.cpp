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
    system -> setup();
    system -> initMSG();
    #endif
}

Controller::~Controller(){
    delete system;
}

void Controller::nextState(){
    #ifdef sysPC
    system -> initMSG();
    #endif 
    
    input = system -> inputSystem();

    switch(state){
        case 0: 
            if (input == "nada") state = 0;
            else if (input == "dev") {
                system -> returnMSG(0);
                state = 0;
            }
            else if (input == "etirps") {
                system -> insufficientMSG(); 
            }
            else if (input == "meets"){
            	system -> insufficientMSG(); 
            }
            else if (input == "m025") {
                system -> creditMSG(25); 
                state = 25;
            }
            else if (input == "m050") {
                system -> creditMSG(50); 
                state = 50;
            }
            else if (input == "m100") {
                system -> creditMSG(100); 
                state = 100;
            }
            break;
        case 25:
            if (input == "nada") state = 25;
            else if (input == "dev") {
                system -> returnMSG(25); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> insufficientMSG(); 
            }
            else if (input == "meets"){
            	system -> insufficientMSG(); 
            }
            else if (input == "m025"){
                system -> creditMSG(50); 
                state = 50;
            }
            else if (input == "m050") {
                system -> creditMSG(75); 
                state = 75;
            }
            else if (input == "m100") {
                system -> creditMSG(125); 
                state = 125;
            }
            break;
        case 50:
            if (input == "nada") state = 50;
            else if (input == "dev") {
                system -> returnMSG(50); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> insufficientMSG(); 
            }
            else if (input == "meets"){
            	system -> insufficientMSG(); 
            }
            else if (input == "m025") {
                system -> creditMSG(75); 
                state = 75;
            }
            else if (input == "m050") {
                system -> creditMSG(100); 
                state = 100;
            }
            else if (input == "m100") {
                system -> creditMSG(150); 
                state = 150;
            }
            break;
        case 75:
            if (input == "nada") state = 75;
            else if (input == "dev") {
                system -> returnMSG(75); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> insufficientMSG(); 
            }
            else if (input == "meets"){
            	system -> insufficientMSG(); 
            }
            else if (input == "m025") {
                system -> creditMSG(100); 
                state = 100;
            }
            else if (input == "m050") {
                system -> creditMSG(125); 
                state = 125;
            }
            else if (input == "m100") {
                system -> autoReturnMSG(25); 
                state = 150;
            }      
            break;
        case 100:
            if (input == "nada") state = 100;
            else if (input == "dev") {
            	system -> returnMSG(100); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> insufficientMSG(); 
            }
            else if (input == "meets"){
            	system -> insufficientMSG(); 
            }
            else if (input == "m025") {
            	system -> creditMSG(125);  
            	state = 125;
            }
            else if (input == "m050") {
            	system -> creditMSG(150); 
            	state = 150;
            }
            else if (input == "m100") {
                system -> autoReturnMSG(50); 
                state = 150;
            }
            break;
        case 125:
            if (input == "nada") state = 125;
            else if (input == "dev") {
            	system -> returnMSG(125); 
                state = 0;
            }
            else if (input == "etirps") {
                system -> insufficientMSG(); 
            }
            else if (input == "meets"){
            	system -> insufficientMSG(); 
            }
            else if (input == "m025") {
            	system -> creditMSG(150); 
            	state = 150;
            }
            else if (input == "m050") {
                system -> autoReturnMSG(25);             	
                state = 150;
            }
            else if (input == "m100") {
                system -> autoReturnMSG(75); 
                state = 150;
            }
            break;
        case 150:
            if (input == "nada") state = 150;
            else if (input == "dev") {
            	system -> returnMSG(150);           	
                state = 0;
            }
            else if (input == "meets") {
            	system -> outputMSG(1);
                state = 0;
            }
            else if (input == "etirps") {
            	system -> outputMSG(0);
                state = 0;
            }            
            else if (input == "m025") {
            	system -> autoReturnMSG(25); 
                state = 150;
            }
            else if (input == "m050") {
            	system -> autoReturnMSG(50);             	
                state = 150;
            }
            else if (input == "m100") {
            	system -> autoReturnMSG(100); 
                state = 150;
            }
            break;
        default:
            break;
    }
}
