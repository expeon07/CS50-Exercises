#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get height from user
    int height = -1;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    // print ladder according to height given
    for (int i = 1; i < (height + 1); i++)
    {
        for (int j = 1; j < (height - i + 1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // go to next lines
        printf("\n");
    }
}
