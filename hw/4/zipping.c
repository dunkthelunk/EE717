#include<stdio.h>
#include<stdlib.h>


void * mymalloc(int p);

void print (int *A, int N)
{
	int i;
	for(i=0; i<N-1; i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[N-1]);
}

void zip(int *A, int N);

int main(void)
{
	int N, i, *A;

	scanf("%d",&N);

	A = (int *) malloc(sizeof(int)*N);
	if(A==NULL)
		return 1;

	for(i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	zip(A,N);
	print(A,N);
	return 0;
}

void * mymalloc(int size)
{
	static int i=0;
	if(i==0){
		void *p = (void *) malloc(size);
		return p;
	}
	else{
		return NULL;
	}
}

#define malloc mymalloc
#define calloc mymalloc
#define realloc myalloc
void zip(int *A, int N)
{
	/*Note that no extra memory should be allocated. The operation
	 *     has to be done in place.*/
	int i,j,k,l;

	l = (N%2==0) ? (N-1)/2 : (N-3)/2 ;
	
	for (i= N/2 ; i<N;i++)
	{
		k = i;
		
		for (j=l;j>0;j--)
		{

			int a;
			a = A[k];
			A[k] = A[k-1];
			A[k-1]=a;
			k--;   

		}
		l--;
	}
}
