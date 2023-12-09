// Programmer: Spencer
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
	private: // hold list node and function prototype for create node and search location
		Node *list; //head pointer
		Node *createNode(); // creates a new node
		Node *searchLocation(int); // searches correct position of which to insert or delete a node
	public: 
		void insertNode(); // functions for various actions within the list
		void deleteNode(int);
		void printList();
		void searchNode(); 

	LinkedList(); // Constructor

	~LinkedList();
};

#endif
