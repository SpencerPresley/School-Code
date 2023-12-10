// Programmer: Spencer Presley
// Goal: Write C program using lseek to append 2 files (foo, foo1) into a 3rd new file (foo12)
// File permissions for foo12 will be rwxrw---
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
	int foo, foo1, foo12; // foo = Input File 1, foo1 = Input File 2, foo12 = Output File
	char buffer[BUFFER_SIZE];

	foo = open(argv[1], O_RDONLY); // open foo file (first file entered as argument) as read only
	foo1 = open(argv[2], O_RDONLY); // open foo1 file (second file entered as argument) as read only
	if(foo < 0 || foo1 < 0) // 
		err_sys("Input Error");

	umask(0); // clearing umask
	foo12 = open("foo12", O_WRONLY | O_CREAT, FILE_MODE); // opens the file foo12 as write only, if it doesn't exist it's created. FILE_MODE gives it the modes previously defined.
	if(foo12 < 0) // Error writing or Creating
		err_sys("Output Error");

	while (( read(foo, buffer, BUFFER_SIZE ) == 1 ))
		write( foo12, buffer, BUFFER_SIZE ); // Writes contents of foo to foo12
	
	if(lseek(foo12, 0, SEEK_END) == -1);

	while (( read(foo1, buffer, BUFFER_SIZE ) == 1 ))
		write( foo12, buffer, BUFFER_SIZE ); // Writes contents of foo1 to foo12
	
	// Closing Files
	close(foo);
	close(foo1);
	close(foo12);
	
	exit (0);
}
