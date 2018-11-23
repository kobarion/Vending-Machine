/*
   File: node.cpp
   Implementation file for class Node

   UFSC - EEL7323 - C++ Programming for Embedded Systems

   Project: Vending Machine
   Description: Class Node stores values for a linked list.  

   Modified from: Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Author: Rodrigo Kobashikawa Rosa <rodrigokrosa@gmail.com>
   Github: https://github.com/kobarion/Vending-Machine

   Last changed in: 22/11/2018

*/

#include "../include/node.h"

// Constructor - initializes the node
//
Node::Node(string dat, Node* nxt){
	msg = dat;
	next = nxt;
}

// getVal returns the string message stored in the node
//
string Node::getVal(){
	return msg;
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
	return next;
}

// setVal stores the string message in the node
//
void Node::setVal(string dat){
	msg = dat;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
	next = nxt;
}
