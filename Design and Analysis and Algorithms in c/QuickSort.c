#include<stdio.h>
#include<malloc.h>
#include <sys/time.h>
#include<stdlib.h>
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
   printf("Enter The Size Of Array in single block");
    int size;
    scanf("%d",&size);

    int *arr = (int *)malloc(sizeof(int) * size);

    printf("The Best Case");
    for(int i=0;i<size;i++)
    {
        arr[i]=i+1;                 //Time taken: 0.735774 seconds
        printf("%d\n",arr[i]);
    }
//         struct timeval tr;
// struct timezone tz;

// int t1,t2,t3;

// gettimeofday(&tr,&tz);
// t1=tr.tv_usec;
// BubbleSort(arr,size);

// gettimeofday(&tr,&tz);
// t2=tr.tv_usec;
// t3=t2-t1;

// printf("The Time Complexity Is",t3);

// printf("The Average case");
// for(int i=0;i<size;i++)
// {
//     arr[i]=rand()%1000;
//     printf("%d\n",arr[i]);    //Time taken: 0.753768 seconds
// }

// printf("For Wrost Case");
// int temp=size;
// for(int i=0;i<size;i++)
// {
//     arr[i]=temp;                  //Time taken: 0.756807 seconds
//     temp--;
//     printf("%d\n",arr[i]);
// }

struct timeval start, end;
    gettimeofday(&start, NULL); // Start time

    quickSort(arr,0,size-1);

    gettimeofday(&end, NULL); // End time

    double time_taken = (end.tv_sec - start.tv_sec) +
                        (end.tv_usec - start.tv_usec) / 1e6;

                          printf("\n");

    printf("Time taken: %f seconds\n", time_taken);
     printf("Time taken: %f seconds\n", time_taken);

    free(arr);

  return 0;
}
