#include<stdio.h>
int i,j,nof,nor,flag=0,ref[50],frm[50],pf=0,victim=-1;
void main()
{
	printf("\n \t\t\t FIFO PAGE REPLACEMENT ALGORITHM");
	printf("\n Enter no.of frames....");
	scanf("%d",&nof);
	printf("Enter number of Pages.\n");
	scanf("%d",&nor);
	printf("\n Enter the Page Nos...");
	for(i=0;i<nor;i++)
		scanf("%d",&ref[i]);
	printf("\nThe given Pages are:");
	for(i=0;i<nor;i++)
		printf("%4d",ref[i]);
	for(i=1;i<=nof;i++)
		frm[i]=-1;
		printf("\n");
	for(i=0;i<nor;i++)
	{
		flag=0;
		printf("\n\t page no %d->\t",ref[i]);
		for(j=0;j<nof;j++)
		{
			if(frm[j]==ref[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		pf++;
		victim++;
		victim=victim%nof;frm[victim]=ref[i];
		for(j=0;j<nof;j++)
		printf("%4d",frm[j]);
		}
	}
	printf("\n\n\t\t No.of pages faults...%d",pf);
}
/*
OUTPUT

 			 FIFO PAGE REPLACEMENT ALGORITHM
 Enter no.of frames....4
Enter number of Pages.
6

 Enter the Page Nos...5
6
4
1
2
3

The given Pages are:   5   6   4   1   2   3

	 page no 5->	   5  -1  -1  -1
	 page no 6->	   5   6  -1  -1
	 page no 4->	   5   6   4  -1
	 page no 1->	   5   6   4   1
	 page no 2->	   2   6   4   1
	 page no 3->	   2   3   4   1

		 No.of pages faults...6
*/
