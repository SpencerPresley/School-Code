//Programmer: Spencer Presley

#include "lab2.h"
#include <iostream>
using namespace std;

Node *createNode()
{
	Node *newNode = new Node;
	int itemNum;
	char itemName[40];
	double unit;
	double tax;
	double subtotal;
	Node *next;
}

Node *insertNode(Node *list, Node *newNode){

	Node *tmp = list;

	if(list == nullptr)
	{
		list = newNode;
		return list;
	}

	while(tmp->next != nullptr)
	{
		tmp = tmp->next;
	}

	tmp = newNode;
}

void print(Node *list){
	
	Node *tmp = list;

	if(list == nullptr)
	{
		cout << "Cart Empty. " << endl;
		return list;
	}
	
	else
	{
		while(tmp->next != nullptr)
		{
			outdata << list->itemNum << "\t\t\t\t\t\t\t\t" << list->itemName << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << list->unit << "\t\t\t\t\t\t\t\t\t" << list->tax << "\t\t\t\t\t\t\t\t\t\t\t" << list->subtotal;
		}

		outdata << list->itemNum < "\t\t\t\t\t\t\t\t\t\t\t" << list->itemName << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << list->unit << "\t\t\t\t\t\t\t\t\t\t" << list->tax << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << list->subtotal;
	}	
}
