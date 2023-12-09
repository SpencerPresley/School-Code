//Programmer: Spencer Presley
//Date: 11/8/22

#include "TNode.h"
#include <iostream>

using namespace std;

template <class DataType>
TNode<DataType>::TNode()
{
	parent = nullptr;
	leftchild = nullptr;
	rightchild = nullptr;
	cout << "Enter Data for Node: ";
//	cin >> data;
	cout << endl;
}

template<class DataType>
TNode<DataType>::TNode(DataType data)
{
	parent = NULL;
	leftchild = NULL;
	rightchild = NULL;
	this->data = data;
}

template <class DataType>
void TNode<DataType>::printNode(TNode<DataType> *x)
{
	cout << "Data: " << x->data;  
}

	
