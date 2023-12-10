//Programmer: Spencer Presley
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_SIZE 1

void err_sys(char *str) {printf("%s", str), exit(1);} /* for error printing */

int main(int argc, char **argv)
{
	int mkd, fd, fd2, chd, lnk;
	char buff[BUFFER_SIZE];
	umask(0);
	mkd = mkdir("/Users/spencerpresley/Dir1", 0777);
	if(mkd < 0) err_sys("mkdir error\n");
	mkd = mkdir("/Users/spencerpresley/Dir2", 0777);
	if(mkd < 0) err_sys("mkdir error\n");
	mkd = mkdir("/Users/spencerpresley/Dir2/Dir21", 0777);
	if(mkd < 0) err_sys("mkdir error\n");
	
	/* for copying hello and hello exucutable */
	chd = chdir("/Users/spencerpresley");
	fd = open("hello", O_RDONLY);
	chd = chdir("/Users/spencerpresley/Dir2/Dir21");
	fd2 = open("hello", O_WRONLY | O_CREAT, 0777);
	while(read(fd, buff, BUFFER_SIZE) > 0)
	{
		write(fd2, buff, BUFFER_SIZE);
	}
	
	if(fd < 0) err_sys("File Creation Error\n");
	chd = chdir("/Users/spencerpresley/cosc350/lab4/task3.1");
	if(chd < 0) err_sys("chdir error\n");
	
	lnk = symlink("/Users/spencerpresley/Dir2/Dir21", "/Users/spencerpresley/Dir1/toDir21");
	if(lnk < 0) err_sys("Symbolic Link Error\n");
	lnk = symlink("/Users/spencerpresley/Dir2/Dir21/hello", "/Users/spencerpresley/Dir1/toHello");
	if(lnk < 0) err_sys("Symbolic Link Error\n");
	
	return 0;
	
}


