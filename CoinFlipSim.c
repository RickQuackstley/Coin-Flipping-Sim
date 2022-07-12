#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "coins.h"

void flip(float cns, int r);

//use second command line argument as the number of coins being flipped
int main(int argc, char **argv)
{
    srand(time(NULL));

    char *errorMsg = "please enter a valid number\nmake sure your number does not contain any decimal values or special characters";

    if (argc == 2)
    {
        if (isNum(argv[1]) && argv[1][0] != '0')
        {
            int rand;
            int c = atoi(argv[1]);
            printf("number of coins being flipped: %i\n\n", c);
            flip(c, rand);
        }

        else
        {
            printf("%s", errorMsg);
            return 1;
        }
    }

    else
    {
        printf("%s", errorMsg);
        return 1;
    }

    return 0;
}

void flip(float cns, int r)
{
    coins c;

    c.heads = 0;
    c.tails = 0;

    for (int i = 0; i < cns; i++)
    {
        r = rand() % 2; 
        printf("you flipped coin: %i\n", i + 1);
        printf("value of coin %i: %i\n\n", i + 1, r);

        if (r == 0)
        {
            c.heads++;
        }

        else
        {
            c.tails++;
        }
    }

    float n = 100 / cns;
    printf("heads: %fpercent\n", n * c.heads);
    printf("tails: %fpercent", n * c.tails);
    //percentage = (100 / totalcoins) * #ofcoinsheadortails
}

bool isNum(char *str)
{
    for (int a = 0, n = strlen(str); a < n; a++)
    {
        for (char b = 'A'; b <= 'Z'; b++)
        {
            //ALL LETTERS
            if (toupper(str[a]) == b)
            {
                return false;
            }
        }

        for (int c = 33; c <= 47; c++)
        {
            //ASCII 39-47
            if ((int)str[a] == c)
            {
                return false;
            }
        }

        for (int d = 58; d <= 64; d++)
        {
            //ASCII 58-64
            if ((int)str[a] == d)
            {
                return false;
            }
        }

        for (int e = 91; e <= 96; e++)
        {
            //ASCII 91-96
            if ((int)str[a] == e)
            {
                return false;
            }
        }

        for (int f = 123; f <= 126; f++)
        {
            //ASCII 123-126
            if ((int)str[a] == f)
            {
                return false;
            }
        }
    }

    return true;
}