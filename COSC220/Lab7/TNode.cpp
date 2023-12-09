//Programmer: Spencer Presley
//Date: 11/8/22

#include "TNode.h"
#include <iostream>

using namespace std;

TNode::TNode()
{
	parent = nullptr;
	leftchild = nullptr;
	rightchild = nullptr;
}

void TNode::printNode(TNode* x)
{
	cout << "Data: " << x->data;  
}

	
