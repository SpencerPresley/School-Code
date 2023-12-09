//Programmer: Spencer Presley
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	int choice; // integer to hold value of user selected action
	LinkedList LL;
	bool flag = true;
	
	while(choice != 5){	
		cout << "1 to insert, 2 to delete, 3 to print list, 4 to search and print node, 5 to quit." << endl << "Select an option: ";
		cin >> choice;	
		switch(choice)// menu that does whatever corresponds with user input
		{
			case 1: // inserts new node
				LL.insertNode();
				break;
			case 2: // deletes student associated with key. If student doesn't exist tells user they don't exist.
				int key;
				cout << "Enter the student ID of the student you want to remove: ";
				cin >> key;
				LL.deleteNode(key);
				break;
			case 3: // prints entire list
				LL.printList();
				break;
			case 4: // searches for and prints specific node
				LL.searchNode();
				break;
			case 5: // leaves program
		//		cout << "Goodbye!\n";
		//		flag = false;
				break;
		}
	}	

	return 0;
}
