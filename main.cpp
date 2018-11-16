/*
	File: main.cpp

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Implementation of a C++ controller for a beverage vending machine.

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 03/11/2018
*/

// Choose which system to use
//#define sysPC // if using in PC (Linux)
 #define sysRPi // if using in RaspberryPi (ARM based system)

#include <iostream>
#include "src/controller.cpp"

using namespace std;

int main(){
	
    Controller vendingMachine;

    while(1){
		vendingMachine.nextState();
    }

    return 0;
}

