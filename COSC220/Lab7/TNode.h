//Programmer: Spencer Presley
//Date: 11/8/22
#ifndef TNODE_H
#define TNODE_H

class TNode
{
	friend class BST;
	
	private:
		TNode *parent; // parent pointer
		TNode *leftchild; // pointer to left child
		TNode *rightchild; // pointer to right child
		int data;
	public:
		TNode(); // constructor
		void printNode(TNode*); // print function
};

#endif
