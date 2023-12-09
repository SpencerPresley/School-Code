// Programmer: Spencer Presley

#ifndef HEADER_H
#define HEADER_H


struct Node
{
	int itemNum;
	char itemName[40];
	double unit; // for pound or number of units
	double tax;
	double subtotal;
	Node *next;
};


Node *insertNode(Node*, Node*);
Node *deleteNode(Node*, int);
double taxCalc(double price);
double taxTotal(double price);
double taxCalc(double unit, double price);
double taxTotal(double unit, double price);
double totalNoTax(double unit, double price);
void printCurrent(Node*, int);
void printFile(Node*, double subt);

#endif
