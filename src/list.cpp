/*
	File: list.cpp
	Implementation file for class List

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

#include "../include/list.h"

List::List() {
	head = 0;
}

List::~List() {
	Node* cursor = head;
	while(head) {
		cursor = cursor->getNext();
		delete head;
		head = cursor;
	}
	head = 0; // Officially empty
}

void List::insert(string dat) {
	Node* p = head;
	Node* q = head;

	if (head == 0)
		head = new Node(dat, head);
	else {
		while (q != 0) {
		    p = q;
		    q = p->getNext();
		 }
		 p->setNext(new Node(dat,0));
	}
}

Node* List::readHead(){
	return head;
}

string List::readFirst() {
	return head->getVal(); 
}

string List::remove() {
	string retval = "";
	if (head != 0){
		retval = head->getVal();
		Node* oldHead = head;
		head = head->getNext();
		delete oldHead;
	}
	return retval;
}

void List::listAll() {
	Node* aux = head;
	while (aux != 0){
		cout << aux->getVal() << endl;
		aux = aux->getNext();
	}
}
