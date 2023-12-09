// Programmer: Spencer Presley
// 9/25/22

#ifndef LINK_H
#define LINK_H

//structure with datatype node. Node contains various variables being assigned to a student. It also contains a pointer pointing to the next node.
struct Node{
	char lastName[20]; // Student Last Name
	char firstName[20]; // Student First Name
	int idNumber; // Student's ID Number
	Node *next; 
};

//Function prototypes that will be needed to do various tasks involving the linked list. Create node creates a new node, insert Node inserts a Node into the list, search Node searches the list for a Node //with a matching id number inputted by user, delete Node deletes a node with a matching id the user inputted, print list prints the current linked list.
Node *createNode();
Node *insertNode(Node *, Node *);
Node *searchNode(Node*, int);
Node *deleteNode(Node*, int);
void printList(Node*);

#endif
