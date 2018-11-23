/*
	File: node.h
	Header file for class Node

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Node stores values for a linked list.  

	Modified from: Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 22/11/2018
*/


#include <iostream>

using namespace std;

class Node {
	string msg;
	public: 
		Node* next;
		Node(string dat, Node* nxt);
		string getVal();
		Node* getNext();
		void setVal(string dat);
		void setNext(Node* nxt);
};
