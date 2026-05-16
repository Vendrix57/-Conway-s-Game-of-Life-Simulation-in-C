#include <stdio.h>
#include <stdlib.h>

#define RAND_SEED 7 // No = for define

int Col = 4;
int Row = 4;
int Rand_x = RAND_SEED;

void row_line()
{
    printf("\n");

    for (int i = 0; i < Col; i++)
    {
        printf(" -----");
    }
    printf("\n");
}

void rand_init(int s)
{
    if (s > 0 && s < 16)
    {
        Rand_x = s;
    }
}

int Rand_no()
{
    Rand_x = (5 * Rand_x + 3) % 16;

    return Rand_x % 2; // For 2 outputs which are 0 and 1
}

void Gen_cells(int A[Row][Col])
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            A[i][j] = Rand_no();
        }
    }
}

int count_live_neighs(int A[Row][Col], int r, int c)
{
    int i, j;
    int count = 0;

    for (i = r - 1; i <= r + 1; i++)
    {
        for (j = c - 1; j <= c + 1; j++)
        {
            if (i >= 0 && i < Row && j >= 0 && j < Col)
            {
                if (!(i == r && j == c))
                {
                    if (A[i][j] == 1)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

void Next_Gen(int A[Row][Col], int B[Row][Col])
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            int n_live = count_live_neighs(A, i, j);

            if (A[i][j] == 1 && (n_live == 2 || n_live == 3))
            {
                B[i][j] = 1;
            }

            else if (A[i][j] == 0 && n_live == 3)
            {
                B[i][j] = 1;
            }

            else
            {
                B[i][j] = 0;
            }
        }
    }
}

void PrintMat(int A[Row][Col])
{
    int i, j;
    printf(" Initial Stage:");

    row_line();

    for (i = 0; i < Row; i++)
    {
        printf("|");
        for (j = 0; j < Col; j++)
        {
            printf("  %d  |", A[i][j]);
        }
        // printf("\n");
        row_line();
    }
}

void PrintNextGen(int A[Row][Col], int B[Row][Col])
{
    int i, j;
    printf(" Next Generation:");

    row_line();

    for (i = 0; i < Row; i++)
    {
        printf("|");
        for (j = 0; j < Col; j++)
        {
            printf("  %d  |", B[i][j]);
        }
        row_line();
    }
}

int main()
{
    int A[Row][Col];
    int B[Row][Col];

    rand_init(5);
    Gen_cells(A);
    PrintMat(A);
    Next_Gen(A, B);

    printf("\n");
    PrintNextGen(A, B);

    return 0;
}
