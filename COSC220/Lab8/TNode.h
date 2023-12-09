//Programmer: Spencer Presley
//Date: 11/8/22
#ifndef TNODE_H
#define TNODE_H

template <class DataType>
class TNode
{
	template<class>friend class BST;
	
	private:
		TNode *parent; // parent pointer
		TNode *leftchild; // pointer to left child
		TNode *rightchild; // pointer to right child
	public:
		DataType data;
		TNode(); // constructor
		TNode(DataType);
		void printNode(TNode*); // print function
};

#endif
