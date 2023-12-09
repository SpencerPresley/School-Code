//Programmer: Spencer Presley

#ifndef LAB2_H
#define LAB2_H

struct Node{
	int itemNum;
	char itemName[40];
	double unit; //for pound or number of unit
	double tax;
	double subtotal;
	Node* next;
}

Node *createNode();
Node *insertNode();
Node *deleteNode();
void print();

#endif
