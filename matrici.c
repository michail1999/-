#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int m, n, **matrix1, i, j;

    scanf("%d %d", &m, &n);
    printf("\n\n");
    srand(time(NULL));
    matrix1 = (int**) malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
        matrix1[i] = (int*) malloc(n * sizeof(int));
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            matrix1[i][j] = rand()%10;
    printf("Generating first matrix: \n");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%6d ", matrix1[i][j]);
    }
    printf("\n\n");

    int save;
    for (i = 0; i < n; i++)
    {
        save = matrix1[0][i];
        matrix1[0][i] = matrix1[m - 1][i];
        matrix1[m - 1][i] = save;
    }

    for (i = 0; i < (n / 2); i++)
    {
        save = matrix1[0][n - i - 1];
        matrix1[0][n - i - 1] = matrix1[0][i];
        matrix1[0][i] = save;
        save = matrix1[m - 1][n - i - 1];
        matrix1[m - 1][n - i - 1] = matrix1[m - 1][i];
        matrix1[m - 1][i] = save;
    }
    printf("Reversing and exchanging rows: \n");
    for (i = 0; i < m; i++)
        {
            printf("\n");
            for (j = 0; j < n; j++)
                printf("%6d ", matrix1[i][j]);
        }
    printf("\n\n");

    int minn = INT_MAX, **matrix2 = NULL, ii, jj, ni = 0, nj = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            if (matrix1[i][j] < minn)
            {
                minn = matrix1[i][j];
                ii = i;
                jj = j;
            }
        }
    matrix2 = (int**) malloc((m - 1) * sizeof(int*));
    for (i = 0; i < m; i++)
        matrix2[i] = (int*) malloc((n - 1) * sizeof(int));
    for (i = 0; i < m; i++)
    {
        if (i == ii)
            continue;
        for (j = 0; j < n; j++)
        {
                if (j != jj) {
                    matrix2[ni][nj] = matrix1[i][j];
                    nj++;
                }
                else
                continue;
        }
        nj = 0;
        ni++;
    }
    printf("Necessary rows has been deleted: \n");
    for (i = 0; i < m - 1; i++)
        {
            printf("\n");
            for (j = 0; j < n - 1; j++)
                printf("%6d ", matrix2[i][j]);
        }
    printf("\n\n");

    int l = 0, qr = 1, qc = 0, vi = 0, **fa = NULL, flag = 0;
    char s[100] = {0}, *a = NULL, *value = NULL;

    fflush(stdin);
    printf("Print values for new matrix in appropriate format: \n\n");
    a = fgets(s, sizeof(s), stdin);
    l = strlen(a) - 2;
    i = 0;
    for (i = 0; i < l; i++)
    {
        if ((a[i] == ' ') && (flag == 0))
        {
            qc++;
        }
        if (a[i] == ',')
        {
            qr++;
            i++;
            flag = 1;
        }
    }
    fa = (int**) malloc(qr * sizeof(int*));
    for (i = 0; i < qr; i++)
        fa[i] = (int*) malloc(qc * sizeof(int));
    qc = 0;
    qr = 0;
    value = (char*) malloc(6*sizeof(char));
    for (i = 0; i < l; i++)
    {
    if (isdigit(a[i]) != 0)
        {
            value[vi] = a[i];
            vi++;
        }
    if ((a[i] == ' ') && (a[i - 1] != ',') ) {
            fa[qr][qc] = atoi(value);
            vi = 0;
            qc++;
            free(value);
            value = (char*) malloc(6*sizeof(char));
    }
    if (a[i] == ',') {
            qr++;
            qc = 0;
    }
    if (a[i] == '.') {
            qr++;
    }
    }
    qr++;
    printf("Array has been created: \n\n");
    for (i = 0; i < qr; i++) {
            printf("\n");
        for (j = 0; j < qc; j++)
            printf("%6d ", fa[i][j]);
    }
    printf("\n\n");


    int **matrix3, k;
    matrix3 = (int**) malloc((n-1) * sizeof(int*));
    for (i = 0; i < n - 1; i++)
        matrix3[i] = (int*) malloc(qr * sizeof(int));
    printf("Matrixes has been multiplied: \n\n");
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < qc; j++)
        {
            for (k = 0; k < n - 1; k++)
                matrix3[i][j] = matrix1[i][k] * matrix2[k][j];
            printf("%6d ", matrix3[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Successfully done.\n");
    printf("\n\n");
    return(0);
}
