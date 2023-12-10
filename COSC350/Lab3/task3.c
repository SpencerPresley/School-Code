// Programmer: Spencer Presley
/* Goal: Write a C program to copy contents of any readable file (foo) to a file (clone1) with open files. (Created ouput file mode will be rw-rw-rw*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void err_sys(char *string) // To print what error occurred
{
        printf ("%s", string);
        exit (1);
}

#define BUFFER_SIZE 32

int main(int argc, char** argv)
{
        int InFileDes, OutFileDes, nbyte; // declaring vars
        char buffer[BUFFER_SIZE]; // declaring buffer
        umask(0); // clearing umask to set perms
        InFileDes = open(argv[1], O_RDONLY); // stores descriptor returned by open function
        OutFileDes = open(argv[2], O_WRONLY | O_CREAT, 0666); // open file specified in argument 2 as write only, creates if doesn't exist, gives rw-rw-rw- perms

        while ((nbyte = read(InFileDes, buffer, BUFFER_SIZE)) > 0)
                if (write (OutFileDes, buffer, nbyte) != nbyte)
                        err_sys ("Write Error");
        if (nbyte < 0) // checks last iteration
                err_sys ("Read Error");

        close (InFileDes); // closing files
        close (OutFileDes);
        exit (0);
}

