//Programmer: Spencer Presley

#include "stack.h"
#include <iostream>
using namespace std;

template<class DataType>
Stack<DataType>::Stack(int stackSize) // defualt constructor
{
	maxSize = stackSize;
	top = nullptr;
	numNodes = 0;
}

/*template<class DataType>
Stack<DataType>::Stack(int x) // constructor
{
	maxSize = x;
	top = nullptr;
	numNodes = 0;
}*/

template<class DataType>
void Stack<DataType>::push(const DataType x) // pushes a new element to the top of the stack
{

		StackNode<DataType> *newNode = new StackNode<DataType>;
		newNode->data = x;
		newNode->next = nullptr;
		if(top==nullptr)
		{
			top = newNode;
			numNodes++;
		}
	
		else
		{
			newNode->next = top;
			top = newNode;
			numNodes++;
		}
	
}

template<class DataType>
void Stack<DataType>::pop() // pops node from stack
{
		StackNode<DataType> *tmp = nullptr;
		tmp = top;
		top = top->next;
		delete tmp;
		numNodes--;
	
}

template<class DataType>
bool Stack<DataType>::isEmpty() const // checks if stack is empty
{
	if(top == nullptr)
		return true;
	else
		return false;
}

template<class DataType>
bool Stack<DataType>::isFull() const // checks if stack is full
{
	if(numNodes == maxSize)
		return true;
	else
		return false;
}

template<class DataType>
DataType Stack<DataType>::topStack() const // returns top node
{
	return  top->data;
}

/*template<class DataType>
Stack<DataType>::~Stack()
{
	while(top!=nullptr)
	{
		pop();
	}
}*/

template<class DataType>
Stack<DataType>::~Stack()
{
	StackNode<DataType> *tmp = top, *del = nullptr;
	
	while(tmp != nullptr)
	{
		del = tmp;
		tmp = tmp->next;
		delete del;
	}
}
