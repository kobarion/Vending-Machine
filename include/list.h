/*
	File: list.h
	Header file for class List

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description:  Class List stores Nodes (class Node) in a linked list.

	Class list is definition for a linked list, having the following operations:

	1. Initialize the list to an empty list.
	2. Free the nodes of a list.
	3. Determine whether a list is empty.
	4. Add a node with a given value to the end of the list.
	5. Delete the first node from the list. 

	Modified from: Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
	Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
	Github: https://github.com/kobarion/Vending-Machine

	Last changed in: 16/11/2018
*/

#include "../src/node.cpp"

class List {

	Node* head;

	public:
		List();
		~List();
		void insert(string dat);
		string readFirst();
		Node* readHead();
		string remove();
		void listAll();
};
