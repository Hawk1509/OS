// To write C program to print the PID of itself and its parent. Create a child process and Pid of itself and parent should be printed
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
    pid_t a;
    pid_t x, b, c, d;
    a = fork();
    if (a > 0)
    {
        wait(NULL);
        printf("\nParent process\n");
        x = getpid();
        printf("pid : %d", x);
    }
    else if (a == 0)
    {
        printf("Child process\n");
        b = getpid();
        printf("pid : %d\t", b);
        c = getppid();
        printf("parent pid : %d\t", c);
    }
    else
    {
        printf("Error\n");
    }
}
/*Output
Child process
pid : 11740     parent pid : 11739
Parent process
pid : 11739  
*/