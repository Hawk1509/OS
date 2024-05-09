//Producer consumer problem
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>
sem_t mutex,empty,full;
int buffer[5],get=0,item=0,gitem,put=0,pro[20],con[20];
void *producer(void *arg)
{
	do
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[put%5]=item;
		item++;
		printf("producer %d produces %d item buffered[%d]:%d\n",(*(int *)arg),buffer[put%5],put%5,item);
		put++;
		sem_post(&mutex);
		sem_post(&full);
		sleep(3);
	}
	while(1);
}
void *consumer(void *arg)
{
	do
	{
		sem_wait(&full);
		sem_wait(&mutex);
		gitem=buffer[get%5];
		printf("consumer %d consumes %d item buffered[%d]:%d\n",(*(int *)arg),gitem,get%5,gitem);
		get++;
		sem_post(&mutex);
		sem_post(&empty);
		sleep(2);
	}
	while(1);
}
void main()
{
	int p,c,j,k;
	pthread_t a[10],b[10];
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	printf("\n Enter no of producers");
	scanf("%d",&p);
	printf("\n Enter no of consumers");
	scanf("%d",&c);
	for(j=0;j<p;j++)
	{
		pro[j]=j;
		pthread_create(&a[j],NULL,producer,&pro[j]);
	}
	for(k=0;k<c;k++)
	{
		con[k]=k;
		pthread_create(&b[k],NULL,consumer,&con[k]);
	}
	for(j=0;j<p;j++)
	{
		pthread_join(a[j],NULL);
	}
	for(k=0;k<c;k++)
	{	
		pthread_join(b[k],NULL);
	}
}
/*
Output

 Enter no of producers3

 Enter no of consumers3
producer 0 produces 0 item buffered[0]:1
producer 2 produces 1 item buffered[1]:2
producer 1 produces 2 item buffered[2]:3
consumer 0 consumes 0 item buffered[0]:0
consumer 2 consumes 1 item buffered[1]:1
consumer 1 consumes 2 item buffered[2]:2
producer 0 produces 3 item buffered[3]:4
consumer 0 consumes 3 item buffered[3]:3
producer 2 produces 4 item buffered[4]:5
producer 1 produces 5 item buffered[0]:6
consumer 2 consumes 4 item buffered[4]:4
consumer 1 consumes 5 item buffered[0]:5
producer 0 produces 6 item buffered[1]:7
producer 2 produces 7 item buffered[2]:8
consumer 0 consumes 6 item buffered[1]:6
producer 1 produces 8 item buffered[3]:9
consumer 1 consumes 7 item buffered[2]:7
consumer 2 consumes 8 item buffered[3]:8
*/	