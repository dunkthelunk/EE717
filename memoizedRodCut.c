#include<stdio.h>


int memoizedRodCut(int *prices, int N, int *cuts)
{
	if(N==0) return 0;
	if (cuts[N] != 0) return prices[cuts[N]];
	int qmax = 0xFFFFFFFF; // -INFINITY
	int i,q,cutLength;
	for (i=1;i<=N;i++)
	{
		q = prices[i] + memoizedRodCut(prices,N-i,cuts);
		if (q > qmax)
		{
			cutLength = i;
			qmax = q;
		}
	}
	cuts[N] = cutLength;
	printf("For length %d: %d\n",N,cutLength);
	return prices[cutLength];
}
int main()
{

	int N;
	scanf("%d",&N);
	int cuts[N+1];
	int i;	
	for(i=1;i<=N;i++)
	{
		cuts[i] = 0;
	}


	int p[N+1];
	printf("Enter prices (Eg: 1 2 4 3) - ");

	for(i=1;i<=N;i++)
	{
		scanf("%d",&p[i]);
	}	
	printf("%d\n",memoizedRodCut(p,N,cuts));	
	return 0;
}
