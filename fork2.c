#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	pid_t a;
	int i;
	a=fork();
	if(a>0){
	wait(NULL);
		printf("Printing even numbers from 1 to 10\n");
		for(i=2;i<=10;i=i+2){
			printf("%d\t",i);
		}
		printf("\n");
	}
	else if(a==0){
		printf("Printing odd numbers from 1 to 10\n");
		for(i=1;i<=10;i=i+2){
			printf("%d\t",i);
		}
		printf("\n");
	
	}
	else{
		printf("Error\n");
	}
}
