#include<stdio.h>
int main(void)
{

	long int num;
	int digitalRoot=0;
	scanf("%ld", &num);

	while(num != 0)
	{
		digitalRoot = digitalRoot + (num%10); 

		digitalRoot = (digitalRoot >= 10) ? 1+ digitalRoot%10:digitalRoot;

		num = num/10;
	}


	printf("%d",digitalRoot);	

	return 0;
}
