#include<stdio.h>
main()
{
	int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum=0,end=199;
	clrscr();
	printf("enter the no of tracks to be traversed");
	scanf("%d",&n);printf("enter the position of head");
	scanf("%d",&h);
	t[0]=0;t[1]=h;
	t[n+2]=end;
	printf("enter the tracks");
	for(i=2;i<n+2;i++)
		scanf("%d",&t[i]);
	for(i=0;i<n+2;i++)
	{
		for(j=0;j<(n+2)-i-1;j++)
		{
			if(t[j]>t[j+1])
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
	for(i=0;i<n+2;i++)
		if(t[i]==h)
		{
			k=i;
			p=0;
		}
	if(h<(end-h))
	{
		for(i=k;i>=0;i--)
		{ 
			atr[p]=t[i];
			p++;
		}	
		for(i=n+2;i>k;i--)
		{
			atr[p]=t[i];
			p++;
		}
	}
	else
	{
		for(i=k;i<=n+2;i++)
			{
				atr[p]=t[i];
				p++;
			}
		for(i=0;i<k;i++)
		{
			atr[p]=t[i];
			p++;
		}
	}
	printf("Scheduling order:\n");
	for(p=0;p<=n+2;p++)
		printf("%d \t",atr[p]);
		for(j=0;j<n+2;j++)
		{
			d[j]=0;
			if(atr[j]>atr[j+1])
				d[j]=atr[j]-atr[j+1];
			else d[j]=atr[j+1]-atr[j];
				sum+=d[j];
		}	
		printf("\nTotal head movements:%d\n",sum);
}
