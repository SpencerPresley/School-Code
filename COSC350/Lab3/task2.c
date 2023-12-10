// Programmer: Spencer Presley
/* Goal: Write a C program to copy contents of any readable file (foo) to a file (clone1) with open files. (Created ouput file mode will be rw-rw-rw*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void err_sys(char *string) // To print what error occurred
{
	printf ("%s", string);
	exit (1);
}

#define BUFFER_SIZE 1

int main(int argc, char** argv)
{
	int InFileDes, OutFileDes, nbyte;
	char buffer[BUFFER_SIZE];
	umask(0);
	InFileDes = open(argv[1], O_RDONLY); // stores descriptor returned by open function
	OutFileDes = open("clone1", O_WRONLY | O_CREAT, 0666); // opens clone1 file as write only, if doesn't exist creates it, 0666 gives it rw-rw-rw- permissions

	while ((nbyte = read(InFileDes, buffer, BUFFER_SIZE)) > 0) // reads input file and stores BUFFER SIZE bytes of info in buffer
		if (write (OutFileDes, buffer, nbyte) != nbyte) // writes what was in buffer
			err_sys ("Write Error");
	if (nbyte < 0) // checks last iteration
		err_sys ("Read Error");

	close (InFileDes); // closing files
	close (OutFileDes);
	exit (0);
}
