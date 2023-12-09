// Programmer: Spencer Presley

#include "d_stree.h"
#include "int.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <utility>
using namespace std;

int main()
{
	int ARRSIZE = 10000;
	int arr[ARRSIZE];
	int RANDOMVALUE = 7;
	srand(time(NULL));
	stree <integer>tree;
	
	for(int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = rand()%(RANDOMVALUE); 
	}
	
	for(int j = 0; j < ARRSIZE; j++)
	{
		if(tree.findNode(arr[j])==NULL)
        	{
			integer obj(arr[j]);
            		tree.insert(obj);
        	}
	
		else
		{
			(tree.findNode(arr[j])->nodeValue).incCount();
		}				
	}

	for(int k = 0; k < RANDOMVALUE; k++)
	{
		integer obj(k);
		cout << tree.findNode(obj)->nodeValue;
	}
	cout << endl;
	tree.displayTree(10);
	return 0;
}
