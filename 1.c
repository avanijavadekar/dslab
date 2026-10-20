#include <stdio.h>
#include <stdlib.h>

void accept(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void display(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void add(int a[10][10], int b[10][10], int r, int c) {
    int i, j, d[10][10];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            d[i][j] = a[i][j] + b[i][j];
    display(d, r, c);
}

void subtract(int a[10][10], int b[10][10], int r, int c) {
    int i, j, d[10][10];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            d[i][j] = a[i][j] - b[i][j];
    display(d, r, c);
}

void multiply(int a[10][10], int b[10][10], int r, int c) {
    int i, j, k, d[10][10] = {0};
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            for (k = 0; k < c; k++)
                d[i][j] += a[i][k] * b[k][j];
    display(d, r, c);
}

void transpose(int a[10][10], int r, int c) {
    int i, j, d[10][10];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            d[j][i] = a[i][j];
    display(d, c, r);
}

int main() {
    int a[10][10], b[10][10], r, c, ch;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter first matrix:\n");
    accept(a, r, c);

    printf("Enter second matrix:\n");
    accept(b, r, c);

    while (1) {
        printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                add(a, b, r, c);
                break;
            case 2:
                subtract(a, b, r, c);
                break;
            case 3:
                multiply(a, b, r, c);
                break;
            case 4:
                transpose(a, r, c);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}