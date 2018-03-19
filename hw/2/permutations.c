#include<stdio.h>
int stringlen(char s[])
{
  int i=0;
  while(s[i]!='\0') i++;
  return i;
}

void stringHisto(char histo[],char s[],int l)
{
  int i = 0;
  for (i=0;i<l;i++) histo[s[i]]++;  
}

int main(void)
{
  int yes;
  char histo1[128]={0},histo2[128]={0};
  char s1[101],s2[101];
  scanf("%s%s",s1,s2);
  int l1 = stringlen(s1);
  int l2 = stringlen(s2);
  if (l1==l2)
  {      
    yes = 1;
    stringHisto(histo1,s1,l1);
    stringHisto(histo2,s2,l2);
    int j;
    for(j=0;j<l1;j++)
    {
      if(histo1[s1[j]] != histo2[s1[j]])
      {
        yes = 0;
        break;        
      }
    }
  }
  else yes = 0;
  
  if(yes ==1) printf("%s","yes");
  else printf("%s","no");
  
  return 0;
}
