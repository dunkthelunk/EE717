#include<stdio.h>
int main(void)
{
	char str[11];
	char c;
	int i;
	for(i=0; i < 11 && ((c=getchar()) != '\n' && c != EOF ); ++i) str[i] = c;
	//scanf("%s",str);
	printf("%s %s.\n","Hello,",str);

}
