/*C program to print
    a) Name
    b) Size of all file in the current directory whose name starts with "a"
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
void main()
{
    DIR *d;
    struct dirent *de;
    struct stat sb;
    d = opendir(".");
    while ((de = readdir(d)) != NULL)
    {
        printf("Name:%-20s\t", de->d_name);
        stat(de->d_name, &sb);
        if ((de->d_type) == 8)
        {
            printf("Type:File \t");
        }
        else if ((de->d_type) == 4)
        {
            printf("Type:Directory\t");
        }
        printf("Mode:%o\t", sb.st_mode & 0777);
        if (de->d_name[0] == 'a')
        {
            printf("Size:%d", de->d_reclen);
        }
        printf("\n");
    }
}
/*Output
Name:ParentChildPro.c           Type:File       Mode:644
Name:hi.txt                     Type:File       Mode:644
Name:fork1.c                    Type:File       Mode:644
Name:exec.c                     Type:File       Mode:644
Name:a.out                      Type:File       Mode:755        Size:32
Name:fcfsTest.c                 Type:File       Mode:644
Name:DirecFileDetails.c         Type:File       Mode:644
Name:sys2.c                     Type:File       Mode:644
Name:options.sh                 Type:File       Mode:644
Name:.                          Type:Directory  Mode:755
Name:Area.sh                    Type:File       Mode:644
Name:FileInfoHandle.c           Type:File       Mode:644
Name:OddEvenNum.c               Type:File       Mode:644
Name:sys.c                      Type:File       Mode:644
Name:PidNumber.c                Type:File       Mode:644
Name:fork4.c                    Type:File       Mode:644
Name:fork3.c                    Type:File       Mode:644
Name:fork2.c                    Type:File       Mode:644
Name:..                         Type:Directory  Mode:700
Name:.git                       Type:Directory  Mode:755
Name:fib.sh                     Type:File       Mode:644
Name:fork5.c                    Type:File       Mode:644
Name:fact.sh                    Type:File       Mode:644
Name:TypeOfFileInDir.c          Type:File       Mode:644
Name:Name&TypeOfFile.c          Type:File       Mode:644
Name:README.md                  Type:File       Mode:644
*/