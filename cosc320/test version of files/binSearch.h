// Programmer: Spencer Presley

#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <iostream>

using namespace std;

//void deSelsort(int[], int);
//void swap(int, int);
//int binSearch(int[], int, int, int, int);

int binSearch(int arr[], int x, int low, int high, int &count)
{
//	cout << " in binsearch " << endl;
	while(low <= high)
	{
		count++;
//		cout << " in while " << endl;
		int mid = (low+high)/2;
//		cout << "done setting mid" << endl;
	
		if(arr[mid] == x)
		{
//			cout << "mid = x" << endl;
			count++;
			return 1;
		}
	
//		cout << "moving to next if" << endl;

		if(arr[mid] < x)
		{
	//		cout << "comparing mid<x" << endl;
//			count++;
			low = mid+1;
	//		cout << "leaving" << endl;
		}

		else
		{
	//		cout << "in else" << endl;
//			count+=2;
			high = mid-1;
	//		cout << "leaving";
		}
	}
	
	return -1;
}

/*void deSelsort(int arr[], int size)
{
	cout << " in sort" << endl;
	//int j=0;
	//int i=0;
	
	for(int i = 0, j=size-1; i<j; i++, j--)
	{
		cout << " in for in sort " << endl;
		int min = arr[i];
		int max = arr[i];
		int locMin = i;
		int locMax = i;
		
		for(int k = i; k <= j; k++)
		{
			if(arr[k] > min)
			{
				max = arr[k];
				locMax = k;
			}

			else if(arr[k] < max)
			{
				min = arr[k];
				locMin = k;
			}
		}
		
		swap(arr[i], arr[locMin]);

		//if(arr[i] != arr[locMin])
		//	swap(arr[i], arr[locMin]);
		
		if(arr[locMin] == max)
			swap(arr[j], arr[locMin]);

		else
			swap(arr[j], arr[locMax]);
	}
}

void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}*/

#endif
