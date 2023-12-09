//Programmer: Spencer Presley

#ifndef STACK_H
#define STACK_H

template <class DataType>
struct StackNode
{
	DataType data; // data can be any type
	StackNode<DataType> *next; // pointer to the next node
};

template <class DataType>
class Stack
{
	private:
		StackNode<DataType> *top; //point to the top node of the stack
		int maxSize; //max stack size
		int numNodes; //number of nodes in the stack
	public:
		Stack (int=5); // constructor: create a stack with size x; default size is 10.
		~Stack(); // destructor
		bool isEmpty() const; // check if stack is empty
		bool isFull() const; // checks if the stack is full
		void push(const DataType); // push a node onto the top of the stack
		void pop(); // pop a node from the top of the stack
		DataType topStack() const; // return data from the top of the stack
};

#endif
