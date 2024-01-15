#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void swap(int *a, int *b);
void MaxHeapify(int arr[], int size, int i);
void HeapSort(int arr[], int size);

int main()
{
    printf("Enter Size Of Array: ");
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }

    struct timeval start, stop;
    struct timezone tz;

  	gettimeofday(&start, &tz);
   	HeapSort(arr, size);
	gettimeofday(&stop, &tz);
	
    double ans = (stop.tv_sec - start.tv_sec);
    double ans1 = (stop.tv_usec - start.tv_usec);
    double time = (ans+ans1)/1000;

    printf("%f", time);
    
    // clock_t start,stop;
    // start=clock();
    //     HeapSort(arr, size);
    // stop=clock();
    // double ans=(double)(stop-start)/CLOCKS_PER_SEC;
    // printf("The Time Complexity Is:%f" ,ans);
    // return 0;
}
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void MaxHeapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(arr, size, largest);
    }
}

void HeapSort(int arr[], int size)
{
    // BuildHeap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(arr, size, i);
    }

    for (int i = size - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        MaxHeapify(arr, i, 0);
    }
    
}