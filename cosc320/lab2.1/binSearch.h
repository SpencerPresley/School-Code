// Programmer: Spencer Presley

#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <iostream>

using namespace std;


int binSearch(int arr[], int x, int low, int high, int &count)
{
	while(low <= high)
	{
		count++;
		int mid = (low+high)/2;
	
		if(arr[mid] == x)
		{
			count++;
			return 1;
		}
	

		if(arr[mid] < x)
		{
			low = mid+1;
		}

		else
		{
			high = mid-1;
		}
	}
	
	return -1;
}


#endif
