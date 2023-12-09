//Programmer: Spencer Presley

#include "BST.h"
#include "TNode.h"
#include "Students.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Welcome to create a binary tree example program!\n";
	bool flag = true;
	BST<Students> sTree;
	BST<int> iTree;
	int key;
	int printType;

	int menu;
	int data;
	int dt;
	
	Students *student = nullptr;
	Students *temp;


	cout << "1 for int, 2 for student: ";
	cin >> data;
	cout << endl;

	while(flag)
	{	
		cout << "Options: 1) Insert New Element, 2) Delete an Element, 3) Check by printing (Inorder, Postorder, and Preorder), 4) end program.\n";
		cin >> menu;

		if(data == 1){
	
		//	iTree = createNode();

			switch(menu)
			{
				case 1:
					cout << "Enter integer for node: ";
					cin >> dt;
					iTree.insertNode(dt);
					break;
				case 2:
					cout << "Enter key value for node you would like to delete: ";
					cin >> key;
					iTree.deleteNode(key);
					break;
				case 3:
					cout << "In-Order: \n";
					iTree.inOrder(iTree.getRoot());
					cout << endl << "Pre-Order: \n";
					iTree.preOrder(iTree.getRoot());
					cout << endl << "Post-Order: \n";
					iTree.postOrder(iTree.getRoot());
					cout << endl;
					break;
				case 4:
					flag = false;
					break;
			}	
		}

		if(data == 2)
		{

		//	sTree = createNode():

			switch(menu)
			{
				case 1:
				//	Students *newStudent;
				//	newStudent = new Students();
					student  = new Students();
					sTree.insertNode(*student);
					break;
				case 2:
			//		cout << "Enter key value for the Node you'd like to remove from tree: ";
					cout << "Enter id of student too remove from database: ";
					cin >> key;
					temp  = new Students(key);
					sTree.deleteNode(*temp);
					delete temp;
					break;
				case 3:
					cout << "In-Order: \n";
					sTree.inOrder(sTree.getRoot());
					cout << endl << "Pre-Order: \n";
					sTree.preOrder(sTree.getRoot());
					cout << endl << "Post-Order: \n";
					sTree.postOrder(sTree.getRoot());
					cout << endl;
					break;
				case 4:
					flag = false;
					break;
			}
		}
			
	}
}
