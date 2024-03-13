#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void main(int argc,char *argv[])
{
	pid_t p=fork();
	if(p==0)
	{
		printf("filename:%s",argv[1]);
		execl("/bin/cat","cat",argv[1],NULL);
	}
	else if(p>0)	
	{
	wait(NULL);
	printf("child process");
	}
	else
		printf("error");
}
