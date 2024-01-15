#include<stdio.h>
#define max  2000

// arr - will have a list of needed coins
int ans[max];

int findMinCoins(int coins[], int size, int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        // take as much from coins[i]
        while(value >= coins[i])
        {
            // after taking the coin, reduce the value.
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;
    }

    return count;
}

int main()
{
    int coins[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int value, i;

    printf("Enter The Value You Want To Change: ");
    scanf("%d", &value);

    // find the size of the coins array
    int size = sizeof(coins) / sizeof(coins[0]);

    int MinCount = findMinCoins(coins, size, value);

    printf("Total Coins Needed = %d\n", MinCount);

    printf("Coins are:\t");
    for(i = 0; i < MinCount; i++)
        printf("%d ", ans[i]);

    return 0;
}
