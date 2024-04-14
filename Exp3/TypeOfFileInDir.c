// C program to check if the given number is a directory or a regular file in the current directory
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
void main()
{
    struct stat s;
    char file[20];
    printf("File:");
    scanf("%s", file);
    int i = stat(file, &s);
    if (S_ISDIR(s.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISREG(s.st_mode))
    {
        printf("Regular file\n");
    }
}
/*Output
File:FileInfoHandle.c
Regular file
*/