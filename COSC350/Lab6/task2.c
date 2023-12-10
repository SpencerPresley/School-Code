// Progammer: Spencer Prelsey
// Open utmp file and read it's records

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utmp.h>

void err_sys(char *str){printf("%s", str); exit(1);}

int openUtmpFile()
{
	int utmp;
	utmp = open("/var/run/utmp", O_RDONLY);
	if(utmp < 0)
		err_sys("utmp open error\n");
	return utmp;
}

int main(int argc, char **argv)
{
	int fdUTMP, rd, records; /* file descrpitor for utmp file, variable to assign read() call to, variable to count amount of records */
	records = 0; /* giving records initial value of 0 */
	fdUTMP = openUtmpFile();
	
	struct utmp log;
	
	while((rd = read(fdUTMP, &log, sizeof(log))) > 0)
	{
		printf("Username: %s\n", log.ut_user);
		if(log.ut_type == 7)
			records++;
	}

	printf("Users currently logged in: %d\n", records);

	exit (0);
}
