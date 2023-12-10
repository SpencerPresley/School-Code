#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void endParent(int sig)
{
	printf("Parent Terminate\n");
	exit(0);
}

void endChild(int sig)
{
	printf("Child Terminated\n");
	kill(getppid(), SIGUSR2);
	exit(0);
}

int main()
{
	signal(SIGUSR1, endChild);
	signal(SIGUSR2, endParent);

	pid_t pid = fork(); // create child process

	if(pid != 0) // parent
	{
		while(1)
			printf("Parent Process\n");
	}

	if(pid == 0) // child
	{
		pid_t cpid = fork(); // creat gc
		
		if(cpid == 0) // gc process
		{
			for(int i = 1; i <= 10; i++)
				printf("Grandchild Process\n");

			kill(getppid(), SIGUSR1);
			
			if(getppid() == 1)
				exit(0);
		}

		else // child
			while(1)
				printf("Child Process\n");
	}

	exit(0);
}
