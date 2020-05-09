#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // coin values
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    
    float dollars = -1;
    int coins = 0;

    // user input
    while (dollars < 0)
    {
        dollars = get_float("Change owed: ");
    }

    // multiply by 100 to consider cents and roundoff
    int cents = round(dollars * 100);

    // compute for number of coins until cents is 0
    do
    {
        int current_coins = 0;
        int num_coins = 0;

        if (cents / quarters > 0)
        {
            num_coins = cents / quarters;
            coins += num_coins;
            current_coins = num_coins * quarters;
        }
        else if (cents / dimes > 0) 
        {
            num_coins = cents / dimes;
            coins += num_coins;
            current_coins = num_coins * dimes;
        }
        else if (cents / nickels > 0)
        {
            num_coins = cents / nickels;
            coins += num_coins;
            current_coins = num_coins * nickels;
        }
        else 
        {
            num_coins = cents / pennies;
            coins += num_coins;
            current_coins = num_coins * pennies;
        }

        // track current amount
        cents -= current_coins;
    }
    while (cents > 0);

    // output how many coins are used for change
    printf("%i\n", coins);
}
