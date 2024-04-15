/* C program to perform the following:
    a) Take file name as argument
    b) Create child process
    c) Execute cat command in child
    d) call wait() so that parent is blocked until child terminates
*/
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
void main(int argc, char *argv[])
{
    pid_t a;
    a = fork();
    if (a > 0)
    {
        wait(NULL);
        printf("Child terminated");
    }
    else if (a == 0)
    {
        execl("/bin/cat", "cat", argv[1], NULL);
    }
    else
    {
        printf("Error\n");
    }
}
/*Output
❯ gcc -o file ExecCatComm.c
❯ ./file hello.txt
hel ios skiow
Child terminated
<<<<<<< HEAD
*/
=======
*/
>>>>>>> ef6478e7b837e95ac9ae75acef2de6a1c03d9066
