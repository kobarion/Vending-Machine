/*
	File: controller.h
	Header file for class Controller

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Controller is the definition for a controller 
	of the vending machine full state machine.  

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 03/11/2018
*/

#include <iostream>
#include "../src/interface.cpp"
using namespace std;

class Controller {
    int state;
    string input;
    Interface* system;
    public:
        Controller();
        ~Controller();
        void nextState();
};