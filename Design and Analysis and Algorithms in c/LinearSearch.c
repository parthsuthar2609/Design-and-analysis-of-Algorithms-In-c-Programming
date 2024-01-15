#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int Search(int arr[],int n, int key);

int main()
{
    printf("Enter Size Of Array: ");
    int size;
    scanf("%d", &size);
    
    printf("Enter The Key Element:");
    int key;
    scanf("%d",&key);

    int *arr = (int *)malloc(size * sizeof(int));
    
    printf("The Best Case");
    for (int i = 0; i < size; i++)
    {
        arr[i] = i+1;
        printf("%d",arr[i]);
    }
    
    // printf("The Average Case");
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = rand()%1000;
    //     printf("%d",arr[i]);
    // }
    
    // printf("The Worst Case");
    // int temp=size;
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = temp;
    //     temp--;
    //     printf("%d",arr[i]);
    // }

    struct timeval start, stop;
    struct timezone tz;

   	gettimeofday(&start, &tz);
        Search(arr,size,key);
	gettimeofday(&stop, &tz);
	
    double ans = (stop.tv_sec - start.tv_sec);
    double ans1 = (stop.tv_usec - start.tv_usec);
    double time = (ans+ans1)/1000;

    printf("The Time Taken Is:%f", time);
   
  return 0;
 }
 
 int Search(int arr[],int x, int mid)
   {
       int right;
       int left;
       while (left <= right) {
       mid = (right + left) /2;
       
         if (arr[mid] == x)
            return mid;
 

        if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}