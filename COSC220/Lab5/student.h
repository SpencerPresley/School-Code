//Programmer: Spencer Presley

#ifndef STUDENT_H
#define STUDENT_H

// definition of struct type student

struct Student
{
	char lastName[20]; // student last name
	char firstName[20]; // student first name
	int idNumber; // student ID
	Student(); // constructor
	void printStudent(); // print a student info
};

#endif
