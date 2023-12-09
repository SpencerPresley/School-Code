// Programmer: Spencer Presley
#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
	cout << "Last Name: ";
	cin >> lastName;
	cout << endl << "First Name: ";
	cin >> firstName;
	cout << endl << "ID Number: ";
	cin >> idNumber;	
	
	next = nullptr;
}

void Node::printNode()
{
	cout << "Last Name: " << lastName << " First Name: " << firstName << " ID Number: " << idNumber;
}

