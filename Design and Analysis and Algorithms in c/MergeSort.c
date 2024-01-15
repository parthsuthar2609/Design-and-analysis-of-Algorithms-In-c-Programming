#include<stdio.h>
#include<malloc.h>
#include <sys/time.h>

// Function to merge two subarrays of arr[]
void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

// Merge Sort function
void merge_sort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Split the array into two halves
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort each half
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted halves
    merge(arr, left, right, mid, size - mid);
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

    merge_sort(arr, size);

    gettimeofday(&end, NULL); // End time

    double time_taken = (end.tv_sec - start.tv_sec) +
                        (end.tv_usec - start.tv_usec) / 1e6;

                          printf("\n");

    printf("Time taken: %f seconds\n", time_taken);
     printf("Time taken: %f seconds\n", time_taken);

    free(arr);

  return 0;

   
}
