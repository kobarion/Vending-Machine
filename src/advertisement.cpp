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
	adCount = 0;

	// srand (time(NULL));
	randomTime = rand() % 4 + 3;

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

	usleep(1000*1000);

	if (adCount == randomTime) {
		adCount = 0;
		// srand (time(NULL));
		randomTime = rand() % 4 + 3;
		time(&currentTime);
		system->displayMessage(asctime(localtime(&currentTime)));
	} else if (adCount != randomTime){
		msg = queue1.readFirst();
		system->displayMessage(msg);
		queue1.moveToEnd();
		adCount++;
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
