#include<stdio.h>
#include<malloc.h>
#include <sys/time.h>
void SelectionSort(int arr[],int n);
int main()
{
    printf("Enter The Sise Of Array in single block");
    int size;
    scanf("%d",&size);

    int *arr = (int *)malloc(sizeof(int) * size);

    printf("The Best Case");
    for(int i=0;i<size;i++)
    {
        arr[i]=i+1;
        printf("%d\n",arr[i]);
    }

printf("The Average case");
for(int i=0;i<size;i++)
{
    arr[i]=rand()%1000;
    printf("%d\n",arr[i]);    
}

printf("For Wrost Case");
int temp=size;
for(int i=0;i<size;i++)
{
    arr[i]=temp;                  
    temp--;
    printf("%d\n",arr[i]);
}

    struct timeval start, end;
    gettimeofday(&start, NULL); // Start time

    SelectionSort(arr, size);

    gettimeofday(&end, NULL); // End time

    double time_taken = (end.tv_sec - start.tv_sec) +
                        (end.tv_usec - start.tv_usec) / 1e6;

                          printf("\n");

    printf("Time taken: %f seconds\n", time_taken);
    printf("Time taken: %f seconds\n", time_taken);
    free(arr);
    return 0;
}
void SelectionSort(int arr[],int n)
{     int minIndex;
    for(int i=0;i<n-1;i++)
    {
        minIndex=i;
        for(int j=i+1;j<n;j++)
        {
              if(arr[j]<arr[minIndex])
              {
                minIndex=j;
              }
        }
        int temp;
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
        for (int i = 0; i < n; i++) {
        printf("%d\n ", arr[i]);
    }
}