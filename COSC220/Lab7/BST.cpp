//Programmer: Spencer Presley

#include <iostream>
#include "TNode.h"
#include "BST.h"

using namespace std;

BST::BST() // bst constructor
{
	root = nullptr;
}

TNode *BST::createNode() //function to create an new tnode
{
	TNode *newNode = new TNode; // dynamically allocates new memory for a node
//	newNode->parent = nullptr;
//	newNode->leftchild = nullptr;
//	newNode->rightchild = nullptr;
	cout << "Please enter your data for this Node: ";
	cin >> newNode->data;
	cout << endl;
	return newNode;
}

void BST::insertNode() // function to insert a new node
{
	TNode *newNode = createNode();

	
	TNode* y = nullptr;
	TNode *tmp = root;
	
	while(tmp != nullptr)
	{
		y = tmp;
		if(newNode->data < tmp->data)
			tmp = tmp->leftchild;
		else
			tmp = tmp->rightchild;
	}
	

	newNode->parent = y;
	
	if(y == nullptr)
		root = newNode;

	else if(treeSearch(root, newNode->data) != nullptr)
		cout << "Data already in tree!" << endl;
	
	else if(newNode->data < y->data)
		y->leftchild = newNode;

	else
		y->rightchild = newNode;
	
}

/*void BST::deleteNode(int key)
{
	BST *y = nullptr;
	BST *tmp = head;

	if((del->leftchild == nullptr) || (del->rightchild == nullptr))
		y = del;
	else
		y = successor(del);

	if(y->leftchild != nullptr)
		tmp = y->leftchild;
	else
		tmp = y->rightchild;

	if(tmp!=nullptr)
		tmp->parent = y->parent;
	if(y->parent == nullptr)
		head->root = tmp;
	else if(y == y->parent->leftchild)
		y->parent->leftchild = tmp;
	else
		head->data = y->data;		
}*/

void BST::deleteNode(int key) // function to delete a node from tree
{
	if(root == nullptr)// for case with empty tree
	{
		cout << "Tree is empty!" << endl;
	}

	else
	{
		TNode *tmp = nullptr;
		TNode *tmp2;
		TNode *del = treeSearch(root, key);

		if(del == nullptr) // if node to be deleted isn't found
			cout << "Not in tree";
		
		else if((del->leftchild == nullptr) || (del->rightchild == nullptr)) // if del node is a leaf
			tmp = del;
	
		else // if not leaf
			tmp = successor(del);

		if(tmp->leftchild != nullptr)
			tmp2 = tmp->leftchild;

		else
			tmp2 = tmp->rightchild;
	
		if(tmp2 != nullptr)
			tmp2->parent = tmp->parent;

		if(tmp->parent == nullptr)
			root = tmp2;

		else if(tmp == tmp->parent->leftchild)
			tmp->parent->leftchild = tmp2;
		else
			tmp->parent->rightchild = tmp2;

		if(tmp != del)
			del->data = tmp->data;

		delete tmp;
	}
}

void BST::inOrder(TNode *root) // to print inorder
{
	if(root == nullptr)
		return;

	inOrder(root->leftchild); // go left
	cout << root->data << " "; // print
	inOrder(root->rightchild); // go right
}

void BST::preOrder(TNode* root) // to print preorder
{
	if(root == nullptr)
		return;

	cout << root->data << " "; // print
	preOrder(root->leftchild); // go left
	preOrder(root->rightchild); // go right
}

void BST::postOrder(TNode* root) // to print post order
{
	if(root == nullptr)
		return;
	
	postOrder(root->leftchild); // go left
	postOrder(root->rightchild); // go right
	cout << root->data << " "; // print
}

TNode *BST::successor(TNode *x) //sucessor
{
	TNode *tmp = x;
	if(tmp->rightchild != nullptr) 
		return min(tmp->rightchild); // go to right if not null and then find minium
	
	else
	{
		tmp = x->parent; // if right is null, tmp will be parent of x
	}

	while((tmp!=nullptr) && (x == tmp->rightchild)) // continue up until tmp doesn't = null or x is no longer right child of tmp
	{
		x = tmp; // sets x = to tmp
		tmp = tmp->parent; // moves tmp up one
	}

	return tmp;	
}

TNode *BST::predecessor(TNode *x) //predecessor
{
	TNode *tmp = x;

	if(tmp->leftchild != nullptr)
		return max(tmp->leftchild);
	else
	{
		tmp = x->parent;
	
		while((tmp!=nullptr) && (x = tmp->leftchild))
		{
			x = tmp;
			tmp = tmp->parent;
		}

		return tmp;
	}
}

// find minimum
TNode *BST::min(TNode *x)
{
	TNode *tmp = x;
	
	while(tmp->leftchild != nullptr) // keep going left until null to fin min
		tmp = tmp->leftchild;

	return tmp;
}

// find max
TNode *BST::max(TNode *x)
{
	TNode *tmp = x;
	
	while(tmp->rightchild != nullptr) // keep going right until null to find max
		tmp = tmp->rightchild;

	return tmp;
}

TNode *BST::treeSearch(TNode *x, int key)
{

	TNode *tmp = x;

	if(tmp == nullptr)
	{
		return tmp;
	}

	else if(tmp->data == key)
		return tmp;

	else if(key < tmp->data)
		return treeSearch(tmp->leftchild, key);

	else
		return treeSearch(tmp->rightchild, key);
}

BST::~BST()
{
	clear(root);
}

void BST::clear(TNode* x)
{
	TNode *tmp = x;
	if(x == nullptr)
		return;

	/*else
	{
		TNode *tmp = nullptr;
		TNode *tmp;

		if((x->leftchild == nullptr) || (x->leftchild == nullptr))
			tmp = x;

		else
			
			
			
	}*/

	clear(tmp->leftchild);
	clear(tmp->rightchild);
	delete tmp; 
	
	
}
