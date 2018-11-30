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
#define sysPC // if using in PC (Linux)
// #define sysRPi // if using in RaspberryPi (ARM based system)

#include <iostream>
#include <thread>
#include "src/controller.cpp"
#include "src/advertisement.cpp"

using namespace std;

Controller vendingMachine;
Advertisement ad_controller;

void ad(){
	while(1){
		ad_controller.showAD();
    }
}

int main(){
	ad_controller.addAD();
    ad_controller.addAD();
    ad_controller.addAD();
    ad_controller.addAD();
    ad_controller.insertIntoQueue1();

	thread t1(ad);

    while(1){
		vendingMachine.nextState();
    }

    t1.join();

    return 0;
}

