//Programmer: Spencer Presley

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "header.h"

using namespace std;

int main()
{	
	
	int currentLog = 0; // Number to track latest item added to list. Needed for printcurrent funct
	int itemNumber; // itemnumber, itemn, tax, selltype, price, units, pounds, and subt are for tracking purposes mostly. Needed things like selltype to know one what unique message to print out and to also to know which tax functions to call.
	char itemN[40];
	char tax;
	char sellType;	
	double price, units, pounds;
	double subt = 0.0;
	Node *list = nullptr; // linked list
	bool found = false; // bool flag to track if item user entered is in the file or not
	int ask; // prompt for what option 1-4 the user wants to pick

	ifstream indata;
	indata.open("item.txt", ios::in); // opening file

	if(!indata) // in case file could not be opened
	{
		cout << "File could not be opened!\n";
		exit(1);
	}

/*	fstream outdata;
	outdata.open("Presley_Spencer.txt", ios::out); // opening/creating output file*/

/*	outdata << "Item Number\t Item Name\t Unit\t Unit Price\t Tax\t Sub-Total\n"; //printing the table header to the file
	outdata << "_________________\t __________________\t _________________\t _________________\t ________\t ________________\t ______\t _____________\t\n";*/

	int selection = 1;
	int input; // variable used to take in what item user is searching for

//	outdata << fixed << showpoint;
	
	while(true) // loops forever
	{
		cout << "Welcome, enter the number that corresponds with the action you'd like to perform. 1 to insert, 2 to print selected item, 3 to delete item from the currently selected item list, 4 to print your receipt\n";
	/*	while(!(cin >> ask))
		{
			cout << "Invalid Data Type.\n";
			cout << "Please re-enter with correct data-type. To insert a new item press 1, to print the selected item press 2, to delete the current selected item from the list press 3, to print your reciept press 4, to terminate the program without printing the reciept press 5\n";
			cin.clear();
			cin.ignore(10, '\n');
		}*/

		cin >> ask;
	
		switch(ask)
		{
		
		case 1:{ // This case will insert a new Node into the list according to what item the user enters
			
			cout << "Enter item number for the item you want to add to the list: ";

			while(!(cin >> input)) // brings in 'input' variable, while loop to verify data type.
			{
				cout << "Invalid Input, please re-enter with valid data-type.\n";
				cout << "Enter item number for the item you want to add to the list: ";
				cin.clear();
				cin.ignore(10, '\n');
			}

			
			

			while(indata >> itemNumber >> itemN >> tax >> sellType >> price) // while the file is still going
			{
				if(itemNumber == input) // if it finds the item with id number that mtches input goes into if statement
				{
					found = true; // switches found to true once it finds it
					currentLog = input;
					Node *newNode = new Node; // creates and allocates memory to newNode
					newNode->next = nullptr;
					newNode->itemNum = itemNumber;
					int i = 0; 
					while(itemN[i] != '\0') // loop to copy itemname from here to the node variable
					{
						newNode->itemName[i] = itemN[i];
						i++;
					}

					if(sellType == 'p') // 'p' represent pounds in file
					{
						cout << "You've selected: " << newNode->itemName << endl << "How many pounds would you like? ";
						cin >> newNode->unit; //assigns amount of units to the unit variable in Node
						if(tax == 't') // if taxable
						{
							newNode->tax = taxCalc(newNode->unit, price);
							newNode->subtotal = taxTotal(newNode->unit, price);
							subt+=newNode->subtotal;
						}	

						else // if not taxable
						{
							newNode->tax = 0.0;
							newNode->subtotal = totalNoTax(newNode->unit, price);
							subt+=newNode->subtotal;
						}
						list = insertNode(list, newNode); // inserts node
					}

					if(sellType == 'n') // n represents items you buy by number in file
					{	
						cout << "You've selected: " << newNode->itemName << endl << "How many of them would you like? ";
						cin >> newNode->unit;
						
						if(tax == 't') // if taxable
						{
							newNode->tax = taxCalc(newNode->unit, price);
							newNode->subtotal = taxTotal(newNode->unit, price);
							subt+=newNode->subtotal;
						}

						else // if not taxable
						{
							newNode->tax = 0.00;
							newNode->subtotal = totalNoTax(newNode->unit, price);
							subt+=newNode->subtotal;
						}
	
						list = insertNode(list, newNode); // inserts node
					}

					if(sellType == 's') // s is for items that are sold as single units in the file
					{
						cout << "You've selected: " << newNode->itemName << endl;
						newNode->unit = 1.0;

						if(tax == 't') // if taxable
						{
							newNode->tax = taxCalc(price);
							newNode->subtotal = taxTotal(price);
							subt+=newNode->subtotal;
						}

						else // if not taxable
						{
							newNode->tax = 0.0;
							newNode->subtotal = price;
							subt+=newNode->subtotal;
						}
						
						list = insertNode(list, newNode); // inserts node
					}

				}

				else
				{
					continue; // if first line is not the input being searched for go to next line
				}	
			}
			if(!found) // if it doesn't find the item with the item number that matches input in the whole file
			{
				cout << "Invalid item number, try again\n";
			}
			found = false; // wasn't found
			indata.clear(); // back to top of file to read through next insertion
			indata.seekg(0);
			
			break; // ends case 1
			}
			
		case 2:{
			printCurrent(list, currentLog); // prints the current (most recently inserted) node
			break;	// ends case 2
		}

		case 3:{
			int key = 0;
			cout << "What's the item number for the item you'd like to delete? ";
			cin >> key;
			list = deleteNode(list, key);
			break;
		}

		case 4:{
			printFile(list, subt);
			break;
		}

		case 5:{
			return -1;
		}
	
		}	
	}
	
	indata.close();
	
	return 0;
}
