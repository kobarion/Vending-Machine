/*
	File: queue.cpp
	Implementation file for class Queue

	UFSC - EEL7323 - C++ Programming for Embedded Systems

	Project: Vending Machine
	Description: Class Queue is definition for a queue inmplemented on a linked list,
	with the following operations:

	1. Insert element (tail).
	2. Remove element (head).
	3. Determine whether the queue is empty.
	4. Show the head and the tail.
	5. Show the length.

	Author: Eduardo Augusto Bezerra <eduardob@acm.org>
	April 2003.
*/

#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
	head = 0;
	tail = 0;
	length = 0;
}

Queue::~Queue() {
	Link* cursor = head;
	while(head) {
		cursor = cursor->prev;
		delete head;
		head = cursor;
	}
	head = 0; // Officially empty
	tail = 0;
	length = 0;
}

Queue::Link::Link(void* dat, Link* prv, Link* nxt) {
	data = dat;
	prev = prv;
	next = nxt;
}

Queue::Link::~Link() {
//  delete prev;
}

void Queue::insert(void* dat) {
	if (head == 0){
		tail = new Link(dat, 0, 0);
		head = tail;
	} else {
		tail->next = new Link(dat, tail, 0);
		tail = tail->next;
	}
	length++;
}

void* Queue::remove() {
	int* pint;
	void* result;
	if(length == 0)
		result = 0;
	else {
		result = head->data;
		Link* oldHead = head;
		head = head->next;
		if (head != 0)
			head->prev = 0;
			delete oldHead;
			length--;
		}
		if (length == 0)
			tail = 0;
	return result;
}

void* Queue::getHead() { 
	return head->data; 
}

void* Queue::getTail() { 
	return tail->data; 
}

int Queue::getLength() {
	return length;
}

bool Queue::isEmpty() {

	bool flag = false;

	if (length == 0)
		flag = true;

	return flag;
}