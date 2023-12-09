// Programmer: Spencer Presley
// Date: 11/24/22

#include "Students.h"
#include<iostream>

using namespace std;

//template<class DataType>
Students::Students()
{
	cout << "Enter Student's last name: ";
	cin >> lastName;
	cout << endl << "Enter Student's first name: ";
	cin >> firstName;
	cout << endl << "Enter Student's ID Number: ";
	cin >> idNumber;
	cout << endl;
}

Students::Students(int num)
{
	
	lastName[0] = '\0';
	firstName[0] = '\0';
	idNumber = num;
}

//template<class DataType>
bool Students::operator ==(const Students student)
{
	if(idNumber == student.idNumber)
		return true;
	return false;
}  

//template<class DataType>
bool Students::operator >(const Students student)
{
	if(idNumber > student.idNumber)
		return true;
	return false;
}

//template<class DataType>
bool Students::operator <(const Students student)
{
	if(idNumber < student.idNumber)
		return true;
	return false;
}

/*bool operator<(Students *s1, Students *s2)
{
	return s1->idNumber < s2->idNumber;
}*/

ostream& operator <<(ostream &stream, const Students &student)
{
	return cout << student.idNumber << endl;
	//return cout << "Last Name: " << student.lastName << endl << "First Name: " << student.firstName << endl << "Student ID: " << student.idNumber << endl;
}
