//Programmer: Spencer Presley

#include <iostream>
#include "TNode.h"
#include "BST.h"

using namespace std;

template<class DataType>
BST<DataType>::BST() // bst constructor
{
	root = nullptr;
}

/*template<class DataType>
TNode<DataType> *BST<DataType>::createNode() //function to create an new tnode
{
	TNode<DataType> *newNode = new TNode<DataType>; // dynamically allocates new memory for a node
//	newNode->parent = nullptr;
//	newNode->leftchild = nullptr;
//	newNode->rightchild = nullptr;
//	cout << "Please enter your data for this Node: ";
//	cin >> newNode->data;
//	cout << endl;
	return newNode;
}*/

template <class DataType>
void BST<DataType>::insertNode(DataType data) // function to insert a new node
{
//	TNode<DataType> *newNode = createNode();
	TNode<DataType> *newNode = new TNode<DataType>(data);

	TNode<DataType> *parent = nullptr;
	TNode<DataType> *tmp = root;
	/*
	while(tmp != nullptr)
	{
		y = tmp;
		if(newNode->data < tmp->data)
			tmp = tmp->leftchild;
		else
			tmp = tmp->rightchild;
	}
	

	newNode->parent = y;
	
	cout <<" about to do checks";	
	if(y == nullptr){
		root = newNode;
		cout << "in if";
	}

	else if(treeSearch(root, data) != nullptr){
		cout << "Data already in tree!" << endl;
		cout << "in else if 1";
	}
	
	else if(newNode->data < y->data){
		y->leftchild = newNode;
		cout << "in else if 2";
	}

	else{
		y->rightchild = newNode;
		cout << "in else";
	} */
	
	// CASE 1: Empty Tree
	if (tmp == nullptr) {
		root = newNode;
		return;
	}

	// CASE 2: Non-Empty Tree
	while (tmp != nullptr) {
		if (tmp->data > newNode->data) {
			parent = tmp;
			tmp = tmp->leftchild;
			cout << "went left\n";
			continue;
		}	
		if (tmp->data < newNode->data) {
			parent = tmp;
			tmp = tmp->rightchild;
			cout << "went right\n";
			continue;
		}
		if (tmp->data == newNode->data) {
			cout << "Data is already in tree!\n";
			return;
		}
		cout << "Error inserting into the tree.\n";
		return;
	}
	tmp = newNode;
	newNode->parent = parent;
	if (newNode->data > parent->data)
		parent->rightchild = newNode;
	if (newNode->data < parent->data)
		parent->leftchild = newNode;
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

template <class DataType>
void BST<DataType>::deleteNode(DataType key) // function to delete a node from tree
{
	if(root == nullptr)// for case with empty tree
	{
		cout << "Tree is empty!" << endl;
	}

	else
	{
		TNode<DataType> *tmp = nullptr;
		TNode<DataType> *tmp2;
		TNode<DataType> *del = treeSearch(root, key);

		if(del == nullptr) { // if node to be deleted isn't found
			cout << "Not in tree" << endl;
			return;
		
		} 
		
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

template <class DataType>
void BST<DataType>::inOrder(TNode<DataType> *root) // to print inorder
{
	if(root == nullptr)
		return;

	inOrder(root->leftchild); // go left
	cout << root->data << " "; // print
	inOrder(root->rightchild); // go right
}

template <class DataType>
void BST<DataType>::preOrder(TNode<DataType> *root) // to print preorder
{
	if(root == nullptr)
		return;

	cout << root->data << " "; // print
	preOrder(root->leftchild); // go left
	preOrder(root->rightchild); // go right
}

template <class DataType>
void BST<DataType>::postOrder(TNode<DataType>* root) // to print post order
{
	if(root == nullptr)
		return;
	
	postOrder(root->leftchild); // go left
	postOrder(root->rightchild); // go right
	cout << root->data << " "; // print
}

template <class DataType>
TNode<DataType> *BST<DataType>::successor(TNode<DataType> *x) //sucessor
{
	TNode<DataType> *tmp = x;
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

template <class DataType>
TNode<DataType> *BST<DataType>::predecessor(TNode<DataType> *x) //predecessor
{
	TNode<DataType> *tmp = x;

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
template <class DataType>
TNode<DataType> *BST<DataType>::min(TNode<DataType> *x)
{
	TNode<DataType> *tmp = x;
	
	while(tmp->leftchild != nullptr) // keep going left until null to fin min
		tmp = tmp->leftchild;

	return tmp;
}

// find max
template<class DataType>
TNode<DataType> *BST<DataType>::max(TNode<DataType> *x)
{
	TNode<DataType> *tmp = x;
	
	while(tmp->rightchild != nullptr) // keep going right until null to find max
		tmp = tmp->rightchild;

	return tmp;
}

template <class DataType>
TNode<DataType> *BST<DataType>::treeSearch(TNode<DataType> *x, DataType  key)
{

	TNode<DataType> *tmp = x;

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

template <class DataType>
BST<DataType>::~BST()
{
	clear(root);
}

template <class DataType>
void BST<DataType>::clear(TNode<DataType>* x)
{
	TNode<DataType> *tmp = x;
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
