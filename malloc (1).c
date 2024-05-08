#include <stdio.h>
#include <stdlib.h>
int* partitions;
int* partition_allocated;
int num_partitions;
int* requests;
int num_requests;

void first_fit() 
{
    printf("First Fit\n");

    for (int i = 0; i < num_requests; i++) 
    {
        int request = requests[i];
        int j;

        for (j = 0; j < num_partitions; j++) 
        {
            if (!partition_allocated[j] && partitions[j] >= request ) 
            {
                printf("Request %d in [%d] ;now Current Partition: ", request, j + 1);
                partitions[j] -= request;
                partition_allocated[j] = 1;
                for (int k = 0; k < num_partitions; k++) 
                {
                    printf("%d ", partitions[k]);
                }
                printf("\n");
                break;
            }
        }

        if (j == num_partitions) 
        {
            printf("Request %d Not - Allocated\n", request);
        }
    }
}

void worst_fit() 
{
    printf("Worst Fit\n");

    for (int i = 0; i < num_requests; i++) 
    {
        int request = requests[i];
        int j, max = -1;

        for (j = 0; j < num_partitions; j++) 
        {
            if (!partition_allocated[j] && partitions[j] >= request &&
                (max == -1 || partitions[j] > partitions[max])) 
            {
                max = j;
            }
        }
	
        if (max!=-1) 
        {
            printf("Request %d in [%d] ;now Current Partition: ", request, max + 1);
            partitions[max] -= request;
            partition_allocated[max] = 1;
            for (int k = 0; k < num_partitions; k++) 
            {
                    printf("%d ", partitions[k]);
            }
            printf("\n");
        } 
        else 
        {
            printf("Request %d Not - Allocated\n", request);
        }
    }
}

void best_fit() 
{
    printf("Best Fit\n");

    for (int i = 0; i < num_requests; i++) 
    {
        int request = requests[i];
        int j, min = -1;

        for (j = 0; j < num_partitions; j++) 
        {
            if (!partition_allocated[j] && partitions[j] >= request &&
                (min == -1 || partitions[j] < partitions[min])) 
            {
                min = j;
            }
        }

        if (min != -1) 
        {
            printf("Request %d in {%d};Now  Current Partition: ", request, min + 1);
            partitions[min] -= request;
            partition_allocated[min] = 1;
	    for (int k = 0; k < num_partitions; k++)
	    {
                    printf("%d ", partitions[k]);
            }
            printf("\n");
                
        }
        else 
        {
            printf("Request %d Not - Allocated\n", request);
        }
    }
}

int main() 
{
    int choice,x;

    do 
    {
       
	printf("1. First Fit\n2. Worst Fit\n3. Best Fit\nSelect: ");
        scanf("%d", &choice);
        
        printf("Number of Partitions: ");
        scanf("%d", &num_partitions);

        partitions = (int*)malloc(num_partitions * sizeof(int));
        partition_allocated = (int*)malloc(num_partitions * sizeof(int));

        printf("Enter Partitions: ");
        for (int i = 0; i < num_partitions; i++) 
        {
            scanf("%d", &partitions[i]);
            partition_allocated[i] = 0;
        }

        printf("Number of Requests: ");
        scanf("%d", &num_requests);

        requests = (int*)malloc(num_requests * sizeof(int));

        printf("Enter all Requests: ");
        for (int i = 0; i < num_requests; i++) 
        {
            scanf("%d", &requests[i]);
        }
	
	
        
        switch (choice) {
            case 1:
                first_fit();
                break;
            case 2:
                worst_fit();
                break;
            case 3:
                best_fit();
                break;
            
            	
            default:
                printf("Invalid choice!\n");
        }
		printf("Press 1 to continue:");
		scanf("%d",&x);
        free(partitions);
        free(partition_allocated);
        free(requests);
    } 
    while (x==1);

    return 0;
}
/*
OUTPUT
1. First Fit
2. Worst Fit
3. Best Fit
Select: 1   
Number of Partitions: 4
Enter Partitions: 100
250
400
500
Number of Requests: 3
Enter all Requests: 112
212
300
First Fit
Request 112 in [2] ;now Current Partition: 100 138 400 500 
Request 212 in [3] ;now Current Partition: 100 138 188 500 
Request 300 in [4] ;now Current Partition: 100 138 188 200 
Press 1 to continue:1
1. First Fit
2. Worst Fit
3. Best Fit
Select: 2
Number of Partitions: 4
Enter Partitions: 100 
250
400
500
Number of Requests: 3
Enter all Requests: 112
212
300
Worst Fit
Request 112 in [4] ;now Current Partition: 100 250 400 388 
Request 212 in [3] ;now Current Partition: 100 250 188 388 
Request 300 Not - Allocated
Press 1 to continue:1
1. First Fit
2. Worst Fit
3. Best Fit
Select: 3
Number of Partitions: 4
Enter Partitions: 100
250
400
500
Number of Requests: 3
Enter all Requests: 112
212
300
Best Fit
Request 112 in {2};Now  Current Partition: 100 138 400 500 
Request 212 in {3};Now  Current Partition: 100 138 188 500 
Request 300 in {4};Now  Current Partition: 100 138 188 200 
Press 1 to continue:0
*/

