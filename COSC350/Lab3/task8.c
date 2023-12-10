// Programmer: Spencer Prelsey
// task8.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1
#define FILE_MODE ( S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) // GIVES rw-rw-rw- permissions

void err_sys(char *string) // To print what error occurred
{
        printf ("%s", string);
        exit (1);
}

int main(int argc, char** argv)
{
	umask(0); // resetting umask so I can set permissions
	int inFile, outFile, i, n;
	char buffer;

	if(argc < 3 || argc > 3) // less than 2 or more than 2 is not a valid # of files
		err_sys("Please (only) enter an input and output file.");

	inFile = open(argv[1], O_RDONLY); // opening first file as read only
	if(inFile < 0) // if error
	{
		close(inFile);
		err_sys("Read Error (inFile)");
	}

	outFile = open(argv[2], O_WRONLY | O_CREAT, FILE_MODE); // opening second file as write only
	if(outFile < 0) // if error
	{
		close(inFile);
		close(outFile);
		err_sys("Write Error (OutFile)");
	}
	
	dup2(outFile, 1);

	while(( i = read(inFile, &buffer, BUFFER_SIZE) > 0 ))
	{
		if(buffer == '\n')
		{
			printf("\n");
			continue;
		}


		n = (int)buffer;
		
		/*if( write(outFile, buffer, BUFFER_SIZE) == -1)
		{
			close(inFile);
			close(outFile);
			err_sys("Write Error");
		}

		i--;*/
		printf("%d", n);

	}

	exit (0);
}
