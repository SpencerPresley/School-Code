#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
	pid_t pid = fork();

	char *childStr = "Hi, Mom\n";
	int status;
	char parentStr[sizeof(childStr) / sizeof(char)];

	if(pid == 0) // child
	{
		int out = creat("foo.txt", 0666);
		write(out, childStr, sizeof(childStr) / sizeof(char));
	}

	else // parent
	{
		wait(&status);

		int in = open("foo.txt", O_RDONLY);
		read(in, parentStr, sizeof(childStr) / sizeof(char));
		printf("My son said %s", parentStr);
	}

	exit(0);
}
