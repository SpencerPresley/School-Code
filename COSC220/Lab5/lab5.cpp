//Programmer: Spencer Presley

#include "student.h"
#include "stack.h"
#include<iostream>

using namespace std;

int main()
{	
	bool flag = true;
	Stack<Student*> sstack;
	Stack<int> istack;
	
	int x;
	cout << "Integer or Student stack? 1 for student, 2 for integer. ";
	cin >> x;

	int menu;
	int data;

	while(flag)
	{	
		cout << "Menu Options: " << endl << "1 to push new data in the stack, 2 to pop data from the stack, 3 top display data in the top of stack, 4 to quit\n";
		cin >> menu;
		
		if(x==1)
		{
		
			switch(menu)
			{
				case 1:			
					if(sstack.isFull()){
						cout << "Stack is full!\n";
					}

					else{
						Student *newStudent = new Student;
						sstack.push(newStudent);
					}

					break;

				case 2:
					if(sstack.isEmpty())
					{
						cout << "Stack is empty!\n";
					}
			
					else{
						sstack.pop();
					}

					break;

				case 3:
					sstack.topStack()->printStudent();
					break;
				case 4:
					flag = false;
					break;
			}
		}

		else
		{
	
				
			switch(menu)
			{
				case 1:
					if(istack.isFull())
					{
						cout << "Stack is currently full!\n";
					}

					else
					{
						cout << "What data would you like to push? ";
						cin >> data;
						cout << endl;
						istack.push(data);			
					}

					break;

				case 2:
					if(istack.isEmpty())
					{
						cout << "Stack is currently empty!\n";
					}
					else
					{
						istack.pop();
					}

					break;
	
				case 3:
					cout << "Int: " <<  istack.topStack() << endl;
					break;
				case 4:
					flag = false;
					break;
			}
		}
	}

	return 0;
}
