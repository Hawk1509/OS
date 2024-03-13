#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void main(){
	pid_t a;
	pid_t x,y,z;
	a=fork();
	if(a>0){
	wait(NULL);
		printf("\nI am a parent process\n");
		x=getpid();
		printf("pid: %d",x);}
	else if(a==0){
		z=getpid();
		y=getppid();
		printf("\nI am a child process\n");
		printf("ppid: %d",y);
		printf("pid: %d",z);}
	else{
		printf("Error\n");
	}
}
