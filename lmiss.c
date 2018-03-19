// CLRS 15.4-5 
#include<stdio.h>
#include<stdlib.h>

int main()
{	
	int N;
	scanf("%d",&N);
	int inputSeq[N+1];
	int *current = (int *) malloc((N+1)*sizeof(int));
	int *longestSeq = (int *) malloc((N+1)*sizeof(int));
	
	inputSeq[0] = N;
	current[0] = 1;
	longestSeq[0] = 0;
	int *temp;
	int i,j;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&inputSeq[i]);
	}
	
	int k;	
	for(i=1;i<=N;i++)
	{
		
		current[0] = 1;
		k = 1;
		current[k] = inputSeq[i];
		for(j=i+1;j<=N;j++)
		{	
//			printf("j = %d\n ",j);
			if (inputSeq[j] >= current[k])
			{
				k++;
				current[k] = inputSeq[j];
				current[0]++;
			}
		
		}	
//		printf("length= %d\n",current[0]);	
		if (current[0] > longestSeq[0])
		{
			temp = current;
			current = longestSeq;
			longestSeq = temp;
		}	
	}

	printf("Length of longest subsequence is %d.\nSequence: ",longestSeq[0]);	
	for (i=1;i<=longestSeq[0];i++)
	{
		printf("%d ",longestSeq[i]);
	}
	printf("\n");
	return 0;
}
