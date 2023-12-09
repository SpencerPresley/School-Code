//Programmer: Spencer Presley
//Date: 9/27/22
#include<iostream>
#include "link.h"
using namespace std;

int main()
{	
	Node *list = nullptr; // initializing list node
	Node *newNode = nullptr; // initializing newNode to null
	Node *tmp = list;
	int x; // varibale to decide which case to use based on user input
	int id = 0; //initializing id to 0, later to take a value in from user
	bool flag = true; // flag to be used to know when to close while loop
	int ask; // variable to ask user if they want to continue or terminate program
	while(flag){ //program will loop until user enters 0 to terminate
	cout << "1 to insert, 2 to delete, 3 to search, 4 to print, 5 to quit. "; //asks user which thing they'd like to do
	while(!(cin >> x)) //utility to validate datatype. Solves the issue of infinite printing if user enters a char in for an int.
	{
		cout << "Invalid Data Type!\n";
		cout << "1 to insert, 2 to delete, 3 to search, 4 to print, 5 to quit.\n";
		cin.clear();
		cin.ignore(10, '\n');
	} 
	switch(x){
		case 1: // used to insert new nodes in list
			newNode = createNode();
			list = insertNode(list, newNode);
			break;
		case 2: // used to delete specified nodes in list
			cout << "Enter ID: ";
			cin >> id;
			list = deleteNode(list, id);
			break;
		case 3: // used to search specified nodes in list
			cout << "Enter the ID of the student you're looking for: ";
			cin >> id;
			tmp = searchNode(list, id); //searches list for a specified Node from user, prints Node which is one before the one matched with idnumber as well as all after
//			cout << "Name: " << tmp->lastName << tmp->firstName << "ID Number: " << tmp->idNumber;
			break;
		case 4: // prints entirety of current list
			printList(list);
			break;
		case 5: // quits function
			flag = false;
		}
	}
	return 0;
}
