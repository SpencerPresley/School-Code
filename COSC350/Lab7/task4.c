#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
static int first = 0; static int second = 0;

void handleSig(int sig)
{	
	if(sig == SIGUSR1)
	{
		printf("Hi Honey! Anything Wrong?\n");
		first = 1;
	}

	if(sig == SIGUSR2)
	{
		printf("Do you make trouble again?\n");
		second = 1;
	}
	
}



int main()
{
	signal(SIGUSR1, &handleSig);
	signal(SIGUSR2, &handleSig);

	// pid child1, cpid child2
	pid_t pid, cpid;

	// fork process to create first child
	pid = fork();
	
	if(pid != 0) // parent
	{	
		waitpid(pid, 0, 0); // waits for first child
		cpid = fork(); /* create second child */
	}

	if(pid == 0) // child
	{
		kill(getppid(), SIGUSR1); // sends signal to parent
		exit(0);
	}
	
	if(cpid == 0) // second child
	{
		kill(getppid(), SIGUSR2); // sends signal to parent
		exit(0);
	}

	else
	{
		waitpid(cpid, 0, 0); // waits for second child
	}

	exit(0);

}

