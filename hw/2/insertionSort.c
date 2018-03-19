#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int A[], int N)
{
  int j,i,key;
  for(j=1,j<N,j++)  
  {
    key = A[j];
    
    i = j-1;
    
    while (i > 0 && A[i] > key)
    {
      A[i+1] = A[i];
      i = i-1;      
    }
    
    A[i+1] = key;
  }
}



void printArray(int *A, int size)
{
    int i;
    for(i=0; i<size; i++){
        printf("%d\n",A[i]);
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
 
    
    int i;        
    int *A = (int *) malloc (sizeof(int) * (N));

    for (i=0; i<N; i++){
        scanf("%d",&A[i]);
    }

    insertionSort(A, N);
    printArray (A, N);

    return 0;
}
