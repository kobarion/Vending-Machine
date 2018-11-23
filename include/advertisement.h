/*
	File: advertisement.h
	Header file for class Advertisement 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Advertisement

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 22/11/2018
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../src/interface.cpp"
#include "../src/list.cpp"

using namespace std;

class Advertisement {
	Interface* system;
	List queue1;
	List queue2;
	Node* head_queue2;
	Node* tail_queue1;
	string adMessage;
	time_t currentTime;
	time_t previousTime;
	bool resetRandom;
	int adCount;
	int randomTime;
	string msg;
	public: 	
		Advertisement();
		~Advertisement();
		void addAD();
		void insertIntoQueue1();
		void showAD();
		string removeAD();
};