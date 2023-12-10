#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// convert string to int
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
	// checks for correct number of arguments
	if(argc != 5)
		err_sys("invalid number of arguments\n");
	
	// Nc = number of times to run child, Np = times to run parent, Tc = sleep time for child, Tp = sleep time for parent, sleepTime for case statement
	int Nc = st_to_int(argv[1]);
	int Np = st_to_int(argv[2]);
	int Tc = st_to_int(argv[3]);
	int Tp = st_to_int(argv[4]);
	int sleepTime;

	// making pid, message pointer, and n to specifiy when to run in switch
	pid_t pid;
	char *message;
	int n;
	
	// start fork
	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit (1);
		case 0:
			message = "This is the child";
			n = Nc;
			sleepTime = Tc;
			break;
		default:
			message = "This is the parent";
			n = Np;
			sleepTime = Tp;
			break;
	}
	
	for(; n > 0; n--)
	{
		puts(message);
		sleep(sleepTime);
	}

	exit(0);
}
