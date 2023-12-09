// Programmer: Spencer Presley
// Date: 2/14/23

#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;

void deSelsort(int[], int);
void swap(int, int);
int binSearch(int[], int, int, int, int, int);

int binSearch(int arr[], int x, int low, int high, int sumFailCom, int sumSucCom)
{
/*	int ARRSIZE = 10000;
	int arr[ARRSIZE];
	srand(time(0));
	srand((unsigned)time(NULL));
	
	
	for(int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = rand()%100000;
	}
	cout << "past for 1" << endl;

	deSelsort(arr, ARRSIZE);
	cout << "sorted" << endl;
	
	int sumFailCom = 0; // record number of comparisons in all unsuccessful search 
	int sumSucCom = 0; // 
	int successTotal = 0;
	int RANDOMVALUES = 10000;

	int low = arr[0];
	int high = arr[ARRSIZE];

//	int x;
	bool found = false;

//	cout << "Enter number to be searched for: ";
//	cin >> x;*/
	
//	for(int j = 0; j < RANDOMVALUES; j++)
//	{
//		cout << "entered for loop" << endl;
//		int x = rand()%100000;
		while(low <= high)
		{
			cout << "inside bin search" << endl;
			int mid = (low+high)/2;
		
		/*	if(x != arr[mid])
			{
				sumFailCom++;
				// uh return? not exactly what i'm looking for, want to return the sum stuff. 
			}*/

			if(x == arr[mid])
			{
				sumSucCom++;
				return 1;
			//	found = true;
			
			}

			else if(x > arr[mid])
			{
				sumFailCom++;
				sumSucCom++;
				low = mid+1;
			}

			else
				sumFailCom=sumFailCom+2;
				high = mid-1;			
		}
	
		return -1;
		cout << "done with binsearch" << endl;
	
//	if(found)
//		successTotal++;
	}

	/*cout << "out of for loop" << endl;
	cout << sumSucCom << " " << sumFailCom << " " << successTotal << endl;

	cout << "Empirical Result for Worst-Case Comparison for Unsuccessful binary search: " << sumFailCom/(RANDOMVALUES-successTotal) << endl;
	cout << "Empirical Result for Worst-Case Comparison for Successful binary search: " << sumSucCom/successTotal << endl;	*/


void deSelsort(int arr[], int size)
{
	int j = 0;
	int i = 0;

	for(i=0, j=size-1; i<j; i++, j--)
	{
		int min = arr[i];
		int max = arr[i];
		int locMin = i;
		int locMax = size-1;

		for(int k = i; k <= j; k++)
		{
			if(arr[k] < min)
			{
				min = arr[k];
				locMin = k;
			}

			if(arr[k] > max)
			{
				max = arr[k];
				locMax = k;
			}
		}

		if(arr[i] == arr[locMin])
			swap(arr[i], arr[locMin]);

		if(arr[locMin] == max)
			swap(arr[j], arr[locMin]);
		else
			swap(arr[j], arr[locMin]);
	}
}

void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

#endif
