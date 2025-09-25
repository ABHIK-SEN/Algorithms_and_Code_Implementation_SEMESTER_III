#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **A, **B, **C, m, n, p, q, i, j;

    printf("\n Enter ROW Size of Matrix A: ");
    scanf("%d", &m);
    printf("\n Enter COLUMN size of Matrix A: ");
    scanf("%d", &n);

    printf("\n Enter ROW size of Matrix B: ");
    scanf("%d", &p);
    printf("\n Enter COLUMN size of Matrix B: ");
    scanf("%d", &q);

    if(m!=p || n!=q)
    {
        printf("\n Matrix Subtraction NOT Possible!\n");
        return 0;
    }

    A=(int**)malloc(m*sizeof(int*));
    for(i=0; i<m; i++)
        A[i]=(int*)malloc(n*sizeof(int));

    B=(int**)malloc(p*sizeof(int*));
    for(i=0; i<p; i++)
        B[i]=(int*)malloc(q*sizeof(int));

    C=(int**)malloc(m*sizeof(int*));
    for(i=0; i<m; i++)
        C[i]=(int*)malloc(q*sizeof(int));
    
    printf("\n Enter Elements in Matrix A: ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d", &A[i][j]);
    }

    printf("\n Enter Elements in Matrix B: ");
    for(i=0; i<p; i++)
    {
        for(j=0; j<q; j++)
            scanf("%d", &B[i][j]);
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<q; j++)
            C[i][j]=A[i][j]-B[i][j];
    }

    printf("\n Resultant Matrix C (Matrix A - Matrix B):\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<q; j++)
            printf("\t%d", C[i][j]);
        printf("\n");
    }
    printf("\n");

    for(i=0; i<m; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}