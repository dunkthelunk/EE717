#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int *A, int N)
{
    int j,i,key;
    for(j=1;j<N;j++)  
    {
        key = A[j];
        
        i = j-1;
        
        while (i >= 0 && A[i] > key)
        {
        A[i+1] = A[i];
        i = i-1;      
        }
        
        A[i+1] = key;
    }
}

void checkSorted(int *A, int N)
{
    int i;
    for(i=0; i<N-1; i++){
        if(A[i] > A[i+1])
            break;
    }
    if(i != N-1){
        printf("Output is not sorted");
        exit(1);
    }
}
int main(void)
{
  int N;
  int *A;
  int i, j, val;
  
  scanf("%d",&N);
  A = (int *) malloc(sizeof(int)*N);
  
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
    struct timeval start, stop;
    double totaltime;

    gettimeofday(&start,NULL);
    insertionSort(A, N);
    gettimeofday(&stop,NULL);
    
    checkSorted(A,N);
    totaltime = ( stop.tv_sec * 1000000L + stop.tv_usec )
          - ( start.tv_sec * 1000000L + start.tv_usec );
   
    totaltime /= 1000; 
    printf("Size = %d Time taken = %fms\n",N,totaltime);
        
  return 0;
}
