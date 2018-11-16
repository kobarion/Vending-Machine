/*
	File: queue.h
	Header file for class Queue 

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

class Queue {
	struct Link {
		void* data;
		Link* prev;
		Link* next;
		Link(void* dat, Link* prv, Link* nxt);
		~Link();
	} *head, *tail;
	int length;
	public:
		Queue();
		~Queue();
		void insert(void* dat);
		void* remove();
		void* getHead();
		void* getTail();
		int getLength();
		bool isEmpty();
};