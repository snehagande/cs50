#include <stdio.h>
#include<ctype.h>
#include <cs50.h>
#include<math.h>

int main(void)
{
  float l,w,s,index;
  int i=0,intdex;

  //printf("%f",l);
   //char a[500];
  string a=get_string("Text: ");
  // printf("%c",a[3]);
  //for(i=0;i<500;i++)
  //{
  l=0;
  while(a[i]!='\0')
  {
      if(isalnum(a[i]))
      {
          l=l+1;
      }
      i++;


  }
  i=0;
  w=0;
  while(a[i]!='\0')
  {
      if(a[i]==' ')
      w=w+1;
      i++;
  }
  w=w+1;
  i=0;
  s=0;
  while(a[i]!='\0')
  {
      if(a[i]=='.'||a[i]=='?'||a[i]=='!')
      {
         s++;
      }
      i++;
  }
  //w=w/5;
  //printf("%f",w);
  l=(100*l)/w;
  s=(100*s)/w;
  index = 0.0588 * l - 0.296 * s - 15.8;
  index=round(index);
  intdex=((int)index);
  if(intdex<1)
     printf("Before Grade 1\n");
  else if(intdex>16)
     printf("Grade 16+\n");
  else
     printf("Grade %d\n",intdex);



}