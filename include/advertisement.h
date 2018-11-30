/*
	File: advertisement.h
	Header file for class Advertisement 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Advertisement

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 29/11/2018
*/

#ifndef ADVERTISEMNT_H
#define ADVERTISEMNT_H

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <unistd.h>
// #include "../src/interface.cpp" // comment for using thread
#include "../src/list.cpp"

using namespace std;

class Advertisement {
	// Interface* adSystem; //comment for using thread
	List queue1;
	List queue2;
	Node* head_queue2;
	Node* tail_queue1;
	string adMessage;
	time_t currentTime;
	struct tm* tm_info;
	int adCount;
	int randomTime;
	string msg;
	char buffer_date[26];
  	char buffer_time[26];
	public: 	
		Advertisement();
		~Advertisement();
		void addAD();
		void insertIntoQueue1();
		void showAD();
		string removeAD();
};

#endif
