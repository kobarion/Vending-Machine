/*
	File: interface.cpp
	Implementation file for abstract class Interface 

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Interface is the definition for an abstract class
	which deals with the machine interface for multiple systems.

	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 22/11/2018
*/

#include "../include/interface.h"

void PC::setup(){
}

void PC::displayAD(string msg){
	cout << msg << endl;
}

void PC::initMSG(){
	cout << "\n1. M025    2. M050    3. M100" << endl
		 << "4. DEV    5. ETIRPS    6. MEET" << endl;
}

void PC::creditMSG(int amount){
	cout << "Amount: " << amount << endl;
}

void PC::autoReturnMSG(int amount){
	cout << "Amount: 150" << endl
		 << "Return: " << amount << endl;
}

void PC::insufficientMSG(){
	cout << "Insufficient amount" << endl;
}

void PC::outputMSG(int soda){
	if (soda == 0){
		cout << "ETIRPS selected" << endl;
	} else if (soda == 1){
		cout << "MEET selected" << endl;
	}
}

void PC::returnMSG(int amount){
	cout << "Return: " << amount << endl;
}

string PC::inputSystem(){
	cin >> inputChoice;
	switch(inputChoice){
		case 1:
			input = "m025";
			break;
		case 2:
			input = "m050";
			break;
		case 3:
			input = "m100";
			break;
		case 4:
			input = "dev";
			break;
		case 5:
			input = "etirps";
			break;
		case 6:
			input = "meets";
			break;
		default:
			input = "nada";
			break;
	}
	return input;
}

string PC::inputAD(){
	cout << "Mensagem da propaganda (PC): ";
	getline(cin, ad);
	cout << endl;
	return ad;
}

void PC::displayDateTime(string time, string date){
	cout << date << endl;
	cout << time << endl;
}

/* ------------------------------------------------ */
#ifdef sysRPi
void RPi::setup(){
    wiringPiSetup();
    lcd = lcdInit (ROW, COL, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
}

void RPi::initMSG(){
	lcdClear(lcd);
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "       INSERT       ");
	lcdPosition(lcd, 0, 2);
	lcdPuts(lcd, "        COIN        ");
}

void RPi::creditMSG(int amount){
	lcdClear(lcd);
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "   AMOUNT: ");
	switch(amount){
		case 0:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.00");
			break;
		case 25:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.25");
			break;
		case 50:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.50");
			break;
		case 75:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.75");
			break;
		case 100:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "1.00");
			break;
		case 125:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "1.25");
			break;
		case 150:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "1.50");
			break;
	}
}

void RPi::autoReturnMSG(int amount){
	lcdClear(lcd);
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "   AMOUNT: 1.50");
	lcdPosition(lcd, 0, 2);
	lcdPuts(lcd, "   RETURN: ");
	switch(amount){
		case 25:
			lcdPosition(lcd, 11, 2);
			lcdPuts(lcd, "0.25");
			break;
		case 50:
			lcdPosition(lcd, 11, 2);
			lcdPuts(lcd, "0.50");
			break;
		case 75:
			lcdPosition(lcd, 11, 2);
			lcdPuts(lcd, "0.75");
			break;
		case 100:
			lcdPosition(lcd, 11, 2);
			lcdPuts(lcd, "1.00");
			break;
	}
}

void RPi::insufficientMSG(){
	lcdClear(lcd);
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "    INSUFFICIENT    ");
	lcdPosition(lcd, 0, 2);
	lcdPuts(lcd, "       AMOUNT       ");
}

void RPi::outputMSG(int soda){
	lcdClear(lcd);
	if (soda == 0){
		lcdPosition(lcd, 0, 1);
		lcdPuts(lcd, "       ETIRPS      ");
	}else if(soda == 1){
		lcdPosition(lcd, 0, 1);
		lcdPuts(lcd, "        MEET       ");
	}	
	lcdPosition(lcd, 0, 2);
	lcdPuts(lcd, "      SELECTED      ");
}

void RPi::returnMSG(int amount){
	lcdClear(lcd);
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "   RETURN: ");
	switch(amount){
		case 0:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.00");
			break;
		case 25:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.25");
			break;
		case 50:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.50");
			break;
		case 75:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "0.75");
			break;
		case 100:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "1.00");
			break;
		case 125:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "1.25");
			break;
		case 150:
			lcdPosition(lcd, 11, 1);
			lcdPuts(lcd, "1.50");
			break;
	}

}

// Use button interrupts for the inputs
string RPi::inputSystem(){
	cin >> inputChoice;
	switch(inputChoice){
		case 1:
			input = "m025";
			break;
		case 2:
			input = "m050";
			break;
		case 3:
			input = "m100";
			break;
		case 4:
			input = "dev";
			break;
		case 5:
			input = "etirps";
			break;
		case 6:
			input = "meets";
			break;
		default:
			input = "nada";
			break;
	}
	return input;
}


//Serial use serial read/write script
string RPi::inputAD(){
	cout << "Mensagem da propaganda (RPi): ";
	getline(cin, ad);
	cout << endl;
	return ad;
}

void RPi::displayAD(string msg){
	lcdClear(lcd);
	int j = 0;
	string line[4] = NULL;
	for (int i = 0; i < msg.length(); i += 20) {
	    line[j] = msg.substr(i, 20);
	    j++;
	}

	for (int k = 0; k < 4; k++){
		const char* aux_char = line[k].c_str();
		lcdPosition(lcd, 0, k);
		lcdPuts(lcd, aux_char);
	}
}

void RPi::displayDateTime(string time, string date){
	const char* aux_time = time.c_str();
	const char* aux_date = date.c_str();
	lcdClear(lcd);
	lcdPosition(lcd, 2, 1);
	lcdPuts(lcd, aux_date);	
	lcdPosition(lcd, 2, 2);
	lcdPuts(lcd, aux_time);
}

#endif
