#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void main(){
	pid_t a;
	a=fork();
	if(a>0){
		printf("\nI am a parent process\n");
		printf("ppid parent process: %d",getppid());
		;}
	else if(a==0){
		printf("\nI am a child process\n");
		printf("ppid child process: %d",getppid());
		wait(NULL);}
	else{
		printf("Error\n");
	}
}

/*
OUTPUT
I am a parent process
ppid parent process: 3206
I am a child process
ppid child process: 1673
*/
