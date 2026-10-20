#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Job
{
    int jobid;
    char jobtitle[50];
};

struct Job queue[SIZE];
int front = 0, rear = -1, count = 0;

void enqueue()
{
    if (count == SIZE)
    {
        printf("Queue is full\n");
        return;
    }

    rear = (rear + 1) % SIZE;

    printf("Enter job ID: ");
    scanf("%d", &queue[rear].jobid);

    printf("Enter job title: ");
    scanf(" %49[^\n]", queue[rear].jobtitle);

    count++;
    printf("Print job added\n");
}

void dequeue()
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Processing job ID: %d\n", queue[front].jobid);
    printf("Job title: %s\n", queue[front].jobtitle);

    front = (front + 1) % SIZE;
    count--;
}

void display()
{
    if (count == 0)
    {
        printf("No pending print jobs\n");
        return;
    }

    printf("Pending print jobs:\n");

    for (int i = 0; i < count; i++)
    {
        int j = (front + i) % SIZE;
        printf("Job ID: %d, Job Title: %s\n",
               queue[j].jobid, queue[j].jobtitle);
    }
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1. Add print job\n");
        printf("2. Process print job\n");
        printf("3. Display pending jobs\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}