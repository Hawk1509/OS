//To wirte a C Program to create new child process and print "I am child", in parent process "I am parent"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
    pid_t a = fork();
    if (a == 0)
    {
        printf("I am child\n");
    }
    else if (a > 0)
    {
        printf("I am Parent\n");
    }
    else
        printf("Error");
}
/*Output
I am Parent
I am child
*/