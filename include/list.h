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

	Last changed in: 22/11/2018
*/

#ifndef LIST_H
#define LIST_H

#include "../src/node.cpp"

class List {
	Node* head;
	Node* tail;
	public:
		List();
		~List();
		void insert(string dat);
		string remove();
		string readFirst();
		Node* readHead();
		Node* readTail();
		void insertAtEnd(Node* tail_queue1, Node* head_queue2);
		void moveToEnd();
		void newHead();
		void listAll();
};

#endif