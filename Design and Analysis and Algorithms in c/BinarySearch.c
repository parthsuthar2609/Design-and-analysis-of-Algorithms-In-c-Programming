#include <stdio.h>
#include<time.h>
#include<malloc.h>
#include <sys/time.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;           // Left index of the search range
    int right = size - 1;   // Right index of the search range

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index

        if (arr[mid] == target) {
            return mid;  // Element found, return its index
        }
        if (arr[mid] < target) {
            left = mid + 1;  // Adjust the left index
        } else {
            right = mid - 1;  // Adjust the right index
        }
    }

    return -1;  // Element not found
}

int main() {


      printf("Enter Size Of Array: ");
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    
    int target;
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

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

  
//     clock_t start, stop;
//     start = clock();
//    binarySearch(arr, size,target);

//     stop = clock();

//     double duration = (double)(stop - start) / CLOCKS_PER_SEC;
//     printf("%f The Time Taken", duration);
//     return 0;

}
