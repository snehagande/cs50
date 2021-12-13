#include <stdio.h>
#include <cs50.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    int i = 0, c, count = 0, key, b;
    int k[26];
    char d;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    while (argv[1][i] != '\0')
    {
        count++;
        i++;
    }
    if (count != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    i = 0;
    for (i = 0; i < 26; i++)
    {
        k[i] = 0;
    }
    for (i = 0; i < 26; i++)
    {
        if (isalpha(argv[1][i]))
        {
            if (isupper(argv[1][i]))
            {
                key = (int)argv[1][i];
                key = key - 64;
                k[key - 1]++;
            }
            if (islower(argv[1][i]))
            {
                key = (int)(argv[1][i]);
                key = key - 96;
                k[key - 1]++;
            }
        }
        else
        {
            printf("Usage: ./substitution key enter only characters\n");
            return 1;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (k[i] != 1)
        {
            printf("enter each character only once\n");
            return 1;
        }
    }
    i = 0;
    string a = get_string("plaintext:  ");
    printf("ciphertext: ");
    while (a[i] != '\0')
    {
        if (isupper(a[i]))
        {
            b = (int)a[i];
            b = b - 64;
            if (islower(argv[1][b - 1]))
            {
                c = (int)argv[1][b - 1] - 32;
                d = (char)c;
                printf("%c", d);
            }
            else
            {
                printf("%c", argv[1][b - 1]);
            }
        }
        else if (islower(a[i]))
        {
            b = (int)a[i];
            b = b - 96;
            if (isupper(argv[1][b - 1]))
            {
                c = (int)argv[1][b - 1] + 32;
                d = (char)c;
                printf("%c", d);
            }
            else
            {
                printf("%c", argv[1][b - 1]);
            }

        }
        else
        {
            printf("%c", a[i]);
        }
        i++;

    }
    printf("\n");

}