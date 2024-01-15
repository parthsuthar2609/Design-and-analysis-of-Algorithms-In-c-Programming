#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include <sys/time.h>
#include <stdlib.h>
void BubbleSort(int arr[], int n);
 
int main()
{
    printf("Enter Size Of Array: ");
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    printf("Best case\n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1; // 0.001458
    }

    // printf("Avg case\n");
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = rand() % 1000; // 0.001823
    // }

    // printf("Worst case\n");
    // int temp = size;
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = temp; // 0.002649
    //     temp--;
    // }

    struct timeval start, stop;
    struct timezone tz;

  	gettimeofday(&start, &tz);
   	BubbleSort(arr, size);
	gettimeofday(&stop, &tz);
	
    double ans = (stop.tv_sec - start.tv_sec);
    double ans1 = (stop.tv_usec - start.tv_usec);
    double time = (ans+ans1)/1000;

    printf("%f", time);

    // clock_t start, stop;
    // start = clock();
    // BubbleSort(arr, size);

    // stop = clock();

    // double duration = (double)(stop - start) / CLOCKS_PER_SEC;
    // printf("%f", duration);

    // return 0;
}

void BubbleSort(int arr[],int n)
{
    int flag;
    for(int i=0;i<n;i++)
    {
        flag=0;
         for(int j=0;j<n-i-1;j++)
         {
            if(arr[j]<arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
         }
         if(flag == 0)
         {
         break;
    }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}

