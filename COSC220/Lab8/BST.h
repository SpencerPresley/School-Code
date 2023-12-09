//Programmer: Spencer Presley
//Date: 11/8/22
#ifndef BST_H
#define BST_H
#include "TNode.h"

template <class DataType>
class BST
{
	
	private:
		TNode<DataType> *root; // Pointer to root node of tree
		TNode<DataType> *createNode();
		TNode<DataType> *treeSearch(TNode<DataType>*, DataType);
		TNode<DataType> *min(TNode<DataType>*);
		TNode<DataType> *max(TNode<DataType>*);
		TNode<DataType> *successor(TNode<DataType>*);
		TNode<DataType> *predecessor(TNode<DataType>*);
		void clear(TNode<DataType>*);	
	public:
		BST(); // constructor
		~BST(); // destructor
		TNode<DataType> *getRoot(){return root;}
		void inOrder(TNode<DataType>*); // for in order work
		void preOrder(TNode<DataType>*); // pre order work
		void postOrder(TNode<DataType>*); // post order work	
		void insertNode(DataType);	
		void deleteNode(DataType);
};

#endif
