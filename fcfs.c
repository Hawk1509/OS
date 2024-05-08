#include<stdio.h>
#include<math.h>
void main()
{
	int a[20],n,l=0,i,j;
	printf("Enter the range: ");
	scanf("%d",&n);
	printf("Enter the header position: ");
	scanf("%d",&a[0]);
	printf("Enter the track:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The disk is moved from:\n");
	for(j=0;j<n;j++)
	{
		i=abs(a[j+1]-a[j]);
		l=l+i;
		printf("The disk is moved from %d to %d with seek time %d.\n",a[j],a[j+1],i);
	}
	printf("The total head movement is: %d \n",l);
}
/*
OUTPUT
Enter the range: 8
Enter the header position: 53
Enter the track:
98
183
37
122
14
124
65
67
The disk is moved from:
The disk is moved from 53 to 98 with seek time 45.
The disk is moved from 98 to 183 with seek time 85.
The disk is moved from 183 to 37 with seek time 146.
The disk is moved from 37 to 122 with seek time 85.
The disk is moved from 122 to 14 with seek time 108.
The disk is moved from 14 to 124 with seek time 110.
The disk is moved from 124 to 65 with seek time 59.
The disk is moved from 65 to 67 with seek time 2.
The total head movement is: 640
*/
