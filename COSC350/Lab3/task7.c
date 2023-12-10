// Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void err_sys(char *string) // for error printing
{
        printf ("%s", string);
        exit (1);
}

int str_conversion(char *str) // converts string to integer
{
	int n, i;
	n = 0; i = 0;
	while(str[i] != '\0')
	{
		n = (n*10) + (str[i] -48);
		i++;
	}

	return n;
}

int main(int argc, char** argv) 
{
	if(argc == 0) // no arguments passed
		err_sys("Enter at least one integer");
	
	int i = 1; // Used to iterate up to argc
	int tmp2 = 0; // Store value returned by str_conversion

	while(i != argc) // ensure get through all arguments
	{
		tmp2 += str_conversion(argv[i]); // tmp2 is the sum in this program
		i++;
	}

	printf("%s", "Sum Of Integers = "); printf("%d", tmp2);
	
	exit (0);
	
}
