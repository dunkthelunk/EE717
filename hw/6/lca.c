#include<stdio.h>
#include<stdlib.h>

struct bstNode 
{
	char key;
	struct bstNode *leftNode;
	struct bstNode *rightNode;
};

typedef struct bstNode * nodePtr;

nodePtr root;

nodePtr createNode (char c)
{
	nodePtr p;
	p = (nodePtr) malloc(sizeof(struct bstNode));
	
	p->key = c;
	p->leftNode = NULL;
	p->rightNode = NULL;
	
	return p;
}

void addElement(char c)
{
	int keyInserted = 0;
	nodePtr current = root;
	while (keyInserted == 0)
	{
		if (c>current->key)
		{
			if (current->rightNode != NULL) current = current->rightNode;
			else {current->rightNode = createNode(c); keyInserted = 1;}	
		
		}
		else 
		{
		
			if (current->leftNode != NULL) current = current->leftNode;
			else {current->leftNode = createNode(c); keyInserted = 1;}	
		}
	
	}

}


nodePtr lca(char c1, char c2)
{
	if (c1 > c2) 
	{
		c1 = c1+c2;
		c2 = c1-c2;
		c1 = c1-c2;
	}
	
	nodePtr current = root;
	int found = 0;

	while(found == 0)
	{
		if (c1 <= current->key && c2 >= current->key)
		{
			found = 1;
			return current;
		}
		
		else if (c1 > current->key) current = current->rightNode;
		else if (c2 < current->key) current = current->leftNode;
	}

}

void preorderTraversal(nodePtr node)
{
	printf("%c",node->key);

	if(node->leftNode != NULL) preorderTraversal(node->leftNode);
	if(node->rightNode != NULL) preorderTraversal(node->rightNode);
}

void postorderTraversal(nodePtr node)
{

	if(node->leftNode != NULL) postorderTraversal(node->leftNode);
	if(node->rightNode != NULL) postorderTraversal(node->rightNode);

	printf("%c",node->key);

}
void inorderTraversal(nodePtr node)
{

	if(node->leftNode != NULL) inorderTraversal(node->leftNode);
	printf("%c",node->key);
	if(node->rightNode != NULL) inorderTraversal(node->rightNode);

}

int main()
{
	int n;
	scanf("%d\n",&n);
	int i;
	char c;
	scanf("%c",&c);
	root = createNode(c);
	//nodePtr newNode;
	for (i = 1; i<n;i++)
	{
		scanf(" %c",&c);
		addElement(c);
	}
	int m;
	char c1;
	char c2;	
	scanf(" %d",&m);
	nodePtr L;
	for (i=0;i<m;i++)
	{
		scanf(" %c %c",&c1,&c2);
		L = lca(c1,c2);
		printf("%c\n",L->key);
		printf("(");
		preorderTraversal(L);
		printf(")");
		printf("(");
		inorderTraversal(L);
		printf(")");
		printf("\n");
	}
	return 0;
}

