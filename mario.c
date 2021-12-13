#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i, j, n;
    do
    {

        //getting height
        n = get_int("height:");
    }
    while (n < 1 || n > 8);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            //printing spaces
            printf(" ");
        }


        for (j = 1; j <= i; j++)
        {
            //printing #
            printf("#");
        }
        printf("  ");
        for (j = 1; j <= i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}