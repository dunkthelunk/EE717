#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int head, tail, total=0;
int arraySize=0;

char opNames[7][12] = {"push_back","push_front","pop_back","pop_front","back","front","isEmpty"};

void init(int num)
{
	arraySize = num;
	array = (int *) malloc(sizeof(int)*(arraySize)); 
	head = arraySize-1;
	tail = 0;
}

void cleanup()
{
	free(array);    
}

int push_back(int val)
{
	if (total == arraySize) return 0;
	array[tail] = val; 
	tail = (tail+1)%arraySize;
	total++;
	return 1; 
}

int push_front(int val)
{
	if (total == arraySize) return 0;
	array[head] = val;
	head = (arraySize+head-1)%arraySize;
	total++;
	return 1;

}

int isEmpty()
{
	return total==0 ? 1:0;    
}

int pop_back()
{
	if(isEmpty()) return -1;
	total--;
	tail = (arraySize+tail-1)%arraySize;
	return array[tail];    
}

int pop_front()
{
	if(isEmpty()) return -1;
	total--;
	head = (head+1)%arraySize;
	return array[head];    
}

int back()
{
	if(isEmpty()) return -1;
	return array[(arraySize+tail-1)%arraySize];
}

int front()
{
	if(isEmpty()) return -1;
	return array[(head+1)%arraySize];
}

void displayQueue()
{
	int i;

	printf("Deque: ");
	for(i=0; i<total; i++){
		printf("%d ",array[(head+i+1)%arraySize]);
	}
	printf("\n");
}

int main(void)
{
	int N;

	int op, val;

	int status;


	scanf("%d",&N);
	init(N);

	while(scanf("%d",&op) != EOF){
		//printf("op = %s\n",opNames[op]);
		switch(op){
			case 0: scanf("%d",&val);status=push_back(val); printf("%d\n",status);break;
			case 1: scanf("%d",&val);status=push_front(val); printf("%d\n",status);break;
			case 2: status=pop_back(); printf("%d\n",status);break;
			case 3: status=pop_front(); printf("%d\n",status);break;
			case 4: status=back(); printf("%d\n",status);break;
			case 5: status=front(); printf("%d\n",status);break;
			case 6: status=isEmpty();printf("%d\n",status);break;
			case 7: displayQueue(); break;
		}
	}       
	displayQueue();
	cleanup();
	return 0;
}
