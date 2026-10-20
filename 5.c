#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *createNode(int c, int e)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;

    return newnode;
}

struct node *createPolynomial(struct node *head, int c, int e)
{
    struct node *temp, *newnode;
    newnode = createNode(c, e);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("0");
        return;
    }

    temp = head;

    do
    {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != head)
            printf(" + ");

        temp = temp->next;

    } while (temp != head);
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *result = NULL, *a, *b;
    int found;

    if (p1 == NULL)
        return p2;

    if (p2 == NULL)
        return p1;

    a = p1;

    do
    {
        b = p2;
        found = 0;

        do
        {
            if (a->exp == b->exp)
            {
                result = createPolynomial(result, a->coeff + b->coeff, a->exp);
                found = 1;
                break;
            }

            b = b->next;

        } while (b != p2);

        if (!found)
            result = createPolynomial(result, a->coeff, a->exp);

        a = a->next;

    } while (a != p1);

    b = p2;

    do
    {
        a = p1;
        found = 0;

        do
        {
            if (b->exp == a->exp)
            {
                found = 1;
                break;
            }

            a = a->next;

        } while (a != p1);

        if (!found)
            result = createPolynomial(result, b->coeff, b->exp);

        b = b->next;

    } while (b != p2);

    return result;
}

int evaluate(struct node *head, int x)
{
    struct node *temp;
    int sum = 0;

    if (head == NULL)
        return 0;

    temp = head;

    do
    {
        sum += temp->coeff * pow(x, temp->exp);
        temp = temp->next;

    } while (temp != head);

    return sum;
}

int main()
{
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    struct node *p3 = NULL;

    int n, c, e, i, x, ch;

    printf("Enter no. of terms in first polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coeff and expo: ");
        scanf("%d%d", &c, &e);
        p1 = createPolynomial(p1, c, e);
    }

    printf("Enter no. of terms in second polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coeff and expo: ");
        scanf("%d%d", &c, &e);
        p2 = createPolynomial(p2, c, e);
    }

    while (1)
    {
        printf("\n\n1. Display Polynomials");
        printf("\n2. Add Polynomials");
        printf("\n3. Evaluate First Polynomial");
        printf("\n4. Evaluate Second Polynomial");
        printf("\n5. Evaluate Sum");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("First polynomial: ");
                display(p1);

                printf("\nSecond polynomial: ");
                display(p2);
                break;

            case 2:
                p3 = add(p1, p2);
                printf("Sum: ");
                display(p3);
                break;

            case 3:
                printf("Enter value of x: ");
                scanf("%d", &x);
                printf("Value = %d", evaluate(p1, x));
                break;

            case 4:
                printf("Enter value of x: ");
                scanf("%d", &x);
                printf("Value = %d", evaluate(p2, x));
                break;

            case 5:
                p3 = add(p1, p2);
                printf("Enter value of x: ");
                scanf("%d", &x);
                printf("Value of sum = %d", evaluate(p3, x));
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}