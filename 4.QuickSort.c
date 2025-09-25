#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int partition(int *arr, int start, int end);
void quickSort(int *arr, int start, int end);
int main()
{
    int *arr, n, i;

    printf("\n Enter the Size of the Array: ");
    scanf("%d", &n);
    arr=(int*)malloc(n*sizeof(int));
    if (arr==NULL)
    {
        printf("\n Memory Allocation Failed\n");
        return 1;
    }

    printf("\n Enter Elements in the Array: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("\n Unsorted Array: ");
    for(i=0; i<n; i++)
        printf("\t%d", arr[i]);

    quickSort(arr, 0, n-1);

    printf("\n Sorted Array in Ascending Order: ");
    for(i=0; i<n; i++)
        printf("\t%d", arr[i]);
    
    printf("\n Quick Sort performed Successfully\n");
    free(arr);

    return 0;
}

int partition(int *arr, int start, int end)
{
    int pivot=arr[end];
    int piIndex=(start-1);

    for(int i=start; i<end; i++)
    {
        if(arr[i]<=pivot)
        {
            piIndex++;
            swap(&arr[i], &arr[piIndex]);
        }
    }
    swap(&arr[end], &arr[piIndex+1]);
    return (piIndex+1);
}

void quickSort(int *arr, int start, int end)
{
    if (start<end)
    {
        int pi=partition(arr, start, end);
        quickSort(arr, start, pi-1);
        quickSort(arr, pi+1, end);
    }
}