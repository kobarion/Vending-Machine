/*
	File: interface.h
	Header file for abstract class Interface 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Interface is the definition for an abstract class
	which deals with the machine interface for multiple systems.

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 22/11/2018
*/

#include <iostream>
#include <wiringPi.h>
#include <lcd.h>
using namespace std;

class Interface {
	protected:
		int inputChoice;
		string input;
		string ad;
	public:
		virtual void setupLCD() = 0;
		virtual void displayMessage(string) = 0;
		virtual void initMSG() = 0;
		virtual void creditMSG(int) = 0;
		virtual void autoReturnMSG(int) = 0;
		virtual void insufficientMSG() = 0;
		virtual void outputMSG(int) = 0;
		virtual void returnMSG(int) = 0;
		virtual string inputSystem() = 0;
		virtual string inputAD() = 0;
};

class RPi : public Interface {
		static const int ROW=4;
		static const int COL=20;
		static const int LCD_RS=11;
		static const int LCD_E=10;
		static const int LCD_D4=25;
		static const int LCD_D5=24;
		static const int LCD_D6=23;
		static const int LCD_D7=22;
		int lcd;
	public:
		void setupLCD();
		void displayMessage(string);
		string inputSystem();
		string inputAD();
		void initMSG();
		void creditMSG(int);
		void autoReturnMSG(int);
		void insufficientMSG();
		void outputMSG(int);
		void returnMSG(int);
};

class PC : public Interface {
	public:
		void displayMessage(string);
		string inputSystem();
		string inputAD();
		void initMSG();
		void creditMSG(int);
		void autoReturnMSG(int);
		void insufficientMSG();
		void outputMSG(int);
		void returnMSG(int);
};
