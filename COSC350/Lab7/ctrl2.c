#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*  did ./ctrl2& to run in background then did ps to see the process, then used kill {pid} to kill it */

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
}

int main()
{
	struct sigaction act;

	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);

	while(1)
	{
		printf("Hello World!\n");
		sleep(1);
	}
}
