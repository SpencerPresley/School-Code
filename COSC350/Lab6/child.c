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
		n = (n*10) + (str[i] - '0');
		i++;
	}
	return n;
}

// error printing
void err_sys(char *str){printf("%s", str); exit(1);}

int main(int argc, char **argv)
{
	// check for correct # of args
	if(argc != 4)
		err_sys("invalid number of arguments\n");
	// Nc = number of times to run child, Tc = sleep time for child
	int Nc = st_to_int(argv[2]);
	int Tc = st_to_int(argv[3]);

	int n; 
	
	for(; Nc > 0; Nc--)
	{	
		printf("%s Child PID: %d\n", argv[1], getpid());
		sleep(Tc);
	}

	exit(0);
}







