#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <cilk/reducer_opadd.h>

void readiput(int **A,int **B,int n);

void printOP(int **A, int n);

void GenG( int N, int G);
void GenNext(int N, int i, int j);

int **A,**B;

int main()
{
	int g,n;
	scanf ("%d %d",&n ,&g);
	
        int i;
	A=(int**)malloc((n+1)*sizeof(int*));
	B=(int**)malloc((n+1)*sizeof(int*));
	for (i = 0; i <=n; ++i)
	{
		A[i]= (int*)malloc(sizeof(int)*(n+1));
		B[i]= (int*)malloc(sizeof(int)*(n+1));
	}
	readiput(A,B,n);
        
        GenG(n,g);
        printOP(A,n);

     
	//printf("\n");	
	return 0;
}








void GenG(int N, int G){
	int i,k;
        int **temp;
        
	for(k=0;k<G;k++){
		cilk_for(i=1;i<=N;i++){
			cilk_for(int j=1;j<=N;j++){
				GenNext(N,i,j);
			}
                        
		}
		
            cilk_sync;
            temp = B;
            B = A;
            A = temp; 
            
            
	}
}


void GenNext(int N, int i, int j){
	
	// NumNeb is calculated
	int row,col,NumNeb=0;
	
	for(row=i-1;row <= i+1;row++){
		for(col=j-1;col <= j+1; col++){
			if((row==i && col==j)  || row==0||col==0||row==N+1||col==N+1){
				//do nothing
			}
			else{
				NumNeb += A[row][col];
			}
		}
	}
	//printf("%d %d %d\n",i,j,NumNeb);
	
	// Any live cell with fewer than two live neighbours dies, as if caused by under-population.
    //Any live cell with two or three live neighbours lives on to the next generation.
    //Any live cell with more than three live neighbours dies, as if by over-population.
    //Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

	if(NumNeb < 2 ){
		B[i][j]=0;
	}
    else if(NumNeb==2){
		//do nothing
		B[i][j]=A[i][j];
	}
	else if(NumNeb==3){
		B[i][j]=1;
	}
	else if(NumNeb>3){
		B[i][j]=0;
	}
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
            //            A[i][j]=1;
			B[i][j]=0;
		}
		//printf("\n");
	}

}
void printOP(int **A, int n)
{	int i,j;
	for(i=1;i<=n;i++)
	{
		printf("%d",A[i][1]);
		for(j=2;j<=n;j++)
		{
			printf(" %d",A[i][j]);
		}
		printf("\n");
	}	
} 
