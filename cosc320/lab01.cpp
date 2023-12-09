// Programmer: Spencer Presley
// Date: 2/8/23
#include "deSelsort.h"
#include <iostream>

using namespace std;

void deSelsort(int[], int);
int main()
{
	
	//int arr[8] = {13,5,2,25,47,17,8,21};
	cout << "Unsorted Array: ";
	
	for(int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << "Sorted Array: ";

	deSelsort(arr, size);

	for(int j = 0; j < 8; j++)
	{
		cout << arr[j] << " ";
	}

	cout << endl;

	return 0;
}

void deSelort(int arr[8])
{
//	int lowest = arr[0];
//	int max = arr[7];
	
//	int i = 0;
	
	
	/*
	while(i<8)
	{
		i++;
		if(arr [i] > max)
			max = arr[i];
		if(arr[i] < lowest)
			lowest = arr[i];

		if(lowest != arr[0])
		{
			int tmp = arr[i];
			arr[i] = arr[0];
			arr[0] = lowest;
		}

		if(max != arr[0])
	}
	*/

	for(int i = 0; i < size-1; i++)
	{
		int min = i;
	//	int max = 7;

		for(int j = i+1; j < size; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}

		if(min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;	
		}	
	}
}

