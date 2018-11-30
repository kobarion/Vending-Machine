/*
	File: advertisement.cpp
	Implementation file for class Advertisement 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Advertisement

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 29/11/2018
*/

#include "../include/advertisement.h"

Advertisement::Advertisement(){
	adCount = 0;
	
	srand(time(NULL));
	randomTime = rand() % 4 + 3;

	 // #ifdef sysPC				//comment for using thread
	 // adSystem = new PC;
	 // #endif
	
	 // #ifdef sysRPi
	 // adSystem = new RPi;
	 // adSystem -> setup();
	 // #endif					//comment for using thread
}

Advertisement::~Advertisement(){
     // delete adSystem;			//comment for using thread
}

void Advertisement::showAD(){

	usleep(1000*1000);

	if (adCount == randomTime) {
		adCount = 0;
		srand(time(NULL));
		randomTime = rand() % 4 + 3;
		time(&currentTime);
		tm_info = localtime(&currentTime);
		strftime(buffer_date, 26, "Date: %m/%d/%Y", tm_info);
		strftime(buffer_time, 26, "Time: %H:%M:%S", tm_info);
		// adSystem->displayDateTime(buffer_time, buffer_date);  //comment for using thread	 
		cout << buffer_date << endl; 			// thread
		cout << buffer_time << endl; 			// thread
	} else if (adCount != randomTime){
		msg = queue1.readFirst();
		// adSystem->displayAD(msg);				// comment for using thread
		cout << msg << endl;					//thread
		queue1.moveToEnd();
		adCount++;
	}
}

void Advertisement::addAD(){
	// adMessage = adSystem -> inputAD();		// comment for using threads
	cout << "Mensagem da propaganda (PC): "; 	// thread
	getline(cin, adMessage);			// thread
	cout << endl;				 	// thread
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
