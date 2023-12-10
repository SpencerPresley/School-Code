/* Programmer: Spencer Presley
	Task: Palindrome checker using 2 file descriptors, 1 file descriptor and then dup2 the 2nd 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

void err_sys(char *str){printf("%s", str); exit(1);} /* for error printing */

int palindrome(int fd1, int fd2)
{
	char buff[BUFFER_SIZE]; /* buffer to store characters */
	char buff2[BUFFER_SIZE]; /* 2nd buffer */
	int offset = 0, plnd = 1; int offset1, rd, rd2; /* To determine where to place lseek, rd and rd2 used for storing read() output*/
	offset1 = lseek(fd2, -2, SEEK_END); /* sets offset1 value to last character of file so when I read I know where in the file to read for fd2 during first iteration */
	while(1)
	{
		lseek(fd1, offset, SEEK_SET); /* sets how far into the file to read fd1 */
		rd = read(fd1, buff, BUFFER_SIZE); /* reads that character from fd1 */
		lseek(fd2, offset1, SEEK_SET); /* sets how far into the file to read fd2 */
		rd2 = read(fd2, buff2, BUFFER_SIZE); /* reads that character from fd2 */
		if(buff[0] != buff2[0]) /* makes sure they're the same char, if not it's not a palindrome so set pldn to 0 and break */
		{
			plnd = 0; 
			break;
		}
		offset++; /* increment offset to know where to read from next iteration */
		offset1 = offset1 - 2; /* decrements offset1 by 2 to know where to read from next iteration, -2 since need to move cursor back from the read and then again to go back a char */
		if(offset > offset1) /* if offset > offset1 through middle of file, if it hasn't failed yet then it's a palindrome and break */
			break;
	}

	return plnd; /* return value of plnd */
}

int main(int argc, char **argv)
{
	if(argc != 2) err_sys("Invalid Number of Inputs\n");
	
	int fd1, fd2, pal; /* fd1 and fd2 file descriptors, pal to store return of palindrome function */
	char buff[BUFFER_SIZE];
	
	fd1 = open(argv[1], O_RDONLY); /* assigning value of open file at argument 2 to fd1, opens file as read only */
	if(fd1 < 0) err_sys("Open File Error\n"); /* checks for open file error */
	fd2 = dup(fd1); /* duping fd1 as fd2 */
	if(fd2 < 0) err_sys("File Duplication Error\n");
	
	pal = palindrome(fd1, fd2); /* calling palindrome */
	if(pal == 1)
		printf("File contents are a palindrome\n"); 
	else
		printf("File contents are NOT a palindrome\n");
	
	exit (0);	
}
