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
void sort(int[], int);

int main()
{
	int ARRSIZE = 10000;
	int arr[ARRSIZE];
	int RandomLimit = 99999;
	srand(time(NULL));

	/*for(int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = rand()%100;
	}*/

	/*for(int j = 0; j < ARRSIZE; j++)
	{
		cout << arr[j] << " ";
	}*/
	cout << endl;

	for(int k = 0; k < ARRSIZE; k++)
	{
		arr[k] =(int) rand()%(RandomLimit);
//		cout << "first for loop" << endl;
	}
	
	cout << "exited for" << endl;
	deSelsort(arr, ARRSIZE);
	cout << "sorted" << endl;
	
	for(int k = 0; k < ARRSIZE; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;

	int low = 0;
	int high = ARRSIZE-1;

	int sumFailCom = 0;
	int sumSucCom = 0;
	int successTotal = 0;
	int RANDOMVALUES = 10000;
	
	for(int j = 0; j < RANDOMVALUES; j++)
	{
		int count = 0;
		cout << " in for" << endl;
		int x = rand()%(RandomLimit);
		cout << "x: " << x << endl;
	//	int x = j;
		int y = binSearch(arr, x, low, high, count);
		cout << " done with search ";
		if(y==1)
		{
			cout << "y = 1? " << y << endl;
			sumSucCom += count;
			successTotal++;
		}

		else
		{
			cout << "y != 1? " << y << endl;
			sumFailCom += count;
		}
//		cout << " done comparison " << endl;
		cout << "cout: " << count << endl;
	}

	cout << sumSucCom << " " << sumFailCom << " " << successTotal << endl;
	cout << "unsuc: " << sumFailCom/(RANDOMVALUES-successTotal) << endl;
	cout << "Suc: " << sumSucCom/successTotal << endl;
	
	return 0;
}

void deSelsort(int arr[], int size)
{
	int j = 0;
	int i = 0;
//	cout << " in sort " << endl;
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
//				cout << "arr-k " << arr[k] << " max " << max << endl;
				min = arr[k];
				locMin = k;
//				cout << "arr-k " << arr[k] << " max " << max << endl;
			}
		
			else if(arr[k] > max)
			{
//				cout << " arr-k " << arr[k] << " min " << min << " locmin " << locMin << endl;
				max = arr[k];
				locMax = k;
//				cout << " arr-k " << arr[k] << " min " << min << " locmin " << locMin << endl;
			}
		}
		
//		cout << " out of for loop, arr-i " << arr[i] << " arr-locMin " << arr[locMin] << endl;
		
	//	swap(arr[i], arr[locMin]);
		
		if(arr[i] != arr[locMin])
		{
//		cout << " first if " << arr[i] << " " << arr[locMin] << endl;
		swap(arr[i], arr[locMin]);
//		cout << " arr-i " << arr[i] << " arr-locMin " << arr[locMin] << endl;
		}
	//	swap(arr[i],arr[locMin]);
		
		if(arr[locMin]==max)
		{
//			cout << arr[j] << " " << arr[locMin] << endl;
			swap(arr[j], arr[locMin]);
//			cout << arr[j] << " " << arr[locMin] << endl;
		}

		else
		{
	//		cout << arr[j] << " " << arr[locMin] << endl;
			swap(arr[size-i-1], arr[locMax]);
	//		cout << arr[j] << " " << arr[locMin] << endl;
		}
	}
}

void sort(int arr[], int size)
{
	int i, j;
	for(i=0; i < size-1; i++)
	{
		for(j=0; j < size-i-1; j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}

/*void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}*/
