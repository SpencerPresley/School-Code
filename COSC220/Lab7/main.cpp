//Programmer: Spencer Presley

#include "BST.h"
#include "TNode.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Welcome to create a binary tree example program!\n";
	int option;
	bool flag = true;
	BST tree;
	int key;
	int printType;

	while(flag)
	{	
		cout << "Options: 1) Insert New Element, 2) Delete an Element, 3) Check by printing (Inorder, Postorder, and Preorder), 4) end program.\n";
		cin >> option;
		
		
		switch(option)
		{
			case 1:
				tree.insertNode();
				break;
			case 2:
				cout << "Enter key value for node you would like to delete: ";
				cin >> key;
				tree.deleteNode(key);
				break;
			case 3:
				cout << "In-Order: \n";
				tree.inOrder(tree.getRoot());
				cout << endl << "Pre-Order: \n";
				tree.preOrder(tree.getRoot());
				cout << endl << "Post-Order: \n";
				tree.postOrder(tree.getRoot());
				cout << endl;
				break;
			case 4:
				flag = false;
				break;
		}	
	}
}
