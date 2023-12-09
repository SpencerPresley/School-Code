//Programmer: Spencer Presley
//Date: 10/11/22

#ifndef NODE_H
#define NODE_H

class Node
{
	public: //node characteristics
		char lastName[20];
		char firstName[20];
		int idNumber;
		Node *next;
	
		Node(); // constructor
		
		void printNode();
};

#endif
