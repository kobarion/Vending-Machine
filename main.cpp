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

bool flag = true;
char key;

Controller vendingMachine;
Advertisement ad_controller;

void ad(){
	while(1  && flag){
		ad_controller.showAD();
    }
}
void input(){
	while(1 && flag){
		cin >> key;
		if (key == 'c'){
			flag = false;
		}
	}
}

int main(){

	ad_controller.addAD();
	ad_controller.addAD();
	ad_controller.addAD();
	ad_controller.addAD();
	ad_controller.insertIntoQueue1();

	thread t1(ad);
	thread t2(input);

	while(1){
		if (!flag){
			vendingMachine.nextState();	
		}
		usleep(100*1000);

	}

    t1.join();
    t2.join();

    return 0;
}

