#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// string to int
int st_to_int(char *str)
{
	int n = 0, i = 0;
	while(str[i] != '\0')
	{
		n = (n*10) + (str[i] - 48);
		i++;
	}
	return n;
}

// error printing
void err_sys(char *str){printf("%s", str); exit(1);}

int main(int argc, char **argv)
{
	// check for correct # of args
	if(argc != 5)
		err_sys("invalid number of arguments\n");
	
	// Nc = times to run child, Np = time to run parent, Tc = sleep time child, Tp = sleep time parent, sleepTime for switch
	int Nc = st_to_int(argv[1]);
	int Np = st_to_int(argv[2]);
	int Tc = st_to_int(argv[3]);
	int Tp = st_to_int(argv[4]);
	int sleepTime;
	
	// making variables
	pid_t pid;
	char *message;
	int n;
	int exit_code;
	pid_t ppid; /* to get parent pid */
	ppid = getpid();
	
	// start fork
	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit (1);
		case 0:
			if((exit_code = execle("child", "child.c", "This is the child", argv[1], argv[3], NULL)) < 0) /* run child.c */
				err_sys("execl error\n");
			break;
		default:
			message = "This is the parent";
			n = Np;
			exit_code = 0;
			sleepTime = Tp;
			break;
	}
	
	if(pid != 0)
	{
		for(; n > 0; n--)
		{	
			printf("%s PID = %d\n", message, ppid);
			sleep(Tp);
		}

		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);

		printf("Child has finished: PID = %d\n", child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n", child_pid);
		else
			printf("Child terminated abnormally\n");
	}

	exit(exit_code);
}










