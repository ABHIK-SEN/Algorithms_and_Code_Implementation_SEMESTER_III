#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr, int n);
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
    
    bubbleSort(arr, n);

    printf("\n Sorted Array in Ascending Order: ");
    for(i=0 ; i<n; i++)
        printf("\t%d", arr[i]);

    printf("\n Bubble Sort Peformed Successfully\n");

    free(arr);

    return 0;
}

void bubbleSort(int *arr, int n)
{
    int i, j, tmp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if( arr[j]>arr[j+1] )
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;   
            }
        }
    }
}
