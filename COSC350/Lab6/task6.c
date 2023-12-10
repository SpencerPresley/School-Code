// Programmer: Spencer Presley

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

// checks if character is a digit
int isDigit(char c)
{
	if(c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

// error printing
void err_sys(char *str){printf("%s", str); exit(1);}

int main(int argc, char **argv)
{	
	// check # of args
	if(argc != 2)
		err_sys("Invalid number of inputs\n");
	
	// create buffer, file descriptors, and set offset to 0
	char buffer[BUFFER_SIZE];
	int fd, rd, out1, out2, offset = 0;
	
	// opening input file and checking for error
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		err_sys("File open error\n");
	
	// clearing umask
	umask(0);
	
	// opening out files and checking for error, permissions set as rw-rw-rw
	out1 = open("parent.txt", O_WRONLY | O_CREAT, 0666);
	if(out1 < 0)
		err_sys("Create file error\n");
	out2 = open("child.txt", O_WRONLY | O_CREAT, 0666);
	if(out2 < 0)
		err_sys("Create file error\n");
	
	// making pid and forking
	pid_t pid;
	pid = fork();
	
	// use pread to navigate and read file
	while(pread(fd, buffer, BUFFER_SIZE, offset) > 0)
	{
		// if child
		if(pid == 0)
		{	
			// Check if character is not a digit or new line, if either of those things it writes to child.txt
			if(isDigit(buffer[0]) == 0 || buffer[0] == '\n')
				write(out2, buffer, BUFFER_SIZE);
		}

		else
		{
			// check if character is a number or new line, if either of them writes to parent.txt
			if(isDigit(buffer[0]) == 1 || buffer[0] == '\n')
				write(out1, buffer, BUFFER_SIZE);
		}
		
		// incrementing offset
		offset++;
	}
	
	// closing file
	close(fd); close(out1); close(out2);
	exit (0);
}
