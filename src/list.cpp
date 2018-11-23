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

	Last changed in: 22/11/2018
*/

#include "../include/list.h"

List::List(){
	head = 0;
}

List::~List(){
	Node* cursor = head;
	while(head) {
		cursor = cursor->getNext();
		delete head;
		head = cursor;
	}
	head = 0; // Officially empty
}

void List::insert(string dat){
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

string List::remove(){
	string retval = "";
	if (head != 0){
		retval = head->getVal();
		Node* oldHead = head;
		head = head->getNext();
		delete oldHead;
	}
	return retval;
}

Node* List::readHead(){
	return head;
}

string List::readFirst() {
	return head->getVal(); 
}

Node* List::readTail(){
	Node* p = head;
	Node* q = head;
	if (head == 0)
		tail = head;
	else {
		while (q != 0) {
		    p = q;
		    q = p->getNext();
		 }
		 tail = p;
	}
	return tail;
}

void List::insertAtEnd(Node* tail_queue1, Node* head_queue2){
	if (tail_queue1 == 0){
		head = head_queue2;
	} else {
		tail_queue1 -> setNext(head_queue2);
	}
}

void List::moveToEnd(){
	Node* p = head;
	Node* q = head;
	if (head == 0 || head->next == 0) 
		return;
	while (q->next != 0)
		q = q->next;
	head = p->next;
	p->next= 0;
	q->next = p;
}

void List::newHead(){
	head = 0;
}

void List::listAll(){
	Node* aux = head;
	while (aux != 0){
		cout << aux->getVal() << endl;
		aux = aux->getNext();
	}
}
