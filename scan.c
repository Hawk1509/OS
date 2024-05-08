#include<stdio.h>
void main() {
	int	track[100],head,end,n,totalHeadMovement=0,i,j,k,temp,traverse[100],prev;
	printf("\nEnter the value of end sector : ");
	scanf("%d",&end);
	printf("Enter the no. of tracks: ");
	scanf("%d",&n);
	printf("Enter the current head position : ");
	scanf("%d",&head);
	track[0] = 0;
	track[1] = head;
	track[n+2] = end;
	printf("\nEnter the tracks:-\n");
	for (i=2; i<n+2;++i) {
		printf("Track %d : ",(i-1));
		scanf("%d",&track[i]);
		}
	for ( i=0; i<n+1; ++i) {
		for ( j=0; j<n-i+1; ++j) {
			if (track[j] > track[j+1]) {
				temp = track[j];
				track[j] = track[j+1];
				track[j+1] = temp;
			}
		}
	}
	for (i=0;i<n+2;++i) {
		if (track[i]==head) {
			k = i;
			break;
		}
	}
	if (head < (end-head)) {
		for (i=0,j=k;j>=0;--j,++i) {
			traverse[i] = track[j];
		}
		for (j=k+1;j<n+2;++j,++i) {
			traverse[i] = track[j];
		}
	}
	else {
		for (i=0,j=k;j<n+2;++j,++i) {
			traverse[i] = track[j];
		}
		for (j=k-1;j>=0;--j,++i) {
			traverse[i] = track[j];
		}
	}
	prev = traverse[0];
	for (i=1;i<=n+2;++i) {
		if (traverse[i] > prev) {
			totalHeadMovement = totalHeadMovement + (traverse[i]-prev);
		}	 
		else {
		totalHeadMovement = totalHeadMovement + (prev-traverse[i]);
		}
		prev = traverse[i];
	}
	printf("\nTracks Traversed:-\n");
	for (i=0;i<n+2;++i) {
		printf("%d\t",traverse[i]);
	}
	printf("\n\nTotal Head Movements = %d\n\n",totalHeadMovement);
}
/*
OUTPUT

Enter the value of end sector : 199
Enter the no. of tracks: 6
Enter the current head position : 53

Enter the tracks:-
Track 1 : 98
Track 2 : 183
Track 3 : 37
Track 4 : 122
Track 5 : 14
Track 6 : 124

Tracks Traversed:-
53	37	14	0	98	122	124	183	

Total Head Movements = 419

*/
