#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long  n,credit;
    int i=0,sum=0,a[20],l,b;
    do
    {
    credit=get_long("Number:");
    }
    while(credit<=0);
    n=credit;

    while(credit>0)
    {
        a[i]=credit%10;
        credit=credit/10;
        i++;
    }
    l=i;
   // printf("%d",l);
   // printf("%d%d",a[l-1],a[0]);
    for(i=0;i<l;i++)
    {
        if((i%2)!=0)
        {
            if(2*a[i]<10)
            {
                sum+=(2*a[i]);
            }
            else
            {
                sum+=((2*a[i])%10);
                b=(2*a[i])/10;
                sum+=b;
               // printf("%d\n",b);
            }
        }
        else
        {
            sum=sum+a[i];
        }
    }
   // printf("%d",sum);
    if((sum%10)!=0)
    {
        printf("INVALID\n");
    }
    else
    {
        if((a[l-1]==3&&a[l-2]==4)||(a[l-1]==3&&a[l-2]==7))
        {
            printf("AMEX\n");
        }
        else if(a[l-1]==4&&(l==13||l==14||l==15||l==16))
        {
            printf("VISA\n");
        }
        else if(a[l-1]==5&&(a[l-2]==1||a[l-2]==2||a[l-2]==3||a[l-2]==4||a[l-2]==5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");

        }
    }
}
















































































































































