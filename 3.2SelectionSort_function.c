#include <stdio.h>
#include <stdlib.h>
void selectionSort(int *arr, int n);
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

    selectionSort(arr, n);

    printf("\n Sorted Array in Ascending Order: ");
    for(i=0; i<n; i++)
        printf("\t%d", arr[i]);

    printf("\n Selection Sort performed Successfully\n");
    free(arr);

    return 0;
}

void selectionSort(int *arr, int n)
{
    int i, j, min, tmp;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        tmp=arr[i];
        arr[i]=arr[min];
        arr[min]=tmp;
    }
}