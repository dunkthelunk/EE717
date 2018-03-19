#include<stdio.h>
int main(void)
{
		int n;  
		scanf("%d",&n);

		int frequency[201]={0};

		int input[n];
		int i;
		for (i=0; i < n; i++) 
		{
				scanf("%d",&input[i]);
				++frequency[100+input[i]];
		}

		int max = frequency[0], argmax = 0;
		int j;
		for (i=1; i<201; i++)
		{
				if (frequency[i]==max)
				{
					for (j=0; j<n; j++)
					{
						if ( input[j] == i-100) 
						{
							max = frequency[i];
							argmax = i;
							break;
						}
						else if ( input[j] == argmax-100) break;
					}
				} 
				else if (frequency[i] > max)
				{
						max = frequency[i];
						argmax = i;    
				}
		}

		printf("%d", argmax-100);
	return 0;
}
