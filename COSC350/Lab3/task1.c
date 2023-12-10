// Programmer: Spencer Presley
// Program Goal: Copy any readable file (foo) to a file (clone) without opening the input file.
// How I will accomplish it: write a bash script to do the copying and execute using a C program.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // STDIN_FILENO, STDOUT_FILENO

#define BUFFER_SIZE 1

void err_sys(char *str) // used for error printing
{
	printf ("%s",str);
	exit (1);
}

int main(int argc, char* argv[])
{
	int nbyte;	
	char buffer[BUFFER_SIZE]; // declaring variables
	
	while ((nbyte = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) // reads input file for buffer bytes
		if(write (STDOUT_FILENO, buffer, nbyte) != nbyte) // writes what was stored in buffer to output file
			err_sys ("Write Error"); // if write error

	if (nbyte < 0) // checks last input
		err_sys("Read Error");

	exit (0);
}
