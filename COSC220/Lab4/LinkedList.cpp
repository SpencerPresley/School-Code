//Programmer: Spencer Presley
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() // constructor sets head of list to nullptr
{
	list = nullptr;
}

Node *LinkedList::createNode() // creates a new node
{
	Node *newNode = new Node;
	return newNode;
}

Node *LinkedList::searchLocation(int key) // searches for a nodes location and returns pointer to the node before it
{
	Node *tmp = list;
	while((tmp->next != nullptr) && (tmp->next->idNumber < key))
	{
		tmp = tmp->next;
	}

	return tmp;
}

void LinkedList::insertNode() // inserts a new node
{
	Node *newNode = createNode(); // creates the node
	Node *tmp = nullptr;
//	Node *tmp = searchLocation(newNode->idNumber); // sets a tmp pointer = to the pointer returned from search location

	cout << "check";	
	if(list == nullptr) // checks for duplicate in the event theres only one node in the list
	{
		list = newNode;
	}

	else if(list->idNumber == newNode->idNumber) // checks if empty
	{
		cout << "Student already in list!\n";
		delete newNode;
	}

	else if(list->idNumber > newNode->idNumber)
	{
		cout << "student added!\n";
		newNode->next = list;
		list = newNode;
	}

	else // inserts the node
	{
		tmp = searchLocation(newNode->idNumber);
		if(tmp->next == nullptr)
		{
			tmp->next = newNode;
		}

		else if(tmp->next->idNumber >  newNode->idNumber)
		{
			newNode->next = tmp->next;
			tmp->next = newNode;
		}

		else
		{
			cout << "Student already in list!\n";
			delete newNode;
		}
	}
}

void LinkedList::deleteNode(int key) // deletes a node
{
	Node *tmp;
	
	if(list!=nullptr)
	{
	tmp = searchLocation(key); // sets tmp pointer = to the pointer being returned from the search
	}

	Node *tmp1 = list; // tmp pointer set = to list

	if(list == nullptr) // if the list is empty will say so
	{
		cout << "List is empty\n";
	}
	
	else if(list->idNumber == key) //in the event theres only one node in the list and it's the one that matches the key to be deleted
	{
		list = tmp1->next;
		delete tmp1;
	}	
	
	else if(tmp->next == nullptr) //if searchlocation gets all the way to the end of the list and next is nullptr and not the one being searched for will tell user data doesn't exist
	{
		cout << "Data is not available to delete in list.\n";
	}

	else if(tmp->next->idNumber != key) // if the next node isn't the one being looked for informs user student isn't in the list
	{
//		Node *tmp = searchLocation(key);
		cout << "Student isn't in the list.\n";
	}

	else // moves tmp pointer to the node to be deleted then deletes it
	{
//		Node *tmp = searchLocation(key);
		if(tmp->next == nullptr && tmp->idNumber != key) // if the last isn't equal to key and the next is null
		{
			cout << "Student not in list.\n";
		}

		else
		{
				tmp1 = tmp->next;
				tmp->next = tmp->next->next;
				delete tmp1;
				cout << "Student removed from list!\n";
		}
	}
}

void LinkedList::searchNode() // searches for a specific node
{
	Node *tmp; // sets tmp pointer = to list
	
	int key = 0;
	cout << "Student searching for? ";
	cin >> key; //id of student being searched for
	
	tmp = searchLocation(key); // finds location that matches
	
	if(tmp->idNumber == key)
	{
		tmp->printNode();
	}
	else if(tmp->next == nullptr) // if next is null and not the one that matches says student isn't in list
	{
		cout << "Student isn't in list\n";
	}
	
	else if(tmp->next->idNumber != key) // if the next pointer isn't null but also isn't = to the key then says student isn't in list
	{
		cout << "Student not in list\n";
	}
	
	else // if student is found prints out information
	{
		tmp->next->printNode();
	}
}

void LinkedList::printList() // prints entire list
{
	Node *tmp = list;
	
	if(tmp == nullptr)
	{
		cout << "Empty list!\n";
	}
	
	else{
		while(tmp->next != nullptr)
		{
			tmp->printNode();
			cout << endl;
			tmp = tmp->next;
		}
	
		tmp->printNode();
		cout << endl;
	}
}

LinkedList::~LinkedList()
{
	Node *tmp;
	while(list !=  nullptr)
	{
		tmp = list;
		list = list->next;
		delete tmp;
	}
}
