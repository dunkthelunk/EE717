#include<stdio.h>
#include<math.h>

int cost[101][101];
int splits[101][101];

void mcm(int *p,int N)
{
	int i;
	for(i=1;i<=N;i++)
	{
		cost[i][i] = 0;
	}	
	
	int k,m,j;
	for(m=1;m<N;m++)
	{
		j = 0;
		for(i=1;j<N;i++)
		{
			j = i+m;
			cost[i][j] = 0x2FFFFFFF;//INFINITY;
			
			int q;
			for(k=i;k<j;k++)
			{	
				q = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < cost[i][j])
				{
					cost[i][j] = q;
					splits[i][j] = k;
				}
			}
			
		}
	}

}

void printParens(int i, int j)
{
	if (i == j) printf("A%d",i);
	else 
	{
		printf("(");
		printParens(i,splits[i][j]);
		printParens(splits[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int p[N+1];

	int i;
	for (i=0;i<N+1;i++)
	{
		scanf("%d",&p[i]);
	}
	mcm(p,N);
	printf("%d\n",cost[1][N]);
	printParens(1,N);
	printf("\n");
	return 0;
}
