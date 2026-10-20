#include<stdio.h>
#include<stdlib.h>

struct Grocery
{
    int productID;
    char name[50];
    float price;
};

void accept(struct Grocery s[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Product: %d\n", i+1);
        printf("enter product ID: ");
        scanf("%d", &s[i].productID);
        printf("enter product name: ");
        scanf("%s", s[i].name);
        printf("enter price: ");
        scanf("%f", &s[i].price);
    }
}

void display(struct Grocery s[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Product: %d\n", i+1);
        printf("ProductID : %d\n", s[i].productID);
        printf("Name        : %s\n", s[i].name);
        printf("Price       : %.2f\n", s[i].price);
    }
}

void linearSearch(struct Grocery s[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].productID == key)
        {
            printf("\nProduct Found!\n");
            printf("Product ID : %d\n", s[i].productID);
            printf("Name        : %s\n", s[i].name);
            printf("Price       : %.2f\n", s[i].price);
            return;
        }
    }

    printf("\nProduct not found.\n");
}

int binarySearch(struct Grocery s[], int n, float elem)
{
    int l = 0, h = n - 1;

    while(l <= h)
    {
        int mid = (l + h) / 2;

        if(s[mid].price == elem)
        {
            printf("Product found at index %d\n", mid);
            return mid;
        }
        else if(elem > s[mid].price)
            l = mid + 1;
        else
            h = mid - 1;
    }

    printf("Product not found.\n");
    return -1;
}

void selection(struct Grocery s[], int n)
{
    int idxmin;
    float min;

    for(int i = 0; i < n - 1; i++)
    {
        min = s[i].price;
        idxmin = i;

        for(int j = i + 1; j < n; j++)
        {
            if(s[j].price < min)
            {
                min = s[j].price;
                idxmin = j;
            }
        }

        struct Grocery temp = s[i];
        s[i] = s[idxmin];
        s[idxmin] = temp;
    }
}

void insertion(struct Grocery s[], int n)
{
    for(int i = 1; i < n; i++)
    {
        struct Grocery temp = s[i];
        int j = i - 1;

        while(j >= 0 && s[j].price > temp.price)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = temp;
    }
}

void shell(struct Grocery s[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            struct Grocery temp = s[i];
            int j;

            for(j = i; j >= gap && s[j - gap].price > temp.price; j -= gap)
                s[j] = s[j - gap];

            s[j] = temp;
        }
    }
}

int main()
{
    int n, key, ch;
    float elem;

    printf("Enter the number of products: ");
    scanf("%d", &n);

    struct Grocery s[n];
    accept(s, n);

    while(1)
    {
        printf("\n1. Display\n");
        printf("2. Linear Search\n");
        printf("3. Selection Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Shell Sort\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                display(s, n);
                break;

            case 2:
                printf("Enter desired product ID: ");
                scanf("%d", &key);
                linearSearch(s, n, key);
                break;

            case 3:
                selection(s, n);
                printf("Sorted by selection sort:\n");
                display(s, n);
                break;

            case 4:
                insertion(s, n);
                printf("Sorted by insertion sort:\n");
                display(s, n);
                break;

            case 5:
                shell(s, n);
                printf("Sorted by shell sort:\n");
                display(s, n);
                break;

            case 6:
                printf("Enter price to search: ");
                scanf("%f", &elem);
                binarySearch(s, n, elem);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}