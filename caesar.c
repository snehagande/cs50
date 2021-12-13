#include <stdio.h>
#include<stdlib.h>
#include <cs50.h>
#include<ctype.h>

int main(int argc,string argv[])
{

    int i=0,c;
    int key;
    char b;
   // bool is_small,is_capital;
   // string b[200];
   //printf("argv = %s\n",argv[1]);

    //printf("key b = %d\n",key);
    if (argc!=2)
    {
       printf("Usage: ./caesar key\n");
       return 1;
    }
    while((argv[1][i])!='\0')
    {
       if (isalpha(argv[1][i]))
       {
           printf("Usage: ./caesar key\n");
           return 1;
       }
       i++;
    }
    key = atoi(argv[1]);
    string a=get_string("plaintext:  ");
    i=0;
    printf("ciphertext: ");
   // printf("%c",a[i]);
    while(a[i]!='\0')
    {
        if (isalpha(a[i]))
        {
            c=(int)a[i];
            if(c>=97 && c<=122)
            {
               // printf("char = %c\n",a[i]);
                c=c-96;
                //printf("%d\n",key);
                c=(c+key)%26;
                if(c==0)
                b='z';
                else
                {
                c=c+96;
                b=(char)c;
                }


                printf("%c",b);
            }
            else
            {
                c=c-64;
                c=(c+key)%26;
                if(c==0)
                b='Z';
                else
                {
                c=c+64;
                b=(char)c;
                }
                printf("%c",b);
            }


            //printf("%d",c);
            //c=(c+key)%26;
           // b=(char)c;
           // printf("%c",b);
           // printf("%c",b);

        }
        else
        {

            printf("%c",a[i]);
           //b[i]=(char)c;
        }
        i++;
    }
    if(a[i]=='\0')
    {
        printf("\n");
    }
   // printf("\n");


}
