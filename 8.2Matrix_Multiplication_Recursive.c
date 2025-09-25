#include <stdio.h>
#include <stdlib.h>
void multiply_matrices(int **A, int **B, int **C, int row1, int col1, int col2, int i, int j, int k);
int main()
{
    int **A, **B, **C, m, n, p, q, i, j, k;

    printf("\n Enter ROW Size of Matrix A: ");
    scanf("%d", &m);
    printf("\n Enter COLUMN size of Matrix A: ");
    scanf("%d", &n);

    printf("\n Enter ROW size of Matrix B: ");
    scanf("%d", &p);
    printf("\n Enter COLUMN size of Matrix B: ");
    scanf("%d", &q);

    if(n!=p)
    {
        printf("\n Matrix Multiplication NOT Possible!\n");
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

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
            C[i][j] = 0;
    }

    multiply_matrices(A, B, C, m, n, q, 0, 0, 0);

    printf("\n Resultant Matrix C (Matrix A * Matrix B):\n");
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

void multiply_matrices(int **A, int **B, int **C, int row1, int col1, int col2, int i, int j, int k)
{
    if(i>=row1)
        return;
    if(j>=col2)
    {
        multiply_matrices(A, B, C, row1, col1, col2, i + 1, 0, 0);
        return;
    }

    if(k<col1)
    {
        C[i][j]+=A[i][k]*B[k][j];
        multiply_matrices(A, B, C, row1, col1, col2, i, j, k + 1);
    }
    else
        multiply_matrices(A, B, C, row1, col1, col2, i, j + 1, 0); 
}