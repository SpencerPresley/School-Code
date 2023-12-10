// Programmer: Spencer Presley
// Goal: Do task5 but using pread instead of lseek

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1
#define FILE_MODE ( S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP )

void err_sys(char *string) // To print what error occurred
{
        printf ("%s", string);
        exit (1);
}

int main(int argc, char** argv)
{
        int foo, foorev, i; // foo = Input File 1, foorev = Output file, i used for looping later
	off_t offset = -1;
        char buffer[BUFFER_SIZE];

        foo = open(argv[1], O_RDONLY); // open foo file (first file entered as argument) as read only
        if(foo < 0) // 
                err_sys("Input Error");

        umask(0); // clearing umask
        foorev = open("foorev", O_WRONLY | O_CREAT, FILE_MODE); // opens the file foo12 as write only, if it doesn't exist it's created. FILE_MODE gives it the modes previously defined.
        if(foorev < 0) // Error writing or Creating
                err_sys("Output Error");
  	
	i = -1;
	while(read(foo, buffer, BUFFER_SIZE) == 1)
		i++;

        while(i > 0)
        {
		pread(foo, buffer, BUFFER_SIZE, i-1);
		write(foorev, buffer, BUFFER_SIZE);
		i--;
        }

        
        // Closing Files
        close(foo);
        close(foorev);

        exit (0);
}

