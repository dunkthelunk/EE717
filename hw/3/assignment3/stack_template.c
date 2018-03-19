#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int arraySize=0;

char opNames[4][8] = {"push","pop","peek","isEmpty"};

int stack0Length=0, stack1Length=0;
void init(int num)
{
  arraySize = num;
  array = (int *) malloc(sizeof(int)*(arraySize));
}
void cleanup()
{
  free(array);
}
int push(int stack, int val)
{
  if (stack0Length+stack1Length == arraySize) return -1;
  (stack==0)?(array[stack0Length++]=val):(array[arraySize-1-(stack1Length++)]=val);
  return 1;
}

int pop(int stack)
{
  if (stack==0) return (stack0Length != 0) ? array[(stack0Length--)-1]:  -1;
  else return (stack1Length != 0) ? array[arraySize-(stack1Length--)]: -1;
}

int peek(int stack)
{
  if (stack==0) return (stack0Length != 0) ? array[stack0Length-1]:-1;
  else return (stack1Length != 0) ? array[arraySize-stack1Length]:-1;
}

int isEmpty(int stack)
{
    if (stack==0) return stack0Length==0 ? 1 : 0;
    else return stack1Length==0 ? 1 : 0;
}


int main(void)
{
        int N;
        int i;

        int op, val, stack;

        int status;


        scanf("%d",&N);
        init(N);

        while(scanf("%d %d",&op,&stack) != EOF){
                //printf("op = %s stack = %d\n",opNames[op],stack);
                switch(op){
                        case 0: scanf("%d",&val);status=push(stack,val); printf("%d\n",status);break;
                        case 1: status=pop(stack); printf("%d\n",status);break;
                        case 2: status=peek(stack); printf("%d\n",status);break;
                        case 3: status=isEmpty(stack);printf("%d\n",status);break;break;
                }
        }       
        cleanup();
        return 0;
}
