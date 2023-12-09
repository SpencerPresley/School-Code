#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "LL.cpp"
using namespace std;

Node *list = new Node;
Node *newNode = new Node;
float taxCalc(float a);
float taxCalc(float a, float b);
float taxTotal(float a);
float taxTotal(float a, float b);
float totalNoTax(float a, float b);

int main(){
	ifstream indata;
	indata.open("item.txt", ios::in);
	if(!indata){
		cerr<< "File cannot be opened" << endl;
		exit(1);
	}
	
/*	fstream outdata;
	outdata.open("Presley_Spencer.txt", ios::out);
	outdata << "Item Number\t Item Name\t Unit\t Unit price\t Tax\t subtotal\n";
	outdata << "___________\t _________\t ____\t __________\t ___\t ________\t\n";	*/

	int selection = 1;
	int input;
	int itemNum;
	char itemName[50];
	char tax;
	char sellType;
	float unitPrice;
	float pounds;
	float units;
	float subtotal = 0.00;
	bool found = false;
	
	outdata << fixed << showpoint;
	
	while(true){
	cout << "Add an item (0 to quit): ";
	while(!(cin >> input)){
		cout << "Invalid data type. \n";
		cout << "Add an item (0 to quit): \n";
		cin.clear();
		cin.ignore(10, '\n');
	}
	if(!input){
		break;
	}

		while(indata >> itemNum >> itemName >> tax >> sellType >> unitPrice){
			if(itemNum == input){
				found =true;
				newNode->itemNum = itemNum;
				newNode->itemName = itemName;
				
				if(sellType == 'p'){
					cout << "You've selected " << itemName <<  ": How many pounds would you like? \n";
					cin >> pounds;
					newNode->unit = pounds;
					if(tax == 't'){
					//	outdata << itemNum << "\t \t" << itemName << "  \t" << pounds << "\t" << unitPrice << "\t\t" << setprecision(2) << taxCalc(unitPrice, pounds) << "\t" << setprecision(2) << taxTotal(unitPrice, pounds) << endl;
						subtotal += taxTotal(unitPrice, pounds);
						newNode->tax = taxCalc(unitPrice, pounds);
						newNode->subtotal = subtotal;
					}

					else{
					//	outdata << itemNum << "\t \t" << itemName << "\t \t" << setw(3) << setprecision(2) <<  pounds << "\t" << setprecision(2) << unitPrice << "\t \t" << "0.00 \t" << setprecision(2) << totalNoTax(unitPrice, pounds) << endl;
						subtotal += totalNoTax(unitPrice, pounds);
						newNode->tax = 0;
						newNode->subtotal = subtotal;
					}
				}

				if(sellType == 'n'){
					cout << "You've selected " << itemName <<  ": How many would you like? \n";
					cin >> units;
					newNode->unit = units;
					if(tax == 't'){
					//	outdata << itemNum << "\t \t" << itemName << "\t" << units << "\t" << unitPrice << "\t" << setprecision(2) << taxCalc(unitPrice, units) << "\t" << setprecision(2) << taxTotal(unitPrice, units) << endl;
						subtotal += taxTotal(unitPrice, units);
						createNode->tax = taxCalc(unitPrice,units);
						createNode->subtotal = subtotal;
					}
					else{
					//outdata << itemNum << "\t \t" << itemName << "\t  \t" << units << "\t" << unitPrice << "\t\t" << "0.00" << "\t" << setprecision(2) << totalNoTax(unitPrice, units) << endl;
						subtotal += totalNoTax(unitPrice, units);
						newNode->tax = 0;
						newNode->subtotal = subtotal;
					}
				}

				if(sellType == 's'){
					cout << "You have purchased: " << itemName << endl;
					units = 1;
					newNode->unit = units;
					if(tax == 't'){
					//outdata << itemNum << "\t \t" << itemName << "\t" << units << "\t" << unitPrice << "\t" << setprecision(2) << taxCalc(unitPrice) << "\t" << setprecision(2) << taxTotal(unitPrice, units) << endl;
					subtotal+= taxTotal(unitPrice, units);
					newNode->tax = taxCalc(unitPrice);
					newNode->subtotal = subtotal;
				
					}
					else{
					//	outdata << itemNum << "\t \t" << itemName << "\t" << setw(3) << units << "\t" << setprecision(2) << unitPrice << "\t \t" << "0.00" << "\t" << setprecision(2) << unitPrice << endl;
						subtotal += unitPrice;
						newNode->tax = 0;
						newNode->subtotal = subtotal;
					}
				}
				insertNode(list, newNode);
			}
			else{
				continue;
			}
			
			
		}
		if(!found) {
			cout << "invalid item number, try again\n";
		}
		found = false;
		indata.clear();
		indata.seekg(0);
		
	}
	outdata << "Total";
	for(int i = 0; i < 62; i++){
		outdata << ".";
	}
	outdata << setprecision(2) << subtotal;
	
	return 0;
}

float taxCalc(float x){
	float temp = x;
	return temp * .06;
}

float taxTotal(float y){
	float temp = y;
	float taxTotal = temp * .06;
	return y+=taxTotal;
}

float taxCalc(float x, float y){
	float temp = x*y;
	return temp * .06;
}

float taxTotal(float x, float y){
	float temp = x*y;
	float taxTotal = temp * .06;
	return temp+=taxTotal;
}

float totalNoTax(float x, float y){
	return x*y;
}
