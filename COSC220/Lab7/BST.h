//Programmer: Spencer Presley
//Date: 11/8/22
#ifndef BST_H
#define BST_H
#include "TNode.h"

class BST
{
	private:
		TNode *root; // Pointer to root node of tree
		TNode *createNode();
		TNode *treeSearch(TNode*, int);
		TNode *min(TNode*);
		TNode *max(TNode*);
		TNode *successor(TNode*);
		TNode *predecessor(TNode*);
		void clear(TNode*);	
	public:
		BST(); // constructor
		~BST(); // destructor
		TNode *getRoot(){return root;}
		void inOrder(TNode*); // for in order work
		void preOrder(TNode*); // pre order work
		void postOrder(TNode*); // post order work	
		void insertNode();	
		void deleteNode(int);
};

#endif
