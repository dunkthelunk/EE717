#include<stdio.h>


int recursiveRodCut(int *prices, int N)
{
	if(N==0) return 0;
	int qmax = 0xFFFFFFFF; // -INFINITY
	int i,q,cutLength;
	for (i=1;i<=N;i++)
	{
		q = prices[i] + recursiveRodCut(prices,N-i);
		if (q > qmax)
		{
			cutLength = i;
			qmax = q;
		}
	}
	printf("For length %d: %d\n",N,cutLength);
	return prices[cutLength];
}
int main()
{

	int N;
	scanf("%d",&N);
	int p[N+1];
	printf("Enter prices (Eg: 1 2 4 3) - ");

	int i;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&p[i]);
	}	
	printf("%d\n",recursiveRodCut(p,N));	
	return 0;
}
