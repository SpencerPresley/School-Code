// Programmer: Spencer Prelsey
// My version of getenv()

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int err_sys(char *str){printf("%s", str); exit(1);}

int isEqual(char *str, const char *str1)
{
	// runs while the strings are equal and don't have the '=' character in the next spot
	while(*str == *str1 && *(str+1) != '=' && *(str1+1) != '=')
	{
		str++; str1++;
	}
	
	if(*str != *str1) /* checks if they're equal, if they're not returns 0 function exits, if they are if evals false and function returns 1 */
		return 0;
	return 1;
}
char *mygetenv(const char *name)
{
	char **env = environ; char *tmp; /* gets system environment varialbes from extern **environment and stores to **env. tmp used later */
	
	// Loop goes while env is not NULL and env and name are not equal
	while(*env != NULL && isEqual(*env, name) == 0)
	{
		env++;
	}
	
	if(*env == NULL)
		err_sys("(null)\n");
	
	tmp = *env; /* stores *env into tmp */
	
	// runs until *tmp is the character '="
	while(*tmp != '=')
	{
		tmp++;
	}
	tmp++; /* final iteration to move one spot past where loop ends */
	return tmp;
}	

int main(int argc, char **argv)
{
	if(argc != 2)
		err_sys("Invlaid number of inputs.\n");
	
	char *env = mygetenv(argv[1]);
	
	if(env != NULL)
		printf("%s\n", env);
	else
		err_sys("Environment Variables NULL\n");
	
	exit (0);
}
