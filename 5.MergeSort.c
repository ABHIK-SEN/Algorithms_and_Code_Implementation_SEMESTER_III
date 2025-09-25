#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);
int main()
{
    int *arr, n, i;
    
    printf("\n Enter the Size of the Array: ");
    scanf("%d", &n);
    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
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

    mergeSort(arr, 0, n-1);

    printf("\n Sorted Array in Ascending Order: ");
    for(i=0; i<n; i++)
        printf("\t%d", arr[i]);

    printf("\n Merge Sort performed Successfully\n");
    free(arr);

    return 0;
}

void mergeSort(int *arr, int left, int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int *L, *R, n1, n2, i, j, k;
    n1=(mid-left+1);
    n2=(right-mid);
    L=(int*)malloc(n1*sizeof(int));
    R=(int*)malloc(n2*sizeof(int));
    if(L==NULL || R==NULL)
    {
        printf("\n Memory Allocation Failed\n");
        exit(1);
    }

    for(i=0; i<n1; i++)
        L[i]=arr[left+i];
    for(j=0; j<n2; j++)
        R[j]=arr[mid+1+j];
    
    i=0; j=0; k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}