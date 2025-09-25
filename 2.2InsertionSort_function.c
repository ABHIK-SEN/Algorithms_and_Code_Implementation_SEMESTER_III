#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *arr, int n);
int main()
{
    int *arr, n, i;

    printf("\n Enter the Size of the Array: ");
    scanf("%d", &n);
    arr=(int*)malloc(n*sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("\n Enter Elements in the Array: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    printf("\n Unsorted Array: ");
    for(i=0; i<n; i++)
        printf("\t%d", arr[i]);

    insertionSort(arr, n);

    printf("\n Sorted Array in Ascending Order: ");
    for(i=0; i<n; i++)
        printf("\t%d", arr[i]);
    
    printf("\n Insertion Sort Function performed Successfully\n");
    free(arr);

    return 0;
}

void insertionSort(int *arr, int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key=arr[i];
        j=(i-1);
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}