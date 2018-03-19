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

void maxHeapify(Heap h1, int location, int size);
int extractMax(Heap h1, int *sizePtr);
void  buildHeap(Heap h1, int size);
void printHeap(Heap h1, int size);

void maxHeapify(Heap h1, int location, int size)
{
	int leftChild, rightChild, root, swapper;
	root = location;
	while (2*root  <= size)
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

void  buildHeap(Heap h1, int size)
{
	int i=size/2;
	while (i > 0 ) 
	{
		maxHeapify(h1,i,size);
		i--;
	}
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

void printHeap(Heap h1, int size)
{
	int i;
	for(i=1; i<=size; i++){
		printf("%d\n",h1[i]);
	}
}

int main(void)
{
	int N;
	scanf("%d",&N);
	int num=N;

	int i;        

	//Allocate 1 more than N and use from 1 to N
	int *h1 = (int *) malloc (sizeof(int) * (N+1));

	for (i=1; i<=N; i++){
		scanf("%d",&h1[i]);
	}

	heapSort(h1, N);
	printHeap (h1, N);

	return 0;
}
