#include <stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

typedef struct node * nodePtr;

char operations[][30] = {"add","deleteFirstOccurence","deDuplicate","reverseList","isSorted","getLength","printList"};

nodePtr head;

void init(void)
{
	head = (nodePtr) malloc (sizeof(struct node));
	head->val = 0;
	head->next = NULL;
}

void cleanup(void)
{
	if (head==NULL) return;
	nodePtr curr=head->next, tmp;

	while(curr!=NULL){
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	head->val = 0;
	head->next = NULL;
}

void printList(void)
{
	printf("List: ");
	if(head == NULL || head->val == 0){
		printf("\n");
		return;
	}
	nodePtr tmp = head->next;
	while(tmp!=NULL){
		printf("%d ",tmp->val);
		tmp=tmp->next;
	}
	printf("\n");
}

void printListWithPointers(void)
{
	if(head==NULL){
		printf("List header not created\n");
		return;
	}
	printf("(Head, %p) -> ",head->next);
	if(head->val == 0){
		printf("NULL\n");
		return;
	}
	else{
		nodePtr tmp = head->next;
		while(tmp->next != NULL){
			printf("(%d %p) -> ",tmp->val,tmp->next);
			tmp=tmp->next;
		}
		printf("(%d %p)",tmp->val,tmp->next);

		printf("\n");
	}
}

int add(int val)
{
	if (NULL == head) return 0;
	nodePtr newNode;	
	newNode = (nodePtr) malloc (sizeof(struct node));
	newNode->val = val;
	newNode->next = head->next;
	head->next = newNode;
	head->val = (head->val)+1;
	return 1;
}


int getLength(nodePtr p)
{
	return head->val;  
}

int deleteFirstOccurence(int val)
{
	if (getLength(head) == 0) return 0;
	nodePtr current, prev;
	current = head->next;
	prev = head;
	while (current->val != val && current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (current->val == val)
	{
		prev->next = current->next;
		free(current);
		head->val = (head->val)-1;
		return 1;
	}
	else return 0;
}

int deDuplicate(void)
{
	if (getLength(head)==0 || getLength(head) == 1) return 0;
	nodePtr current = head->next;
	int a,b,noOfDuplicates=0;
	nodePtr prev;
	nodePtr now;
	while (current->next != NULL)
	{
		prev = current;
		now = prev->next;
		a = current->val;
		while (now != NULL )
		{
			b = now->val;
			if (b == a)
			{
				prev->next = now->next;
				now = now->next;
				noOfDuplicates++;
				head->val -= 1; 
			}
			else
			{
				if (now->next != NULL)
				{
					prev = prev->next;
					now = now->next;
				}
				else 
				{
					now = now->next;
				}


			}
		}	
		current = current->next;
	}
	return noOfDuplicates;
}

void reverseList(void)
{
	if (head->val ==0 || head->val ==1) return;
	nodePtr p;
	p = (nodePtr) malloc (sizeof(struct node));
	p->next = NULL;

	nodePtr current = head->next;
	p->val = current->val;
	current = current->next;
	nodePtr tmp = current->next;
	while (tmp != NULL)
	{
		current->next = p;
		p = current;
		current = tmp;
		tmp = tmp->next;	
	}
	current->next = p;
	p = current;
	head->next = p;
}

int isSorted(nodePtr p)
{
	if(getLength(p) == 0 || getLength(p)==1) return 1;
	nodePtr current = p;	
	nodePtr nex = current->next;
	while(nex != NULL)
	{
		if(current->val <= nex->val) {current = nex; nex = nex->next;}
		else return 0;	
	}
	return 1;	
}

int main(void)
{
	int op, val;

	int status;


	init();

	while(scanf("%d",&op) != EOF){
		switch(op){
			case 0: scanf("%d",&val);status=add(val); printf("%d\n",status);break;
			case 1: scanf("%d",&val);status=deleteFirstOccurence(val); 
					printf("%d\n",status);break;
			case 2: status=deDuplicate(); printf("%d\n",status);break;
			case 3: reverseList(); break;
			case 4: status=isSorted(head->next); printf("%d\n",status);break;
			case 5: status=getLength(head); printf("%d\n",status);break;
			case 6: printList(); break;
		}   
	}           

	printList();
	cleanup();
	return 0;
}

