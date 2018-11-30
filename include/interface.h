/*
	File: interface.h
	Header file for abstract class Interface 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Interface is the definition for an abstract class
	which deals with the machine interface for multiple systems.

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 29/11/2018
*/
#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#ifdef sysRPi
#include <wiringPi.h>
#include <lcd.h>
#endif
using namespace std;

class Interface {
	protected:
		int inputChoice;
		string input;
		string ad;
	public:
		virtual void setup() = 0;
		virtual void initMSG() = 0;
		virtual void creditMSG(int) = 0;
		virtual void autoReturnMSG(int) = 0;
		virtual void insufficientMSG() = 0;
		virtual void outputMSG(int) = 0;
		virtual void returnMSG(int) = 0;
		virtual void displayAD(string) = 0;
		virtual void displayDateTime(string, string) = 0;
		virtual string inputSystem() = 0;
		virtual string inputAD() = 0;
};
#ifdef sysRPi
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
		void setup();
		string inputSystem();
		string inputAD();
		void displayAD(string);
		void displayDateTime(string, string);
		void initMSG();
		void creditMSG(int);
		void autoReturnMSG(int);
		void insufficientMSG();
		void outputMSG(int);
		void returnMSG(int);
};
#endif

class PC : public Interface {
	public:
		void setup();
		string inputSystem();
		string inputAD();
		void displayAD(string);
		void displayDateTime(string, string);
		void initMSG();
		void creditMSG(int);
		void autoReturnMSG(int);
		void insufficientMSG();
		void outputMSG(int);
		void returnMSG(int);
};

#endif