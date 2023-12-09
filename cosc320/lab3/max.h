//Programmer: Spencer Presley
#ifndef MAX_H
#define MAX_H

#include "d_tnode.h"
#include <iostream>
using namespace std;

int findmax(tnode<int> *r)
{
	if(r == nullptr)
	{
		return -1;
	}
	
	int max = r->nodeValue;
	int leftMax = findmax(r->left);
	int rightMax = findmax(r->right);

	if(max < leftMax)
		max = leftMax;
	if(max < rightMax)
		max = rightMax;
	
	return max;
}

#endif
