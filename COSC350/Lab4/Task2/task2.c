// Programmer: Spencer Presley
/* Task2.c 
   Write a C main function that takes one command-line argument, the name of an input file. Input file contains exactly one integer spread out over a signle line of up to 80 characters. For example, the integer 3579
   is embedded in the line az3mqrm5t?7!z*&gqmtzt9v. Your program uses system calls to do the following:
	a. open and read input file, accumulating discovered digit characters into a character array (string).
	b. Convert the string to an integer. (Define your own atoi function).
	c. Add 10 to the integer
	d. Convert sum back to a string (define your own itoa function)
	e. make a system call to write the string to standard output.
*/

// includes
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1 // for reading into buffer

void err_sys(char *str) // for printing errors
{
	printf("%s", str); // prints string passed in which specifies what the error was
	exit (1); // unsuccesful program run, exits
}

// converts string to integer (atoi)
int st_to_int(char *str)
{
	int n = 0; int i = 0;
	while(str[i] != '\0')
	{
		n = (n*10) + (str[i] - '0');
		i++;
	}
	
	return n;
}

// converts integer to string (itoa)
/*void int_to_st(int num, char *str)
{
	sprintf(str, "%d", num);	
}*/

void int_to_st(int num, char *str)
{
	int neg = 0, tmp = num, length = 0; /* neg used as flag to check if num is negative, tmp used to manipulate to figure out length of string without changing num, length will be used to store length of string */
	int i; /* used for iterating */

	if(num < 0) /* if num is negative set neg = 1 and make num positive */
	{
		neg = 1;
		num = -num;
	}

	if(num == 0) /* case if num is 0 */
	{
		*str = '0'; /* put '0' into str */
		str++; /* go up one spot */
		*str = '\0'; /* put null character into str */
		return; /* return void */
	}

	while(tmp > 0) /* finds length of string */
	{
		length++; /* update length each iteration */
		tmp = tmp/10; /* continue deviding tmp by 10 until it's 0 to find length */
	}

	i = length + neg; /* assign i as size of array, if neg = 1 adds an extra space for '-' if it's 0 won't add any extra index's to str array */

	while(i > -1) /* assigns all the way down the array */
	{
		i--;

		if(neg == 1 && i == 0) /* if neg was 1 then break when i = 0 to save that spot for '-' */
			break;
		
		str[i] = (num % 10) + '0'; /* storing proper character at index of i in str */
		num = num/10; /* devide num by 10 to move to next digit next iteration */
	}

	if(neg == 1) /* if neg =1 add '-' at index 0 */
		str[i] = '-';

	return;


}

int main(int argc, char **argv)
{
	if(argc < 2)
		err_sys("Must enter the file");
	
	if(argc > 2)
		err_sys("Enter only one file");

	int inFile; int i; int num; int strIndex = 0;
	char buffer[BUFFER_SIZE];
	char str[80]; // to store numerical characters

	inFile = open(argv[1], O_RDONLY); // open file
	if(inFile < 0)
	{
		err_sys("Read Error");
	}
	
	while((i = read(inFile, buffer, BUFFER_SIZE)) > 0)
	{
		if(isdigit(buffer[0])) // check if character is between '0' and '9'
		{	
			// if it is store in char str at strIndex then increment strIndex 
			str[strIndex++] = buffer[0]; 
		}
	}

	str[strIndex] = '\0'; // make last position null character
	close(inFile); // close file
	
	num = st_to_int(str); // convert str into integer and store it in num
	num+=10; // add 10 to n
	int_to_st(num, str); // convert num to string store in str array
	printf("New String: %s\n", str); // print new string
	
	exit(0); // exit program succesfully
	
	
}
