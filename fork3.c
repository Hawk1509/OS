#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
	 pid_t a;
	 pid_t x,b,c,d;
	 a=fork();
	 if(a>0){
	 wait(NULL);
	 	printf("\nParent process\n");
	 	x=getpid();
	 	printf("pid : %d",x);
	 }
	 else if(a==0){
	 	printf("\nChild process\n");
	 	b=getpid();
	 	printf("pid : %d\t",b);
	 	c=getppid();
	 	printf("ppid : %d\t",c);
	 }
	 else{
	 	printf("Error\n");
	 }
}
