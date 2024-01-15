#include <stdio.h>
#include <stdlib.h> 

int findMinCoins(int coins[], int size, int value, int ans[])
{
    int i, count = 0;

    for (i = 0; i < size; i++)
    {
       
        while (value >= coins[i])
        {
        
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if (value == 0)
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

    int size = sizeof(coins) / sizeof(coins[0]);

    int *ans = (int *)malloc(sizeof(int) * value);

    int MinCount = findMinCoins(coins, size, value, ans);

    printf("Total Coins Needed = %d\n", MinCount);

    printf("Coins are:\t");
    for (i = 0; i < MinCount; i++)
        printf("%d\n ", ans[i]);

    free(ans);

    return 0;
}

