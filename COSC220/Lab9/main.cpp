// Menu for heap program

#include "heap.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Welcome to Build-A-Heap! The Most Fun You'll Ever Make! Where Best Friends Are Made!\n";
	
	heap a;
	int menu, key;
	bool flag = true;

	while(flag)
	{
		cout << "Enter 1 to insert an element into the heap, 2 to get max value, 3 to extract max value from the heap, 4 to print the heap, and 5 to sort the heap, print the sorted results, and exit the program: ";
		cin >> menu;
	
		switch(menu)
		{
			case 1:
				cout << "Enter value to insert into heap: ";
				cin >> key;
				a.insert(key);
				cout << endl << key << " was inserted into the heap\n";
				break;
			case 2:
				cout << "Max value of heap is: " << a.max() << endl;
				break;
			case 3:
				cout << "Element " << a.extractMax() << " was removed from the heap.\n";
				break;
			case 4:
				a.print();
				break;
			case 5:
				a.heapSort();
				a.print();
				flag = false;
				break;			
		}
	}
}
