#include<stdio.h>
int stringlen(char s[])
{
  int i=0;
  while(s[i]!='\0') i++;
  return i;
}

int main(void)
{
  char s1[101],s2[101];
  scanf("%s%s",s1,s2);
  int l1 = stringlen(s1);
  int l2 = stringlen(s2);
  
  int i,checker=0;
  for(i=0;i<l1;i++)
  {
    checker = checker^s1[i]^s2[i];
  }  
  if(checker == 0) printf("%s","yes");
  else printf("%s","no");
return 0;
}
