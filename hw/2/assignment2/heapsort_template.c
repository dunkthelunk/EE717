#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int * Heap;

void swap(int *A, int a, int b)
{
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void maxHeapify(Heap h1, int location, int size)
{
    int leftChild, rightChild, root, swapper;
    root = location;
    while (2*root <= size)
    {
        leftChild = 2*root;
        rightChild = leftChild+1;
        swapper = root;

        if (h1[leftChild] > h1[swapper]) swapper = leftChild;
        if (rightChild <= size && h1[swapper] < h1[rightChild]) swapper = rightChild;
        if ( swapper == root ) return;
        else 
        {
        swap(h1,root,swapper);
        root = swapper;
        }
    }
}

int extractMax(Heap h1, int *sizePtr)
{
    int max=h1[1];
    swap(h1,1,*sizePtr);
    *sizePtr = *sizePtr-1;
    maxHeapify(h1,1,*sizePtr);
    return max; 
}

void buildHeap(Heap h1, int size)
{
    int i=size/2;
    while (i > 0 ) 
    {
        maxHeapify(h1,i,size);
        i--;
    }
}

void printHeap(Heap h1, int size)
{
    int i;
    for(i=1; i<=size-1; i++){
        printf("%d ",h1[i]);
    }
    printf("%d\n",h1[size]);
}

void heapSort(Heap h1, int N)
{
    int num=N;
    int i;

    buildHeap(h1, N);

    for(i=1; i<=num; i++){
        int val = extractMax(h1, &N);
        h1[num-i+1] = val;
    }
    
    
}

void checkSorted(int *A, int N)
{
    int i;
    for(i=1; i<=N-1; i++){
        if(A[i] > A[i+1])
            break;
    }
    if(i != N){
        printf("Output is not sorted");
        exit(1);
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
    int num=N;
    
    int i;        
    int *h1 = (int *) malloc (sizeof(int) * (N+1));

    for (i=1; i<=N; i++){
        scanf("%d",&h1[i]);
    }

    
    struct timeval start, stop;
    double totaltime;
    
    gettimeofday(&start,NULL);
    heapSort(h1, N);
    gettimeofday(&stop,NULL);
    
    checkSorted(h1,N);
    totaltime = ( stop.tv_sec * 1000000L + stop.tv_usec )
          - ( start.tv_sec * 1000000L + start.tv_usec );
   
    totaltime /= 1000; 
    printf("Size = %d Time taken = %fms\n",N,totaltime);
    return 0;
}
