#include<stdio.h>
int main(void)
{

  char s1[20],s2[20];
  scanf("%s%s",s1,s2);
  
  int i,l1=0,l2=0, index=-1;
  for (i=0; i <20; i++) if(s1[i] == '\0') break;
  l1 = i;
  for ( i = 0; i <20;i++) if (s2[i] == '\0') break;
  l2 = i;
  
  int j;
  int matches=0;
  for ( i = 0; i < l1 ; i++)
  {
    if ( s2[0] == s1[i])
    {
      matches = 1;
      index = i;
      for ( j=1; (j<l2) && matches; j++)
      {
      	matches = (s1[index+j]==s2[j]);
      }
      if(matches) break;
    }
  }
  if (matches) printf("%d",index);
  else printf("%d",-1);
  return 0;
}
