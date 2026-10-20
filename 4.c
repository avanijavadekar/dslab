#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int regno;
    char name[10];
    struct student *next;
};

void create(struct student *head);
void display(struct student *head);
void removeStudent(struct student *head);
int count(struct student *head);
void bubbleSort(struct student *head);
void reverseList(struct student *head);

int main()
{
    struct student *head;
    int ch;

    head = (struct student*)malloc(sizeof(struct student));

    head->regno = 0;
    strcpy(head->name, "HEAD");
    head->next = NULL;

    while(1)
    {
        printf("\n\n1. Create");
        printf("\n2. Display");
        printf("\n3. Remove Student");
        printf("\n4. Bubble Sort");
        printf("\n5. Reverse List");
        printf("\n6. Count");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create(head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                removeStudent(head);
                break;

            case 4:
                bubbleSort(head);
                break;

            case 5:
                reverseList(head);
                break;

            case 6:
                printf("\nNumber of students = %d", count(head));
                break;

            case 7:
                exit(0);

            default:
                printf("\nWrong choice");
        }
    }

    return 0;
}

void create(struct student *head)
{
    struct student *newnode, *temp;

    newnode = (struct student*)malloc(sizeof(struct student));

    printf("\nEnter regno: ");
    scanf("%d", &newnode->regno);

    printf("Enter name: ");
    scanf("%9s", newnode->name);

    newnode->next = NULL;

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    printf("\nStudent added successfully.");
}

void display(struct student *head)
{
    struct student *temp;

    temp = head->next;

    if(temp == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nReg No\tName");

    while(temp != NULL)
    {
        printf("\n%d\t%s", temp->regno, temp->name);
        temp = temp->next;
    }
}

void removeStudent(struct student *head)
{
    struct student *temp, *del;
    int regno;

    printf("\nEnter registration number to remove: ");
    scanf("%d", &regno);

    temp = head;

    while(temp->next != NULL)
    {
        if(temp->next->regno == regno)
        {
            del = temp->next;
            temp->next = del->next;

            free(del);

            printf("\nStudent removed successfully.");
            return;
        }

        temp = temp->next;
    }

    printf("\nStudent with regno %d not found.", regno);
}

int count(struct student *head)
{
    int count;
    struct student *temp;

    count = 0;
    temp = head->next;

    if(temp == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        while(temp != NULL)
        {
            count = count + 1;
            temp = temp->next;
        }
    }

    return count;
}

void bubbleSort(struct student *head)
{
    struct student *prev, *curr1, *curr2;
    int swapped;

    if(head->next == NULL)
    {
        printf("\nList is empty");
        return;
    }

    do
    {
        swapped = 0;
        prev = head;
        curr1 = head->next;

        while(curr1->next != NULL)
        {
            curr2 = curr1->next;

            if(curr1->regno > curr2->regno)
            {
                curr1->next = curr2->next;
                curr2->next = curr1;
                prev->next = curr2;

                swapped = 1;
                prev = curr2;
            }
            else
            {
                prev = curr1;
                curr1 = curr1->next;
            }
        }

    } while(swapped);

    printf("\nList sorted successfully.");
}

void reverseList(struct student *head)
{
    struct student *prev, *current, *infuture;

    prev = NULL;
    current = head->next;

    while(current != NULL)
    {
        infuture = current->next;
        current->next = prev;
        prev = current;
        current = infuture;
    }

    head->next = prev;

    printf("\nList reversed successfully.");
}
