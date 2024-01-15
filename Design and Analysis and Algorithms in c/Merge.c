// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	i = 0;

	j = 0;

	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int main()
{
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

     mergeSort(arr,0,size-1);

    gettimeofday(&end, NULL); // End time

    double time_taken = (end.tv_sec - start.tv_sec) +
                        (end.tv_usec - start.tv_usec) / 1e6;

                          printf("\n");

    printf("Time taken: %f seconds\n", time_taken);
     printf("Time taken: %f seconds\n", time_taken);

    free(arr);

  return 0;

   
}
