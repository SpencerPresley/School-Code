#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 1

void err_sys(char *str) {printf("%s", str); exit(1);}

int main(int argc, char **argv)
{
	if(argc != 3) err_sys("Invalid Input Number\n"); /* checks for correct number of arguments */
	struct stat buf; char buff[BUFFER_SIZE]; /* struct stat buffer and char buffer for reading under the last 2 conditions */
	char path[200]; char fileName[50]; /* char arrays for path and filename at end of path to be concatenated if needed */

	if(stat(argv[2], &buf) < 0) /* if the file/directory does not exist creates it as file via link */
	{
		if(link(argv[1], argv[2]) < 0) err_sys("Link Error 1\n"); /* linking argv[1] to path provided by argv[2] */
		/*if(link(argv[1], path) < 0)
		{
			int fd = open(argv[1], O_RDONLY);
			int fd2 = open(path, O_WRONLY);
			int rd;
			while((rd = read(fd, buff, BUFFER_SIZE)) > 0)
			{
				write(fd2, buff, BUFFER_SIZE);
			}
		}*/
		if(unlink(argv[1]) < 0) err_sys("Unlink Error 1\n"); /* unlinking argv[1] from pwd */
	}

	if(S_ISDIR(buf.st_mode)) /* if it's a direcotry */
	{
		sprintf(path, "%s", argv[2]); /* store argv[2] into path */
		sprintf(fileName, "/%s", argv[1]); /* concatenate /foo to end so can move the foo file from pwd */
		strcat(path, fileName); /* making new path with /foo at end */
	//	if(link(argv[1], path) < 0) err_sys("Link Error 2\n");
		if(link(argv[1], path) < 0) /* if file already exists overwrites it */
		{
			int fd = open(argv[1], O_RDONLY);
			int fd2 = open(path, O_WRONLY);
			int rd;
			while((rd = read(fd, buff, BUFFER_SIZE)) > 0)
				write(fd2, buff, BUFFER_SIZE);
		}
		if(unlink(argv[1]) < 0) err_sys("Unlink Error 2\n"); /* unlinks it */
	}

	if(S_ISREG(buf.st_mode)) /* if path provided leads to a regular file */
	{
//		if(link(argv[1], argv[2]) < 0) err_sys("Link Error 3\n");
		if(link(argv[1], path) < 0) /* links file, if it already exists overwrites it */
		{
			int fd = open(argv[1], O_RDONLY);
			int fd2 = open(argv[2], O_WRONLY);
			int rd;
			while((rd = read(fd, buff, BUFFER_SIZE)) > 0)
				write(fd2, buff, BUFFER_SIZE);
		}
		if(unlink(argv[1]) < 0) err_sys("Unlink Error 3\n"); /* unlinks argv[1] file, in this example foo */
	}

	exit (0);
}
