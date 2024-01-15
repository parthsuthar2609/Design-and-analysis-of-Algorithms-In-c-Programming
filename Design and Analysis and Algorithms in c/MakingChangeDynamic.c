#include <stdio.h>
#include <stdlib.h>
int main()
{
     int m, n, i, j;
     printf("Enter the amount of which you want change\n");
     scanf("%d", &m);
     printf("\nEnter the number of determinants\n");
     scanf("%d", &n);
     int c[n + 1][m + 1], dc[n + 1];
     printf("\nEnter the determinants\n");
     dc[0] = 0;
     for (i = 1; i < n + 1; i++)
          scanf("%d", &dc[i]);
     for (i = 0; i < n + 1; i++)
     {
          for (j = 0; j <= m; j++)
               c[i][j] = 0;
     }
     for (i = 0; i < n + 1; i++)
          c[i][0] = 0;
     for (i = 0; i < m + 1; i++)
     {
          c[0][i] = i;
     }
     for (i = 1; i < n + 1; i++)
     {
          for (j = 1; j < m + 1; j++)
          {
               if (dc[1] > c[0][j])
                    c[i][j] = 0;
               else if (dc[i] <= j)
               {
                    if ((c[i][j - dc[i]] + 1) < c[i - 1][j])
                         c[i][j] = (c[i][j - dc[i]] + 1);
                    else
                         c[i][j] = c[i - 1][j];
               }
               else
                    c[i][j] = c[i - 1][j];
          }
     }
     printf("\n");
     for (i = 0; i < n + 1; i++)
     {
          printf("%d  ", dc[i]);
          for (j = 0; j < m + 1; j++)
          {
               printf("  %d", c[i][j]);
          }
          printf("\n");
     }
     printf("\nThe change you get is \n");
     i = n;
     j = m;
     while (i != 1)
     {
          if (c[i][j] == c[i - 1][j])
               i = i - 1;
          else
          {
               j = j - dc[i];
               printf(" %d ", dc[i]);
          }
     }
     printf("\n\n");
     return 0;
}