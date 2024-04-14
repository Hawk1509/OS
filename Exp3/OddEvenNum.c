// C program to print Odd number among 1 - 10 by the child process and even number among 1 - 10 by the parent process[Even number after odd number].
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
    pid_t a;
    int i;
    a = fork();
    if (a > 0)
    {
        wait(NULL);
        printf("PARENT PROCESS\n");
        printf("Printing even numbers from 1 to 10\n");
        for (i = 2; i <= 10; i = i + 2)
        {
            printf("%d\t", i);
        }
        printf("\n");
    }
    else if (a == 0)
    {
        printf("CHILD PROCESS\nPrinting odd numbers from 1 to 10\n");
        for (i = 1; i <= 10; i = i + 2)
        {
            printf("%d\t", i);
        }
        printf("\n");
    }
    else
    {
        printf("Error\n");
    }
}
/*Output
CHILD PROCESS
Printing odd numbers from 1 to 10
1       3       5       7       9
PARENT PROCESS
Printing even numbers from 1 to 10
2       4       6       8       10
*/