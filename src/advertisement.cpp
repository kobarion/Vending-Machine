/*
	File: advertisement.cpp
	Implementation file for class Advertisement 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Advertisement

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 22/11/2018
*/

#include "../include/advertisement.h"

Advertisement::Advertisement(){
	time(&previousTime);
	resetRandom = false;

	adCount = 0;

	srand (time(NULL));
	randomTime = rand() % 3 + 3;

	#ifdef sysPC
    system = new PC;
    #endif

    #ifdef sysRPi
    system = new RPi;
    #endif
}

Advertisement::~Advertisement(){
    delete system;
}

void Advertisement::showAD(){
	time(&currentTime);
	if (resetRandom) {
		srand (time(NULL));
		randomTime = rand() % 3 + 3;
	}

	if (difftime(currentTime,previousTime) > 1) {
		if (adCount == randomTime) {
			adCount = 0;
			resetRandom = true;
			time(&previousTime);
			system->displayMessage(asctime(localtime(&previousTime)));
		} else {
			adCount++;
			msg = queue1.readFirst();
			system->displayMessage(msg);
			queue1.moveToEnd();
		}
	}
}

void Advertisement::addAD(){
	adMessage = system -> inputAD();
	queue2.insert(adMessage);
}

void Advertisement::insertIntoQueue1(){
	head_queue2 = queue2.readHead();
	tail_queue1 = queue1.readTail();
	queue1.insertAtEnd(tail_queue1, head_queue2);
	queue2.newHead();
}

string Advertisement::removeAD(){
	return queue1.remove();
}