//Programmer: Spencer Presley
#include "header.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Node *insertNode(Node *list, Node *newNode) // Function to insert new node into list
{
	Node *tmp = list;
	
	if(tmp == nullptr)
	{
		list = newNode;
		return list;
	}

	if(newNode->itemNum < tmp->itemNum)
	{
		newNode->next = list;
		list = newNode;
		return list;
	}

	while((tmp->next != nullptr) && (tmp->next->itemNum < newNode->itemNum))
	{
		tmp = tmp->next;
	}

	if(tmp->next == nullptr)
	{
		tmp->next = newNode;
		return list;
	}

	else
	{
		newNode->next = tmp->next;
		tmp->next = newNode;
		return list;
	}
}

Node *deleteNode(Node *list, int key)
{
	Node *tmp = list; // declaration of tmp and setting it equal to list
	Node *tmp1;
	
	if(tmp == nullptr) // if list is empty
	{
		cout << "Nothing is in your cart yet!\n";
		return list;
	}

	if(tmp->itemNum == key) // if Node that matches key is first
	{
		cout << "Item removed from cart.\n";
		list = tmp->next;
		delete tmp;
		return list;
	}

	while((tmp->next != nullptr) && (tmp->next->itemNum < key)) // traverses list to find where the node to delete is located
	{
		tmp = tmp->next;
	}

	if(tmp->next->itemNum == key) // if item is at the end or in between two other items
	{
		cout << "Item removed from cart.\n";
		tmp1 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp;
	}

	else // if the item is not in the cart
	{
		cout << "Item is not in your cart.\n";
		return nullptr;
	}

	return list;

	
}

void printCurrent(Node *list, int current) // prints current node (the most recently added node)
{
	Node *tmp = list;
	
	if(tmp == nullptr)
	{
		cout << "Nothing currently present in list!\n";
	}

	else{
		while((tmp->next != nullptr) && (tmp->itemNum != current))
		{
		//	cout << "FUCK\n";
		//	cout << "Item Num: " << tmp->itemNum << " Item Name: " << tmp->itemName << " Unit: " << tmp->unit << " Tax: " << tmp->tax << " Subtotal: " << tmp->subtotal << endl;
			tmp = tmp->next;
		}
		if(tmp->itemNum == current)
			cout << "Item Num: " << tmp->itemNum << " Item Name: " << tmp->itemName << " Unit: " << tmp->unit << " Tax: " << tmp->tax << " Subtotal: " << tmp->subtotal << endl;
	}
}

void printFile(Node *list, double subt)
{
	fstream outdata;
	outdata.open("Presley_Spencer.txt", ios::out);
	outdata << "Item Number\t Item Name\t\t \tUnit\t Tax\t subtotal\n";
	outdata << "______________\t ___________________________  ______ _________ __________\n";

	outdata << fixed << showpoint;	

	Node *tmp = list;

	if(tmp == nullptr)
	{
		outdata << "Cart Is Empty.";
	}
	
	int i = 0;

	while(tmp->next != nullptr)
	{
		
		while(tmp->itemName[i] != '\0')
		{
			i++;
		}
		if(i < 10)
		{
			outdata << tmp->itemNum << "\t\t" << tmp->itemName << "\t\t\t\t" << setprecision(2) << tmp->unit << setw(8) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
		}
		else if(i >=10 && i < 17){
		outdata << tmp->itemNum << "\t\t" << tmp->itemName << "\t\t\t" << setprecision(2) << tmp->unit << setw(10) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
	}
	
		else if(i > 16 && i < 26)
		{
			outdata << tmp->itemNum << "\t\t" << tmp->itemName << "\t" << setw(10) << setprecision(2) << tmp->unit << setw(10) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
		}

		else
		{
			outdata << tmp->itemNum << "\t\t" << tmp->itemName << setw(10) << setprecision(2) << tmp->unit << setw(10) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
		}

		tmp = tmp->next;
	}

	if(i < 10)
	{
		outdata << tmp->itemNum << "\t\t" << tmp->itemName << "\t\t\t\t" << setprecision(2) << tmp->unit << setw(8) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
	}
	else if(i < 17)
	{
		outdata << tmp->itemNum << "\t\t" << tmp->itemName << "\t\t\t\t\t" << setw(10) << setprecision(2) << tmp->unit << setw(10) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
	}

	else if(i > 16 && i<26)
	{
		outdata << tmp->itemNum << "\t\t" << tmp->itemName << setw(10) << setprecision(2) << tmp->unit << setw(10) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
	}

	else{
	outdata << tmp->itemNum << "\t\t" << tmp->itemName << setw(10) << setprecision(2) << tmp->unit << setw(10) << setprecision(2) << tmp->tax << setw(10) << setprecision(2) << tmp->subtotal << endl;
	outdata << "Total: ________________________________________________________________ " << subt;
	}

	outdata.close();
}

double taxCalc(double price) // Calculates just the tax for single items
{
	double temp = price;
	return temp * .06;
}

double taxTotal(double price) // Calculates the total price including tax for single items
{
	double temp = price;
	double taxTotal = temp * .06;
	return price+=taxTotal;
} 

double taxCalc(double price, double units) // Calculates just the tax for items where users can buy more than one item
{
	double temp = price*units;
	return temp * .06;
}

double taxTotal(double price, double units) //Gets total price for items users can buy more than one of
{
	double temp = price*units;
	double taxTotal = temp * .06;
	return temp+=taxTotal;
}

double totalNoTax(double price, double units) //Gets cost for items without tax
{
	return price*units;
}
