#include <stdio.h>
#include <stdlib.h>
void GameOfLife(int **A,int **B,int i, int j);
void readiput(int **A,int **B,int n);
void compute(int **A, int **B, int n, int g);
void printOP(int **A, int n);

int main()
{
	int g,n,**A,**B;
	scanf ("%d %d",&n ,&g);
	//printf ("%d %d\n",n ,g);
        int i;
	A=(int**)malloc((n+1)*sizeof(int*));
	B=(int**)malloc((n+1)*sizeof(int*));
	for (i = 0; i <=n; ++i)
	{
		A[i]= (int*)malloc(sizeof(int)*(n+1));
		B[i]= (int*)malloc(sizeof(int)*(n+1));
	}
	readiput(A,B,n);
        //printOP(A,n);
	compute(A,B,n,g);


	
	return 0;
}
void compute(int **A, int **B, int n, int g)
{	
	int i,j,k;
	for(k=0;k<g;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((k%2)==0) GameOfLife(A,B,i,j);
				else GameOfLife(B,A,i,j);
			}
		}
	}

	if(g%2==0) printOP(A,n);
	else printOP(B,n);
	
}
void GameOfLife(int **A,int **B, int i, int j)
{
	// your function goes here
}

void readiput(int **A,int **B,int n)
{

	int i,j;
	for (i = 1; i <=n; i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&A[i][j]);
			//printf("%d ",A[i][j]);
			B[i][j]=0;
		}
		//printf("\n");
	}

}
void printOP(int **A, int n)
{	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}	
}