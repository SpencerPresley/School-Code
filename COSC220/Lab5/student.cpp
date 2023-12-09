//Programmer: Spencer Presley

#include <iostream>
#include "student.h"
using namespace std;

Student::Student()
{
	cout << "Last Name: ";
	cin >> lastName;
	cout << endl;
	cout << "First Name: ";
	cout << endl;
	cin >> firstName;
	cout << endl;
	cout << "ID Number: ";
	cin >> idNumber;
	cout << endl;
}

void Student::printStudent()
{
	cout << "Last Name: " << lastName << endl << "First Name: " << firstName << endl << "ID Number: " << idNumber << endl;
}
