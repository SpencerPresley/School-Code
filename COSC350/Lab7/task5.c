#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
// not strictly for sigquit but for this program use it to reset sigquit so it can keep working
void resetSigQuit(int sig)
{
	return;
}

int main()
{
	sigset_t new, old; /* new is new action, old stores previous action */

	sigaddset(&new, SIGINT); // adds ^c to set
	sigaddset(&new, SIGQUIT); // adds ^\ to the set

	sigprocmask(SIG_BLOCK, &new, &old); // Block set of blocked signals (union of current set and set argument)

	// first loop
	printf("Begin first loop\n");
	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	signal(SIGQUIT, &resetSigQuit); /* reset sigquitt so only have ^c signal */
	sigdelset(&new, SIGINT); /* gets rid of ^\ from set */
	sigprocmask(SIG_UNBLOCK, &new, &old); /* removes blocked signals from set */
	signal(SIGQUIT, SIG_DFL); /* sets SIGQUIT back to default behavior */

	printf("Begin second loop\n");
	for(int j = 1; j <=5; j++)
	{
		printf("%d\n", j);
		sleep(1);
	}

	sigprocmask(SIG_SETMASK, &old, NULL); /* rests mask so last action is current action and last action is null */

	exit(0);
}
