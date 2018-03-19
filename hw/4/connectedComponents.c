#include<stdio.h>
#include<stdlib.h>


void insertionSort(int A[], int N)
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

struct node {
	int vertex;
	struct node *next;
	struct node *rep;
};

typedef struct node * nodePtr;

nodePtr *ptrToNode; 
int *noOfNodes; // = size of connected component
				// if node is rep else 0

nodePtr *tails;

void makeSet(int u)
{
	if (ptrToNode[u] == NULL) 
	{
		nodePtr newNode;
		newNode = (nodePtr) malloc(sizeof(struct node));
		newNode->vertex = u;
		newNode->next = NULL;
		newNode->rep = newNode;
		ptrToNode[u] = newNode;
		tails[u] = newNode;
		noOfNodes[u] = 1;
	}
	return;
}

nodePtr findSet(int u)
{
	nodePtr p = ptrToNode[u];
	return p->rep;
}

void Union(int u, int v)
{
	if (u==v)
	{
		makeSet(u);
		return;
	}	

	makeSet(u);
	makeSet(v);

	nodePtr vrep, urep;
	vrep = findSet(v);
	urep = findSet(u);
	if ( vrep == urep ) return;	
	int uRepNode, vRepNode;
	uRepNode = urep->vertex;
	vRepNode = vrep->vertex;

	tails[uRepNode]->next = vrep;
	tails[uRepNode] = tails[vRepNode];
	tails[vRepNode] = NULL;
	
	noOfNodes[uRepNode] += noOfNodes[vRepNode];

	int i;
	nodePtr p = vrep;
	for (i=0;i<noOfNodes[vRepNode];i++)
	{
		p->rep = urep;
		p = p->next;
	}
	noOfNodes[vRepNode] = 0;	
}


int main()
{
	int V,E;
	scanf("%d\n%d",&V,&E);

	ptrToNode = (nodePtr *) malloc(sizeof(nodePtr)*V);
	noOfNodes = (int *) malloc(sizeof(int)*V);
	tails = (nodePtr *) malloc(sizeof(nodePtr)*V);

	int i;
	for (i=0;i<V;i++)
	{
		ptrToNode[i] = NULL;
		noOfNodes[i] = 0;
		tails[i] = NULL;	
	}

	int u,v;
	for (i=0;i<E;i++)
	{
		scanf("%d %d",&u,&v);
		Union(u,v);	
	}	
	
	for (i=0;i<V;i++)
	{
		if (ptrToNode[i] == NULL) noOfNodes[i] = 1;
	}
	insertionSort(noOfNodes,V);

	int firstNonZero = 0;
	for (i=0;i<V;i++)
	{
		if (firstNonZero ==0 && noOfNodes[i] !=0) 
		{
			firstNonZero = 1;
			printf("%d\n",V-i);
		}

		if (firstNonZero == 1) printf("%d ", noOfNodes[i]);		
	}
	return 0;
}
