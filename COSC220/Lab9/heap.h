//Programmer: Spencer Presley
//header file for implementation of integer heap

#ifndef HEAP_H
#define HEAP_H

class heap
{
	private:
		int A[100];
		int heapsize;
		
		int parent(int);
		int leftChild(int);
		int rightChild(int);
		
		void heapify(int);
		void buildHeap();

	public:
		friend void swap(int&, int&);
		heap(); //constructor
		void insert(int); //insert new element into heap
		void heapSort(); // sort the heap
		int extractMax();
		int max(); // returns max of heap
		void print(); // prints heap
		
	
};

#endif
