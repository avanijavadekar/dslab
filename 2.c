#include <stdio.h>
#include <stdlib.h>

void accept(int a[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[10][10], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void compact(int a[10][10], int s[100][3], int r, int c)
{
    int k = 1;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = k - 1;
}

void fastTranspose(int s[100][3], int t[100][3])
{
    int rowTerms[10] = {0};
    int startPos[10];
    int i, j;

    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];

    for(i = 1; i <= s[0][2]; i++)
    {
        rowTerms[s[i][1]]++;
    }

    startPos[0] = 1;

    for(i = 1; i < s[0][1]; i++)
    {
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    }

    for(i = 1; i <= s[0][2]; i++)
    {
        j = startPos[s[i][1]];

        t[j][0] = s[i][1];
        t[j][1] = s[i][0];
        t[j][2] = s[i][2];

        startPos[s[i][1]]++;
    }
}

void displayCompact(int s[100][3])
{
    int n = s[0][2];

    for(int i = 0; i <= n; i++)
    {
        printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
    }
}

int main()
{
    int a[10][10], b[10][10];
    int s[100][3], t[100][3];
    int r1, r2, c1, c2, ch;

    printf("Enter rows and columns of matrix a: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of matrix b: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter elements of matrix a:\n");
    accept(a, r1, c1);

    printf("Enter elements of matrix b:\n");
    accept(b, r2, c2);

    while(1)
    {
        printf("\n1. Display matrices\n2. Compact form\n3. Fast transpose\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nMatrix a:\n");
                display(a, r1, c1);

                printf("\nMatrix b:\n");
                display(b, r2, c2);
                break;

            case 2:
                compact(a, s, r1, c1);
                printf("\nCompact form of matrix a:\n");
                displayCompact(s);
                break;

            case 3:
                compact(a, s, r1, c1);
                fastTranspose(s, t);
                printf("\nFast transpose:\n");
                displayCompact(t);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}