//Programmer: Spencer Presley

#include "heap.h"
#include <iostream>
using namespace std;

heap::heap()
{
	heapsize = 10;
	int defaultArr[] = {4, 12, 3, 19, 23, 5, 32, 11, 2, 24};

	for(int i = 0; i < heapsize; i++)
		A[i] = defaultArr[i];
	
	for(int i = 10; i < 100; i++)
	{
		A[i] = 0;
	}

	buildHeap();
}

int heap::parent(int i) // utility to find parent of i
{
	if((i%2) == 0) // if remainder is 0 it's even so do this
		return ((i-1)/2);
	return (i/2); // when i is odd
}

int heap::leftChild(int i) // utility to find leftChild of i
{
	return ((i*2)+1);
}

int heap::rightChild(int i) // utility to find rightChild of i
{
	return((i*2)+2);
}

void heap::insert(int key)
{
	heapsize = ++heapsize; // increases size by 1
	int i = heapsize-1; // sets i = to largest index
	while((i > 0) && (A[parent(i)] < key)) // iterates through to find right position
	{
		A[i] = A[parent(i)];
		i = parent(i);
	}

	A[i] = key;
}

void heap::heapify(int i)
{
	int largest;
	int L = leftChild(i);
	int R = rightChild(i);

	if((L <= heapsize-1) && (A[L]>A[i]))
		largest = L;
	
	else
		largest = i;
	
	if((R <= (heapsize-1)) && (A[R] > A[largest]))
		largest = R;
	
	if(largest != i)
	{
		swap(A[i], A[largest]);
		heapify(largest);
	}
}

void heap::buildHeap()
{
	for(int i = ((heapsize/2)-1); i >= 0; i--)
		heapify(i);
}

void heap::heapSort()
{
	buildHeap();
	int temp = heapsize;
	
	for(int i = (temp-1); i > 0; i--)
	{
		swap(A[0], A[i]);
		heapsize = heapsize-1;
		heapify(0);
	}
	
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int heap::extractMax()
{
	int max;
	
	if(heapsize < 1){
		cout << "Error, Heap underflow.\n";
		return 0;
	}
	
	else
	{
		max = A[0];
		A[0] = A[heapsize-1];
		A[heapsize-1] = 0;
		heapsize = heapsize-1;
		heapify(0);
		return(max);
	}
	
}

int heap::max()
{
	int max = 0;
	
	for(int i = 0; i < 100; i++)
	{
		if(A[i] > max)
			max = A[i];
	}
	
	return max;
}

void heap::print()
{
	int i = 0;
	
	while(A[i] != 0)
	{
		cout << A[i] << " ";
		i++;
	}

	cout << endl;
}
