// C program to print the name and type each file in directory
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
void main()
{
    DIR *d;
    char file[20];
    struct dirent *de;
    d = opendir(".");
    while ((de = readdir(d)) != NULL)
    {
        printf("Name:%s\t", de->d_name);
        if ((de->d_type) == 8)
        {
            printf("Type:File\n");
        }
        else if ((de->d_type) == 4)
        {
            printf("Type:Directory\n");
        }
        printf("\n");
    }
    closedir(d);
}
/*Output
Name:ParentChildPro.c   Type:File

Name:hi.txt     Type:File

Name:fork1.c    Type:File

Name:exec.c     Type:File

Name:a.out      Type:File

Name:fcfsTest.c Type:File

Name:sys2.c     Type:File

Name:options.sh Type:File

Name:.  Type:Directory

Name:Area.sh    Type:File

Name:FileInfoHandle.c   Type:File

Name:OddEvenNum.c       Type:File

Name:sys.c      Type:File

Name:PidNumber.c        Type:File

Name:fork4.c    Type:File

Name:fork3.c    Type:File

Name:fork2.c    Type:File

Name:.. Type:Directory

Name:.git       Type:Directory

Name:fib.sh     Type:File

Name:fork5.c    Type:File

Name:fact.sh    Type:File

Name:TypeOfFileInDir.c  Type:File

Name:Name&TypeOfFile.c  Type:File

Name:README.md  Type:File
*/