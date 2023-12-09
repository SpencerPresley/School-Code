//programmer: Spencer Presley
//date: 11/22/22

#include<iostream>
using namespace std;

#ifndef STUDENTS_H
#define STUDENTS_H


struct Students
{
	char lastName[20];
	char firstName[20];
	int idNumber;
	Students();
	Students(int);
	bool operator == (const Students student);
//	friend bool operator< (Students*,Students*);
	bool operator > (const Students);
	bool operator < (const Students);
	friend ostream& operator << (ostream &stream, const Students &student);
};

#endif
