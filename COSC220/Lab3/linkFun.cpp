//Programmer: Spencer
//10/4/22

#include "link.h"
#include <iostream>
using namespace std;

Node *createNode() //function implementation to create a new node
{
	Node *newNode = new Node;
	newNode->next = nullptr;
	cout << "Enter last name of student: ";
	cin >> newNode->lastName;
	cout << "Enter first name of student: ";
	cin >> newNode->firstName;
	cout << "Enter ID Number of student: ";
	cin >> newNode->idNumber;
	return newNode;
}

Node *insertNode(Node *list, Node *newNode) //Function implementation to insert a node
{
	Node *tmp = list;
	
	if(tmp == nullptr) //Inserts if empty
	{
		list = newNode;
		return list;
	}

	if(newNode->idNumber < tmp->idNumber) //Inserts node as first in the list
	{
		newNode->next = list;
		list = newNode;
		return list;
	}

	while(tmp->next != nullptr && tmp->next->idNumber < newNode->idNumber) //Searches list to find correct position for newNode
	{
		tmp = tmp->next;
	}

	if(tmp->idNumber == newNode->idNumber) //If the current Node idNumber is = to the idNumber of the newNode passed in by user then it's considered a duplicate
	{
		cout << "Error, student already exists.\n";
		return list;
	}

	if(tmp->next == nullptr) //condition to insert node at the end of the list if it's the greatest
	{
		tmp->next = newNode;
		return list;
	}

	else //inserts newNode between 2 nodes
	{
		newNode->next = tmp->next;
		tmp->next = newNode;
		return list;
	}	
}

Node *searchNode(Node *list, int id)
{
	Node *tmp = list;
	
	if(tmp == nullptr){
		cout << "List is empty so there is no such student in the list.\n";
		return list;
	}
	
	if(tmp->idNumber == id)
	{
		cout << "Student found. ";
		cout << tmp->lastName << " " << tmp->firstName << " " << tmp->idNumber << endl;
		return tmp;
	}
	
	//while loop iterates through list, as long as the next node is not equal to null and the next node's id number is less than the id key passed in it will go to the next node in the list.
	/*while((tmp->next != nullptr) && (tmp->next->idNumber < id))
	{
		tmp = tmp->next;
	}*/

	while((tmp->next != nullptr)&&(tmp->idNumber !=  id))
	{
		tmp = tmp->next;
	}

	if(tmp->idNumber == id) // Checks if the next node's idNumber is = to the id key passed in by user
	{
		cout << "Student found.\n";
		cout << tmp->lastName << " " << tmp->firstName << " " << tmp->idNumber << endl;
		return tmp; //Here I'm returning tmp because the assignment says under search node "Return type: pointer to a node which is one before matched with ID Number. This would mean to find the one you're looking for and return the node 1 before it. If this is incorrect and you'd rather return the entire list you would change 'return tmp;' to 'return list;'. If you want to return just the node you found that matched the id passed in you'd change 'return tmp;' to 'return tmp->next;'.
	}
	
	else //if the next node's idNumber doesn't = the id key passed in by the user and it got this far in the function this must mean the next node's idnumber is greater than the id key or it's equal to null. In either case the node with idNumber matching the id key passed in doesn't exist. In print function this will return nothing present in the list. An alternative way to do this is to just say "student not found in the list" and return list, print function will then print the entire list. Reason I did it this way though is the instructions say "If there is no match, return NULL pointer".
	{
		cout << "Student not in list. " << endl;
		return nullptr;
	}
}

Node *deleteNode(Node *list, int id)
{
	Node *tmp; //declaration of tmp pointer
	Node *tmp1; //declaration of 2nd tmp pointer
	tmp = list; //setting tmp = to list so I can traverse the list without losing access to any data
	
	if(tmp == nullptr) //if the list is empty sends a message saying so and that there's nothing to delete, returns list as is
	{
		cout << "List is empty, nothing to delete.\n";
		return list;
	}

	if(tmp->idNumber == id) //Deletes first node if it's idNumber matches the id key passed in by user
	{
		cout << "Student removed from list.\n";
		list = tmp->next; //moves list to the next Node
		delete tmp; //Deletes selected node
		return list; //returns updated list with selected node removed
	}

	while((tmp->next != nullptr) && (tmp->next->idNumber < id)) //iterates through list to find correct placement
	{
		tmp=tmp->next;
	}

	if(tmp->next->idNumber == id) //Deletes Node between two nodes or at the end
	{
		cout << "Student removed from list.\n";
		tmp1 = tmp->next;
		tmp->next=tmp->next->next;
		delete tmp1;
	}

	else{
		cout << "Student is not in list, nothing to delete." << endl;
		return nullptr;
	}
	
	return list; //either returns updated list from if statement to delete between/end of list or just returns unupdated list if there was nothing matching the id key to delete.

	
}

void printList(Node *list) //function to print Node contents in list
{
	Node *tmp = list;
	if(tmp == nullptr) //if list is empty
	{
		cout << "Nothing currently present in list" << endl;
	}

	else //if list isn't empty
	{
		while(list->next != nullptr) //while node next is not nullptr iterate through and print the nodes
		{
			cout << list->lastName << " " << list->firstName << " " << list->idNumber << endl;
			list = list->next;
		}

		cout << list->lastName << " " << list->firstName << " " << list->idNumber << endl; // prints last node
	}
}
