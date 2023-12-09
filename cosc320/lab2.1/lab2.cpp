// Programmer: Spencer Presley

#include "binSearch.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
void swap(int &x,int&y)
{
	int temp = x;
	x = y;
	y = temp;
}
void deSelsort(int[], int);

int main()
{
	int ARRSIZE = 10000;
	int arr[ARRSIZE];
	int RandomLimit = 99999;
	srand(time(NULL));

	for(int k = 0; k < ARRSIZE; k++)
	{
		arr[k] =(int) rand()%(RandomLimit);
	}
	
	deSelsort(arr, ARRSIZE);
	

	int low = 0;
	int high = ARRSIZE-1;

	int sumFailCom = 0;
	int sumSucCom = 0;
	int successTotal = 0;
	int RANDOMVALUES = 10000;
	
	for(int j = 0; j < RANDOMVALUES; j++)
	{
		int count = 0;
		int x = rand()%(RandomLimit);
		int y = binSearch(arr, x, low, high, count);
		if(y==1)
		{
			sumSucCom += count;
			successTotal++;
		}

		else
		{
			sumFailCom += count;
		}
	}

	cout << "Unsuccessful: " << sumFailCom/(RANDOMVALUES-successTotal) << endl;
	cout << "Successful: " << sumSucCom/successTotal << endl;
	
	return 0;
}

void deSelsort(int arr[], int size)
{
	int j = 0;
	int i = 0;
	for(i = 0, j = size-1; i < j; i++, j--)
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
		
			else if(arr[k] > max)
			{
				max = arr[k];
				locMax = k;
			}
		}
		
		
		
		if(arr[i] != arr[locMin])
		{
		swap(arr[i], arr[locMin]);
		}
		
		if(arr[locMin]==max)
		{
			swap(arr[j], arr[locMin]);
		}

		else
		{
			swap(arr[size-i-1], arr[locMax]);
		}
	}
}

