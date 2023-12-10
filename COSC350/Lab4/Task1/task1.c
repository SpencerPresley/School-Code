// Programmer: Spencer Presley
// task1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#define BUFFER_SIZE 1

void err_sys(char *string){printf("%s", string); exit(1);} /* for error printing */

int main(int argc, char **argv)
{
	if(argc < 2){err_sys("Error: Enter input file");} /* checks for valid # of arguments on command line */
	int input, alpha, num, other, copy, rd, rd2; /* declaring needed integer variables, rd is used to store read() output, rd2 used for when I need to copmare multiple buffers */
	int i = 0; int j = 0; /* keep track of what iteration we are in loop for use later, used to know where to write characters in copy file */
	char buffer[BUFFER_SIZE]; /* general use buffer to store characters in */

	umask(0); /* clearing umask to set permissions for files */
	input = open(argv[1], O_RDONLY); /* open input file */
	alpha = open("alpha", O_CREAT | O_RDWR, 0600); /* create alpha file with permissions rw------- */
	num = open("num", O_CREAT | O_RDWR, 0600); /* create num, same perms as alpha */
	other = open("other", O_CREAT | O_RDWR, 0600); /* create open, same perms as alpha and num */
	copy = open("copy", O_CREAT | O_WRONLY, 0666); /* create copy, same perms as alpha, num, and other */
	
	if(input < 0 || alpha < 0 || num < 0 || other < 0 || copy < 0) {err_sys("Error opening/ creating files");} /* if any can not open or be created print error and exit */
	
	while((rd = read(input, buffer, BUFFER_SIZE)) > 0) /* while rd > 0 as in file isn't done keep going */
	{
		if(buffer[0] == '\n') /* if buffer is new line character print new line to all files and then continue as to not add unwanted extra characters from other conditionals */
		{
			write(alpha, "\n", BUFFER_SIZE);
			write(num, "\n", BUFFER_SIZE);
			write(other, "\n", BUFFER_SIZE);
			continue;
		}

		if(( buffer[0] >= 'a' && buffer[0] <= 'z' ) || ( buffer[0] >= 'A' && buffer[0] <= 'Z' )) /* if buffer stores an alphabetical character write character to alpha */
			write(alpha, buffer, BUFFER_SIZE);
		else
			write(alpha, " ", BUFFER_SIZE); /* if buffer does not store alphabetical character write a space to alpha */

		if(buffer[0] >= '0' && buffer[0] <= '9') /* if buffer stores a numerical charactre write character to num */
			write(num, buffer, BUFFER_SIZE); 
		else
			write(num, " ", BUFFER_SIZE); /* if buffer does not store numerical character write a space to num */

		if( (!(buffer[0] >= 'a' && buffer[0] <= 'z' ) || !(buffer[0] >= 'a' && buffer[0] <= 'z')) && !(buffer[0] >= '0' && buffer[0] <= '9')) /* if character is neither alphabetical nor numerical write character to other */
			write(other, buffer, BUFFER_SIZE);
		else
			write(other, " ", BUFFER_SIZE); /* if character is alphabetical or numerical write a space to other */
	}

	lseek(alpha, 0, SEEK_SET); lseek(num, 0, SEEK_SET); lseek(other, 0, SEEK_SET); lseek(copy, 0, SEEK_SET); /* moving cursor back to beginning of file for every file aside from input */

	while((rd = read(alpha, buffer, BUFFER_SIZE)) > 0) /* initially write contents of alpha to copy */
	{
		write(copy, buffer, BUFFER_SIZE);
	}
	
	while((rd = read(num, buffer, BUFFER_SIZE)) > 0) /* handles writing num file contents to copy */
	{
		if(buffer[0] != ' ') /* if buffer storing character from num file isn't a space then it's a number and we write that character into copy in place of the existing space in that location */
		{
			lseek(copy, i, SEEK_SET); /* moves the cursor over i times. i tracks where we are in the loop, allows program to know where to insert the character into copy */
			write(copy, buffer, BUFFER_SIZE); /* writing */
		}

		i++; /* increment i */
	}
	

	lseek(copy, 0, SEEK_SET); /* moving cursor back to front of copy */
	while((rd = read(other, buffer, BUFFER_SIZE)) > 0) /* handles writing other file to contents of copy */
	{
		if(buffer[0] != ' ') /* if buffer storing character from other file is a non-space then need to write that character to copy in place of the existing space in that location of copy */
		{
			lseek(copy, j, SEEK_SET); /* moves cursor to correct location in file, correct location is tracked by how far we are in the file which is = to amount of iterations, and j tracks iterations */
			write(copy, buffer, BUFFER_SIZE); /* writing */
		}

		j++; /* increment j */
	}
	
	close(input); close(alpha); close(num); close(other); close(copy); /* closing all files */
	exit (0); /* succesful program exit */
}
