#include <stdio.h>
#include<stdlib.h>
#define size 3

struct Q
{
    int jobid;
    char title[20];
};

int front = -1;
int rear = -1;

int isfull(int rear)
{
    if (rear == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int isempty(int rear, int front)
{
    if (rear == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void AddQ(struct Q Q[])
{
    if (isfull(rear) == 0)
    {
        rear = rear + 1;

        printf("enter job id to be added: ");
        scanf("%d", &Q[rear].jobid);

        printf("enter title: ");
        scanf("%s", Q[rear].title);
    }
    else
    {
        printf("queue is full\n");
    }
}

void DelQ(struct Q Q[])
{
    if (isempty(rear, front) == 0)
    {
        front = front + 1;

        printf("Deleted job id: %d\n", Q[front].jobid);
        printf("Deleted title: %s\n", Q[front].title);
    }
    else
    {
        printf("queue is empty\n");
    }
}



int main()
{
    struct Q q[3];
    int choice;
    while(1)
    {
    printf("1.add: \n");
    printf("2.delete: \n ");
    printf("3.exit: \n");
    printf("enter choice: \n");
    scanf("%d", &choice);
   
    switch(choice)
    {
    case 1: AddQ(q);
    break;
   
    case 2: DelQ(q);
    break;
   
    case 3: exit(0);
    break;
    }
   }
   
   return 0;


   

   
}
