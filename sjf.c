#include<stdio.h>
#include<string.h>
struct process
{
	char pname[20];
	int at,bt,wt,tt,status;
}p[20],t;
struct done
{
	char name[20];
	int st,ct;
}d[20];
void main()
{
	int i,j,k,n,idle,num,found=0;
	float sumwt=0.0,sumtt=0.0,st,w;
	printf("enter the number of processes ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter process name\n");
		__fpurge(stdin);
		gets(p[i].pname);
		printf("enter arrival time\n");
		scanf("%d",&p[i].at);
		printf("enter burst time\n");
		scanf("%d",&p[i].bt);
		p[i].status=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	idle=0;
	int ls=0;
	for(i=0,k=0,num=0;ls<n;){
		found=0;
		for(j=0;j<n;j++){
			if(p[j].status==0&&p[j].at<=i&&found==0)
			{
				k=j;
				found++;
			}
			else if(found>0&&p[j].status==0&&p[j].at<=i){
				if(p[j].bt<p[k].bt){k=j;}
			}
		}
		if(found==0&&idle==0){
			strcpy(d[num].name,"idle");
			d[num].st=i;
			i++;
			idle=1;
		}
		else if(found>0){
			if(idle==1)
			{
				d[num].ct=i;
				num++;
			}
			strcpy(d[num].name,p[k].pname);
			d[num].st=i;
			d[num].ct=i+p[k].bt;
			//p[k].tt= d[num].ct-p[k].at;
			//p[k].wt= p[k].tt-p[k].bt;
			p[k].wt=d[num].st-p[k].at;
			p[k].tt=p[k].wt+p[k].bt;
			i=d[num].ct;
			p[k].status=1;
			k++;
			num++;
			idle=0;
			ls++;
		}
		else{
			i++;
		}
		
	}
	/*for(i=0,k=0,num=0;k<n;)
	{
		if(p[k].at<=i&&p[k].status==0)
		{
			if(idle==1)
			{
				d[num].ct=i;
				num++;
			}
			strcpy(d[num].name,p[k].pname);
			d[num].st=i;
			d[num].ct=i+p[k].bt;
			p[k].tt= d[num].ct-p[k].at;
			p[k].wt= p[k].tt-p[k].bt;
			//p[k].wt=d[num].st-p[k].at;
			//p[k].tt=p[k].wt+p[k].bt;
			i=d[num].ct;
			p[k].status=1;
			k++;
			num++;
			idle=0;
			ls++;
		}
		else if(idle==0)
		{
			strcpy(d[num].name,"idle");
			d[num].st=i;
			i++;
			idle=1;
		}
		else
		{
			i++;
		}
	}*/
	printf ( " |pname  | arrival time\t | burst time\t | status\t | wait\t | turn") ;
	for ( i =0; i <n ; i ++)
	{
		printf ( "\n |%s \t |%d \t \t |%d \t \t |%d \t \t |%d \t |%d \n" , p[i].pname ,p[i].at , p[i].bt ,
		p[i].status,p[i].wt,p[i].tt );
	}
	printf("\n\n\nGantt chart\n");
	for(i=0;i<n;i++)
	printf("___________________");
	printf("\n|");
	for(i=0;i<num;i++)
	printf("%s	|",d[i].name);
	printf("\n");
	for(i=0;i<n;i++)
	printf("___________________");
	printf("\n");
	for(i=0;i<num;i++)
	printf("%d   	",d[i].st);
	printf("%d   	",d[num-1].ct);
	printf("\n");
	for(i=0;i<n;i++)
	{
		sumwt=sumwt+p[i].wt;
		sumtt=sumtt+p[i].tt;
	}
	w=(float)(sumwt/n);
	st=(float)(sumtt/n);
	printf("\nAverage waiting time=%f",w);
	printf("\nAverage turnaround time=%f\n",st);
} 
/*
Output
enter the number of processes 3
enter process name
p1
enter arrival time
2
enter burst time
4
enter process name
p2
enter arrival time
3
enter burst time
3
enter process name
p3
enter arrival time
4
enter burst time
8
 |pname  | arrival time	 | burst time	 | status	 | wait	 | turn
 |p1 	 |2 	 	 |4 	 	 |1 	 	 |0 	 |4 

 |p2 	 |3 	 	 |3 	 	 |1 	 	 |3 	 |6 

 |p3 	 |4 	 	 |8 	 	 |1 	 	 |5 	 |13 



Gantt chart
_________________________________________________________
|idle	|p1	|p2	|p3	|
_________________________________________________________
0   	2   	6   	9   	17   	

Average waiting time=2.666667
*/
